/*
 *ndestructive.c
 *
 *non destructive modifiers for linked_list
 *
 *Author: Saketh Kasibatla
 */
#include "linked_list.h"

//insert

linked_list *append(linked_list *l, void *v)
{
        linked_list *n = copy_linked_list(l);
        _append(&n, v);
        return n;
}

linked_list *prepend(linked_list *l, void *v)
{
        linked_list *n = copy_linked_list(l);
        _prepend(&n, v);
        return n;
}

linked_list *insert(linked_list *l, int index, void *v)
{
        linked_list *n = copy_linked_list(l);
        _insert(n, index, v);
        return n;
}


//remove

linked_list *remove_first(linked_list *l)
{
        linked_list *n = copy_linked_list(l);
        _remove_first(&n);
        return n;
}

linked_list *remove_last(linked_list *l)
{
        linked_list *n = copy_linked_list(l);
        _remove_last(l);
        return n;
}

linked_list *rm(linked_list *l, int index)
{
        linked_list *n = copy_linked_list(l);
        _remove(n, index);
        return n;
}


//accessors

size_t size(linked_list *l)
{
        size_t size=0;
        ll_node *current = *l;

        while(current->next != NULL){
                current = current->next;
                size++;
        }
        size++;

        return size;
}


//node value accessors

void *first(linked_list *l)
{
        return _get_value(first_node(l));
}

void *last(linked_list *l)
{
        return _get_value(last_node(l));
}

void *get(linked_list *l, int index)
{
        return _get_value(get_node(l, index));
}



//node value mutators

void *set_first(linked_list *l, void *v)
{
        void *ret = first(l);
        _set_value(first_node(l), v);
        return ret;
}

void *set_last(linked_list *l, void *v)
{
        void *ret = last(l);
        _set_value(last_node(l), v);
        return ret;
}

void *set(linked_list *l, int index, void *v)
{
        void *ret = get(l, index);
        _set_value(get_node(l, index), v);
        return ret;
}



//node accessors

ll_node *get_node(linked_list *l, int index)
{
        int i;
        ll_node *current = first_node(l);

        for(i=0; i<index; i++){
                current = current->next;
        }

        return current;
}

ll_node *last_node(linked_list *l)
{
        return get_node(l, size(l)-1);
}

ll_node *first_node(linked_list *l)
{
        return get_node(l, STARTING_INDEX);
}

