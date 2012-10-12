#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct ll_node{
	void *value;
	struct ll_node *next;
}ll_node;

typedef ll_node *linked_list;

#define STARTING_INDEX 0


/*
 * create/destroy
 */

ll_node * _new_ll_node();
linked_list * new_linked_list();
linked_list * copy_linked_list(linked_list *);
linked_list * array_to_list(void **, size_t);

void delete_list(linked_list *);


/*
 *accessors/mutators destructive
 */
void _append(linked_list **, void *);
void _prepend(linked_list **, void *);
void _insert(linked_list *, int, void *);

ll_node *_remove_first(linked_list **);
ll_node *_remove_last(linked_list *);
ll_node *_remove(linked_list *, int);


/*
 *accessors/mutators non-destructive
 */
linked_list *append(linked_list *, void *);
linked_list *prepend(linked_list *, void *);
linked_list *insert(linked_list *, int, void *);

linked_list *remove_first(linked_list *);
linked_list *remove_last(linked_list *);
linked_list *rm(linked_list *, int);

size_t size(linked_list *);

void *first(linked_list *);
void *last(linked_list *);
void *get(linked_list *, int);

void *set_first(linked_list *, void *);
void *set_last(linked_list *, void *);
void *set(linked_list *, int, void *);

ll_node *first_node(linked_list *);
ll_node *last_node(linked_list *);
ll_node *get_node(linked_list *, int);


/*
 *utilities
 */
void *_get_value(ll_node *);
void _set_value(ll_node *, void *);

ll_node *_get_next(ll_node *);
void _set_next(ll_node *, ll_node *);

#endif
