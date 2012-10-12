/*
 *create-destroy.c
 *
 *contins constructors and destructors for
 *linked_list and ll_node.
 *
 *Author: Saketh Kasibatla
 */
#include "linked_list.h"

//create

ll_node * _new_ll_node()
{
        ll_node *n = (ll_node *) malloc(sizeof(ll_node));
        
        n->value = NULL;
        n->next = NULL;

        return n;
}

linked_list * new_linked_list()
{
        return NULL;
}


linked_list * copy_linked_list(linked_list *l)
{
        linked_list *n = new_linked_list();
        int i;

        for(i=0; i<size(l); i++){
                _append(&n, get(l, i));
        }

        return l;
}

linked_list * array_to_list(void **array, size_t size)
{
        linked_list *l = new_linked_list();
        int i;

        for(i=0; i<size; i++){
                _append(&l, array[i]);
        }

        return l;
}






//destroy

void delete_list(linked_list *l)
{
        ll_node *a = first_node(l);
        ll_node *b = get_node(l, STARTING_INDEX+1);

        while((_get_next(a) != NULL) && (_get_next(b) != NULL)){
                free(a);
                a = _get_next(b);
                
                free(b);
                b = _get_next(a);
        }
}
