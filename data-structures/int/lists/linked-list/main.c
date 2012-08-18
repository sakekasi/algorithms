#include "linked-list.h"

int main(void)
{
    linked_list list=new_linked_list();
    int num,i,v;

    scanf("%d", &num);
    printf("\n");

    for(i=0;i<num;i++){
        scanf("%d", &v);
        ll_append(&list, v);
    }

    printf("\n");
    ll_print(list);

    return 0;
}
