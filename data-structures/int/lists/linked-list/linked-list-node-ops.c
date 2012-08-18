/*
 *linked list node operations
 *author: Saketh Kasibatla
 */ 
#include "linked-list.h"


/*
 *list modifier functions
 */



//destructive functions (modify the actual list)
//-------------------------------------------------

//prepends value v to list l. note the pointer to linked list as
//the first argument as opposed to a linked list.
void ll_prepend(linked_list *l, int v){
    ll_node *n=new_ll_node();
  
    n->value=v;
    n->next=*l;
  
    *l=n;
}

//dont forget to check that last is null
//ll_appends value v to list l
void ll_append(linked_list *l, int v){
    ll_node *n=new_ll_node();
    linked_list last = ll_last(*l);
  
    n->value=v;
    n->next=NULL;
    if(last==NULL)
        *l=n;
    else
        last->next = n;
}

//inserts value v at index i in list l
void ll_insert(linked_list l, int i, int v){
    ll_node *n=new_ll_node();
    linked_list index = ll_get(l,i), next;
    
    next=index->next;
  
    n->value = v;
    n->next = next;
    index->next = n;
}

//deletes node at index i in list l
void ll_remove(linked_list l, int i){
    linked_list n=ll_get(l, i), last=ll_get(l,i-1);
    last->next = n->next;
    n->next = NULL;
    ll_delete(n);
}


//non-destructive functions (return a new modified list)
//-------------------------------------------------


//ll_prepends value v to list l non-destructively
linked_list ll_prepend_nd(linked_list l, int v){
    linked_list copy = ll_copy(l);
    ll_prepend(&copy,v);
    return copy;
    
}

//ll_appends value v to list l non-destructively
linked_list ll_append_nd(linked_list l, int v){
    linked_list copy = ll_copy(l);
    ll_append(&copy, v);
    return copy;
}

//ll_inserts value v at index i in list l non-destructively
linked_list ll_insert_nd(linked_list l, int i, int v){
    linked_list copy = ll_copy(l);
    ll_insert(copy,i,v);
    return copy;
}

//ll_deletes node at index i in list l non-destructively
linked_list ll_remove_nd(linked_list l, int i){
    linked_list copy = ll_copy(l);
    ll_remove(copy, i);
    return copy;
}



//checks if the list is empty or not
int ll_empty(linked_list l){
  if(l==NULL)
    return 1;
  return 0;
}
