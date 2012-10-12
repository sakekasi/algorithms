/*
 *destructive.c
 *
 *destructive modifiers for linked_list
 *
 *Author: Saketh Kasibatla
 */
#include "linked_list.h"

//insertion functions

void _append(linked_list **l, void *v)
{
        ll_node *last = last_node(*l);
        ll_node *app = _new_ll_node();

        _set_value(app, v);

        if(*l == NULL)
                **l = app;
        else
                _set_next(last, app);
}

void _prepend(linked_list **l, void *v)
{
        ll_node *first = first_node(*l);
        ll_node *app = _new_ll_node();

        _set_value(app, v);
        _set_next(app, first);

        **l = app;
}


void _insert(linked_list *l, int index, void *v)
{
        ll_node *node = get_node(l, index);
        ll_node *prev = get_node(l, index-1);
        ll_node *app = _new_ll_node();

        _set_value(app, v);
        _set_next(prev, app);
        _set_next(app, node);
}



//removal functions

//these functions return nodes instead of values so that
//the user has the option to free the node.

ll_node *_remove_first(linked_list **l)
{
        ll_node *first = first_node(*l);

        **l = _get_next(first);

        return first;
}

ll_node *_remove_last(linked_list *l)
{
        ll_node *last = last_node(l);
        ll_node *prev = get_node(l, size(l)-2);

        _set_next(prev, NULL);

        return last;
}

ll_node *_remove(linked_list *l, int index)
{
        ll_node *prev = get_node(l, index-1);
        ll_node *ind = _get_next(prev);

        _set_next(prev, _get_next(ind));

        return ind;
}
