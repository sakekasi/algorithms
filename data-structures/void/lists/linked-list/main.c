//main.c

#include <stdio.h>
#include "linked_list.h"

int main()
{
        linked_list *l = new_linked_list();
        double d = 6.8, e=9.0, f=3.14;
        
        l = append(l, &d);
        l = append(l, &e);
        l = append(l, &f);

        int i=0;
        for(;i<size(l);i++){
                printf("%d\n", *((double *) get(l, i)));
        }

}

        
