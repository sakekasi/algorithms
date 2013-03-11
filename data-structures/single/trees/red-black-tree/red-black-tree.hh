#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

#include <cstddef>
#include <sstream>
#include <string>

template<typename T>
class RedBlackTree{
 public:
  RedBlackTree();
  virtual ~RedBlackTree();

  void insert(T);
  void remove(T);
  bool member(T);
  std::string traverse();

  enum Color {RED, BLACK};

 private:
  struct RBNode{
    RBNode(RBNode*, T, Color);
    RBNode(RBNode*, T);
    ~RBNode();

    T datum;
    Color color;
    RBNode *parent;
    RBNode *left, *right;
  };

  RBNode* _root;

  void delete_helper(RBNode*);

  void refactor(RBNode*); //add a find root function.
  RBNode* find(T);
  void delete_refactor(RBNode*); // add a find root function.
  void traverse_helper(RBNode*, std::ostringstream&);
  void re_root(RBNode*);

  RBNode* inorder_predecessor(RBNode*);
  RBNode* inorder_successor(RBNode*);

  void swap_values(RBNode*, RBNode*);
  void replace(RBNode*, RBNode*);
  
  void rotate_left(RBNode*);
  void rotate_right(RBNode*);

  bool root_p(RBNode*);
  bool leaf_p(RBNode*);
  
  RBNode* grandparent(RBNode*);
  RBNode* uncle(RBNode*);
  RBNode* sibling(RBNode*);
};

template<typename T>
void RedBlackTree<T>::swap_values(RBNode *a, RBNode *b){
  T temp = a->datum;
  a->datum = b->datum;
  b->datum = a->datum;
}

template<typename T>
void RedBlackTree<T>::replace(RBNode *a, RBNode *b){
  a->datum = b->datum;
  a->left = b->left;
  a->right = b->right;
  a->color = b->color;
}

template<typename T>
void RedBlackTree<T>::rotate_left(RBNode *n){
  RBNode* mid = n->right;

  mid->parent = n->parent;
  if(n->parent)
    if( n == n->parent->left )
      n->parent->left = mid;
    else
      n->parent->right = mid;


  n->right = mid->left;
  mid->left = n;

  n->parent = mid;
}

template<typename T>
void RedBlackTree<T>::rotate_right(RBNode *n){
  RBNode* mid = n->left;
  
  mid->parent = n->parent;
  if(n->parent)
    if( n == n->parent->left )
      n->parent->left = mid;
    else
      n->parent->right = mid;
  

  n->left = mid->right;
  mid->right = n;

  n->parent = mid;
}

template<typename T>
bool RedBlackTree<T>::root_p(RBNode *n){
  return n->parent == NULL;
}

template<typename T>
bool RedBlackTree<T>::leaf_p(RBNode *n){
  return (n->left == NULL) && (n->right == NULL);
}

template<typename T>
typename RedBlackTree<T>::RBNode* RedBlackTree<T>::grandparent(RBNode *n){
  if( n!=NULL && (n->parent != NULL) )
    return n->parent->parent;
  else
    return NULL;
}

template<typename T>
typename RedBlackTree<T>::RBNode* RedBlackTree<T>::uncle(RBNode *n){
  RBNode *grand = grandparent(n);
  if( grand==NULL )
    return NULL;
  if( n->parent == grand->left )
    return grand->right;
  else
    return grand->left;
}

template<typename T>
typename RedBlackTree<T>::RBNode* RedBlackTree<T>::sibling(RBNode *n){
  if( n == NULL || n->parent == NULL )
    return NULL;
  else if( n == n->parent->left )
    return n->parent->right;
  else
    return n->parent->left;
}


template<typename T>
RedBlackTree<T>::RedBlackTree()
    :_root(NULL)
{}

template<typename T>
RedBlackTree<T>::~RedBlackTree(){
  delete_helper(_root);
}

template<typename T>
void RedBlackTree<T>::insert(T i){
  RBNode *n = NULL;

  //standard insert
  if( _root == NULL ){
    _root = new RBNode(NULL, i);
    n = _root;
  } else {
    RBNode* current = _root;
    while(!leaf_p(current))
      if(current->datum == i)
        return;
      else if(i > current->datum)
        if(current->right)
          current = current->right;
        else
          break;
      else
        if(current->left)
          current = current->left;
        else
          break;

    if(i > current->datum){
      current->right = new RBNode(current, i);
      n = current->right;
    } else if(i < current->datum) {
      current->left = new RBNode(current, i);
      n = current->left;
    }
  }

  refactor(n);
}

template<typename T>
void RedBlackTree<T>::remove(T i){
  RBNode *n = find(i);
  
  if(n){
    RBNode *p = inorder_predecessor(n), *s = inorder_successor(n);
    RBNode *m = NULL;
    if( p && leaf_p(p) ){
      //choose the predecessor only if it is a leaf.
      swap_values(n, p);
      m = p;
    } else if( s ){
      swap_values(n, s);
      m = s;
    } else {
      delete n;
      return;
    }

    if( leaf_p(m) )
      if( m->color == RED )
        //red leaves can be deleted without violating any of the rules.
        delete m;
      else{
        delete_refactor(m);
        delete m;
        if(m==_root)
          _root = NULL;
      }
    else{
      //a simple recoloring can bring this case into the rules.
      if( m->left )
        replace( m, m->left );
      else
        replace( m, m->right );
      m->color = BLACK;
    }
  }
}

template<typename T>
bool RedBlackTree<T>::member(T i){
  RBNode* current = _root;
  while(current != NULL)
    if(current->datum == i)
      return true;
    else
      if(i > current->datum)
        current = current->right;
      else
        current = current->left;
  return false;
}

template<typename T>
std::string RedBlackTree<T>::traverse(){
  std::ostringstream ret;
  traverse_helper(_root, ret);
  return ret.str();
}

template<typename T>
void RedBlackTree<T>::delete_helper(RBNode* n){
  if(n == NULL)
    return;
  else{
    delete_helper(n->left);
    delete_helper(n->right);
    delete n;
  }
}

template<typename T>
void RedBlackTree<T>::refactor(RBNode *n){

  if(n != NULL)
    if(root_p(n))
      n->color = BLACK;
    else if ( n->parent->color == BLACK )
      return;
    else if(n->parent->color == RED){
      if(uncle(n) && uncle(n)->color == RED){
        //this pushes the color conflicts further up so that they can be
        //resolved by a rotation.
        n->parent->color = BLACK;
        uncle(n)->color = BLACK;
        grandparent(n)->color = RED;
        refactor(grandparent(n));
      } else if( !uncle(n) || uncle(n)->color == BLACK) {
        //at this point, we can resolve coloring issues by rotating and
        //recoloring.
        if( (n == n->parent->right) && (n->parent == grandparent(n)->left) ){
          //if n is on a zig zag, make it straight.
          rotate_left(n->parent);
          n = n->left;
        } else if ((n == n->parent->left) &&
                   (n->parent == grandparent(n)->right)) {
          //if n is on a zig zag, make it straight.
          rotate_right(n->parent);
          n = n->right;        
        }

        //now that we have straight lines to the grandparent, rotate at
        //the grandparent and recolor to fix a color conflict.
        if (n == n->parent->left) {
          rotate_right(grandparent(n));
          n->parent->color = BLACK;
          sibling(n)->color = RED;
        } else {
          rotate_left(grandparent(n));
          n->parent->color = BLACK;
          sibling(n)->color = RED;
        }
      }
      
    }

  re_root(_root);
}


template<typename T>
typename RedBlackTree<T>::RBNode* RedBlackTree<T>::find(T i){
  RBNode* current = _root;

  while(current!=NULL)
    if(current->datum == i)
      return current;
    else
      if(i > current->datum)
        current = current->right;
      else
        current = current->left;

  return NULL;
}

template<typename T>
void RedBlackTree<T>::delete_refactor(RBNode *n){
  if( !root_p(n) ){ //if the last node left is the root, delete it.
    if( sibling(n)->color == RED ){
      n->parent->color = RED;
      sibling(n)->color = BLACK;
      if( n == n->parent->left )
        rotate_left(n->parent);
      else
        rotate_right(n->parent);
    }
    if( n->parent->color == BLACK &&
        sibling(n)->color == BLACK &&
        sibling(n)->left->color == BLACK &&
        sibling(n)->right->color == BLACK){
      sibling(n)->color = RED;
      delete_refactor(n->parent);
    } else if( n->parent->color == RED &&
               sibling(n)->color == BLACK &&               
               sibling(n)->left->color == BLACK &&
               sibling(n)->right->color == BLACK){
      sibling(n)->color = RED;
      n->parent->color = BLACK;
    } else {
      if( n == n->parent->left &&
          sibling(n)->right->color == BLACK &&
          sibling(n)->left->color == RED){
        sibling(n)->color = RED;
        rotate_right(sibling(n));
      } else if ( n == n->parent->right &&
                  sibling(n)->right->color == RED &&
                  sibling(n)->left->color == BLACK) {
        sibling(n)->color = RED;
        rotate_left(sibling(n));
      }

      sibling(n)->color = n->parent->color;
      n->parent->color = BLACK;        
        
      if( n == n->parent->left){
        sibling(n)->right->color = BLACK;
        rotate_left(n->parent);
      } else {
        sibling(n)->left->color = BLACK;
        rotate_right(n->parent);
      }
    }
  }

  re_root(_root);
}

template<typename T>
void RedBlackTree<T>::traverse_helper(RBNode *n, std::ostringstream& oss){
  if(n == NULL)
    return;
  else{
    traverse_helper(n->left, oss);
    oss << n->datum << ' ';
    traverse_helper(n->right, oss);
  }
}

template<typename T>
void RedBlackTree<T>::re_root(RBNode *n){
  RBNode* current = n;
  while(!root_p(current)){
    current = current->parent;
  }
  _root = current;
}

template<typename T>
typename RedBlackTree<T>::RBNode* RedBlackTree<T>::inorder_predecessor(RBNode *n){
  RBNode* current = n->left;
  if(current){
    while(current->right != NULL){
      current = current->right;
    }
    return current;
  }
  return NULL;
}

template<typename T>
typename RedBlackTree<T>::RBNode* RedBlackTree<T>::inorder_successor(RBNode *n){
  RBNode* current = n->right;
  if(current){
    while(current->left != NULL){
      current = current->left;
    }
    return current;
  }
  return NULL;
}


//////////////////////////////////////////////////////////////////////
template<typename T>
RedBlackTree<T>::RBNode::RBNode(RBNode *parent, T datum, Color c)
    :datum(datum), color(c), parent(parent), left(NULL), right(NULL)
{}

template<typename T>
RedBlackTree<T>::RBNode::RBNode(RBNode *parent, T datum)
    :datum(datum), color(RED), parent(parent), left(NULL), right(NULL)
{}

template<typename T>
RedBlackTree<T>::RBNode::~RBNode(){
  if( parent )
    if( this == parent->left )
      parent->left = NULL;
    else
      parent->right = NULL;
}

#endif
