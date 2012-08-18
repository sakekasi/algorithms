/*
 * linked list constructor and destructor functions
 * author: Saketh Kasibatla
 */
#include "linked-list.h"


/*
 * constructor functions
 */

//creates a new ll_node
ll_node *new_ll_node()
{

    ll_node *new=(ll_node *) malloc(sizeof(ll_node));

    new->value=0;
    new->next=NULL;
    
    return new;
}

//creates an empty list
linked_list new_linked_list()
{
    return NULL;
}

//converts an int array to a linked list
linked_list array_to_linked_list(int *array, size_t num)
{
  int i;
  linked_list l;

  l=new_linked_list();
  
  for(i=num-1 ; i>=0 ; i--)
      ll_prepend(&l, array[i]);
  
  return l;
}


//copies a linked list
linked_list ll_copy(linked_list l){
  linked_list new = new_linked_list();
  
  while(l!=NULL){
    ll_append(&new, l->value);
    l=l->next;
  }
  
  return new;
}


/*
 *destructor functions
 */

//frees all memory taken up by list l
void ll_delete(linked_list l){
  linked_list a=l->next;
  
  while((a!=NULL) && (l != NULL)){
    free(l);
    l=a->next;
    free(a);
    a=l->next;
  }
}

