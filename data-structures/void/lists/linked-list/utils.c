/*
 *utils.c
 *
 *Utilities for basic ll_node access
 *
 *Author: Saketh Kasibatla
 */
#include "linked_list.h"

void *_get_value(ll_node *n)
{
        return n->value;
}

void _set_value(ll_node *n, void *v)
{
        n->value = v;
}


ll_node *_get_next(ll_node *n)
{
        return n->next;
}

void _set_next(ll_node *n, ll_node *v)
{
        n->next = v;
}
