/*
 *destructive.c
 *
 *all destructive operations used in the list
 *
 *Author: Saketh Kasibatla
 */
#include "linked-list.h"

void _append(linked_list *l, int value)
{
    ll_node *new = _new_ll_node(), *last = last_node(l);
    
    _set_value(new, value);
    _set_next(last, new);
}

void _prepend(linked_list *l, int value)
{
    ll_node *new = _new_ll_node(), *first = first_node(l);

    _set_value(new, value);
    _set_next(new, first);

    *l = new;
}

void _insert(linked_list *l, int index, int value)
{
    ll_node *new = _new_ll_node(), *current = get_node(l, index-1);
    ll_node *next = _get_next(current);

    _set_value(new, value);
    _set_next(current, new);
    _set_next(new, next);
}


int _remove_first(linked_list *l)
{
    ll_node *first = first_node(l), *second = _get_next(first);
    int ret;

    *l=second;

    ret = _get_value(first);
    free(first);

    return ret;
}

void _remove_last(linked_list *l)
{
    ll_node *penultimate = _get_node(l, size(l)-1);
    ll_node *last = _get_next(penultimate);
    int ret;
    
    _set_next(penultimate, NULL);

    ret = _get_value(last);
    free(last);

    return ret;
}

void _remove(linked_list *l, int index)
{
    ll_node *before = _get_node(l, index-1);
    ll_node *current = _get_next(before);
    ll_node *after = _get_next(current);
    int ret;

    _set_next(before, after);

    ret = _get_value(current);
    free(current);

    return ret;
}
