/*
 * d-linked-list.c
 * author: Saketh Kasibatla
 */

size_t size(d_linked_list l)
{
    size_t size=0;
    Dll_node *ptr = l.first;

    while(ptr!=NULL){
        size++;
        ptr=ptr->next;
    }

    return size;
}

d_linked_list new_list()
{
    d_linked_list l;

    l.first=NULL;
    l.last=NULL;

    return l;
}



