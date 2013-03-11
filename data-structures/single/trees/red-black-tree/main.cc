#include <iostream>
#include "red-black-tree.hh"
using namespace std;

int main(void){
  RedBlackTree<int>* tree = new RedBlackTree<int>();
  tree->insert(10);
  tree->insert(85);
  tree->insert(15);
  tree->insert(70);
  tree->insert(20);
  tree->insert(60);
  tree->insert(30);
  tree->insert(50);
  tree->insert(65);
  tree->insert(80);
  tree->insert(90);
  tree->insert(40);
  tree->insert(50);
  tree->insert(55);  

  cout << tree->member(11) << ' ' <<
      tree->member(85) << ' ' <<
      tree->member(55)<< endl;

  cout << tree->traverse() << endl;
  

  tree->remove(30);
  tree->remove(55);

  cout << tree->traverse() << endl;    


  cout << tree->member(11) << ' ' <<
      tree->member(85) << ' ' <<
      tree->member(55)<< endl;
}
