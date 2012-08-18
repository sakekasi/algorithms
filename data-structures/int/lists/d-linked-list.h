#ifndef D_LINKED_LIST_H
#define D_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int value;
  Dll_node *next;
  Dll_node *prev;
}Dll_node;

typedef struct{
  Dll_node *first;
  Dll_node *last;
}d_linked_list;

#endif
