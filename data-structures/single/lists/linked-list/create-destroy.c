/*
 *create-destroy.c
 *
 *All constructors and destructors of linked list.
 *
 *Author: Saketh Kasibatla
 */

#include "linked-list.h"

ll_node *_new_ll_node()
{
    ll_node *n = (ll_node *) malloc(sizeof(ll_node));
    _set_value(n,0);
    _set_next(n,NULL);

    return n;
}

linked_list *new_linked_list()
{
    linked_list l=NULL;
    return &l;
}

linked_list *copy_list(linked_list *l)
{
    linked_list *new=new_linked_list();
    ll_node *current=first_node(l);

    while(current!=NULL){
        _append(new, _get_value(current));
        current = _get_next(current);
    }

    return new;
}

linked_list *array_to_list(int *array, size_t len)
{
    int i;
    linked_list *l=new_linked_list;
    
    for(i=0;i<len;i++){
        _append(l, array[i]);
    }

    return l;
    
}


void delete_list(linked_list *l)
{
    ll_node *a, *b;

    a=*l;
    b=a->next;
    
    while( (a!=NULL) && (b!=NULL) ){
        free(a);
        a=b->next;

        free(b);
        b=a->next;
    }

    if(a==NULL){
        free(b);
    }else{
        free(a);
    }
    
}
