#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ll_node
{
    int value;
    struct ll_node *next;
}

typedef ll_node * linked_list;

/*
 *create/destroy
 */
ll_node *_new_ll_node();
linked_list *new_linked_list();
linked_list *copy_list(linked_list *);
linked_list *array_to_list(int *, size_t);

void delete_list(linked_list *);


/*
 *accessors/mutators destructive
 */
void _append(linked_list *, int);
void _prepend(linked_list *, int);
void _insert(linked_list *, int, int);

int _remove_first(linked_list *);
int _remove_last(linked_list *);
int _remove(linked_list *, int);


/*
 *accessors/mutators non-destructive
 */
linked_list *append(linked_list *, int);
linked_list *prepend(linked_list *, int);
linked_list *insert(linked_list *, int, int);

linked_list *remove_first(linked_list *);
linked_list *remove_last(linked_list *);
linked_list *remove(linked_list *, int);

size_t size(linked_list *);

int first(linked_list *);
int last(linked_list *);
int get(linked_list *, int);

int set_first(linked_list *, int);
int set_last(linked_list *, int);
int set(linked_list *, int, int);

ll_node *first_node(linked_list *);
ll_node *last_node(linked_list *);
ll_node *get_node(linked_list *, int);


/*
 *utilities
 */
int _get_value(ll_node *);
void _set_value(ll_node *, int);

ll_node *_get_next(ll_node *);
void _set_next(ll_node *, ll_node *);

#endif
