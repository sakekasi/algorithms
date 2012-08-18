#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

#define NIL -1

//struct definition of a node
typedef struct ll_node{
  int value;
  struct ll_node *next;
} ll_node;

typedef ll_node * linked_list;

/*
 *constructor functions
 */

ll_node *new_ll_node();
linked_list new_linked_list();

linked_list array_to_linked_list(int *, size_t);
linked_list ll_copy(linked_list);

/*
 *list modifier functions
 */

//destructive
void ll_prepend(linked_list *, int);
void ll_append(linked_list *, int);
void ll_insert(linked_list, int, int);
void ll_remove(linked_list, int);

//non-destructive
linked_list ll_prepend_nd(linked_list, int);
linked_list ll_append_nd(linked_list, int);
linked_list ll_insert_nd(linked_list, int, int);
linked_list ll_remove_nd(linked_list, int);

/*
 *value  accessor/modifier functions
 */

//accessor
int ll_get_value(linked_list, int);
void ll_print(linked_list);
void ll_sprint(linked_list, char *);
linked_list ll_last(linked_list);
linked_list ll_get(linked_list, int);
int ll_find(linked_list, int);


//modifier
int ll_set_value(linked_list, int, int);

/*
 *properties functions
 */

int ll_empty(linked_list);
size_t ll_size(linked_list);

//destructor
void ll_delete(linked_list);

#endif
