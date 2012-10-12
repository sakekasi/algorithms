/*
 *ndestructive.c
 *
 *Non-destructive accessors and mutators.
 *
 *Author: Saketh Kasibatla
 */

#include "linked-list.h"

linked_list *append(linked_list *l, int value)
{
    linked_list *copy = copy_list(l);

    _append(copy, value);

    return copy;
}

linked_list *prepend(linked_list *l, int value)
{
    linked_list *copy = copy_list(l);

    _prepend(copy, value);

    return copy;
}

linked_list *insert(linked_list *l, int index, int value)
{
    linked_list *copy = copy_list(l);

    _insert(copy, index, value);

    return copy;
}


linked_list *remove_first(linked_list *l)
{
    linked_list *copy = copy_list(l);

    _remove_first(copy);

    return copy;
}

linked_list *remove_last(linked_list *l)
{
    linked_list *copy = copy_list(l);

    _remove_last(copy);

    return copy;
}

linked_list *remove_index(linked_list *l, int index)
{
    linked_list *copy = copy_list(l);

    _remove(copy, index);

    return copy;
}


size_t size(linked_list *l)
{
    ll_node *first = first_node(l);
    size_t size = 0;

    while(first!=NULL){
        size++;
        first = _get_next(first);
    }

    return size;
}


int first(linked_list *l)
{
    return _get_value(first_node(l));
}

int last(linked_list *l)
{
    return _get_value(last_node(l));
}

int get(linked_list *l, int index)
{
    return _get_value(get_node(l,index));
}


int set_first(linked_list *l, int value)
{
    ll_node *first = first_node(l);
    int ret;

    ret = _get_value(first);
    _set_value(first, value);

    return ret;
}

int set_last(linked_list *l, int value)
{
    ll_node *last = last_node(l);
    int ret;

    ret = _get_value(last);
    _set_value(last, value);

    return ret;
}

int set(linked_list *l, int index, int value)
{
    ll_node *current = get_node(l, index);
    int ret;
    
    ret = _get_value(current);
    _set_value(current, value);

    return ret;
}


ll_node *first_node(linked_list *l)
{
    return *l;
}

ll_node *last_node(linked_list *l)
{
    ll_node *first = first_node(l);

    while(_get_next(first) != NULL){
        first = _get_next(first);
    }

    return first;
}

ll_node *get_node(linked_list *l, int index)
{
    ll_node *first = first_node(l);
    int i;
    
    for(i=0;i<index;i++){
        first = _get_next(first);
    }

    return first;
}
