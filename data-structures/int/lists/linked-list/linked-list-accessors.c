/*
 *accessor functions for linked list
 *author:Saketh Kasibatla
 */

#include "linked-list.h"

//gets the value of list l at index i
int ll_get_value(linked_list l, int i){
  int j;
  linked_list copy;
  
  copy = l;
  
  for(j=0 ; j<i ; j++){
    copy=copy->next;
  }
  
  return copy->value;
}

//sets the value of list l at index i to v
int ll_set_value(linked_list l, int i, int v){
  int j,w;
  linked_list copy;
  
  copy=l;
  
  for(j=0 ; j<i ; j++){
    copy=copy->next;
  }

  w=copy->value;
  copy->value = v;
  
  return w;
}

//gets a pointer to the node at index i in list l
linked_list ll_get(linked_list l, int i){
  int j;
  linked_list copy=l;
  
  for(j=0;j<i;j++){
    copy=copy->next;
  }
  
  return copy;
}

//ll_gets a pointer to the last node of list l
linked_list ll_last(linked_list l){
    return ll_get(l, ll_size(l)-1);
}

//prints list l to the screen
void ll_print(linked_list l){
  linked_list copy;
  
  copy=l;
  
  printf("[");
  while((copy->next) != NULL){
    printf("%d, ", copy->value);
    copy = copy->next;
  }
  printf("%d]\n", copy->value);
}

//prints list l to a string
void ll_sprint(linked_list l, char *str){
  linked_list copy;

  copy=l;
  
  sprintf(str, "[");
  while((copy->next) != NULL){
    sprintf(str, "%d, ", copy->value);
    copy = copy->next;
  }
  sprintf(str, "%d]\n", copy->value);
}  

//finds the first instance of int v in list l. returns -1 if not found
int ll_find(linked_list l, int v){
  int i=0;
  linked_list copy=l;
  
  while(copy != NULL){
    if((copy->value)==v){
      return i;
    }
    i++;
  }
  
  return NIL;
}


/*
 *property functions
 */

//returns the number of elements in list l
size_t ll_size(linked_list l){
  size_t size=0;
  linked_list copy=l;
  
  while(copy!= NULL){
    copy=copy->next;
    size++;
  }
  
  return size;
}

