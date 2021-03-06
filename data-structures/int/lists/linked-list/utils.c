/*
 *utils.c
 *
 *Node accessor and mutator utility functions
 *
 *Author: Saketh Kasibatla
 */

#include "linked-list.h"

int _get_value(ll_node *n)
{
    return n->value;
}

void _set_value(ll_node *n, int value)
{
    n->value = value;
}


ll_node *_get_next(ll_node *n)
{
    return n->next;
}

void _set_next(ll_node *n, ll_node *value)
{
    n->next = value;
}
