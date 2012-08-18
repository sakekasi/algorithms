/*
 *heapsort.c
 *
 *author: Saketh Kasibatla
 */
#include "sorting.h"
#include "heap.h"


int *heapsort(int *array, size_t num)
{
    heap *h = heap_from_array(array,num);
    int *ret = (int *) calloc(num, sizeof(int)), i;

    for(i=0;i<num;i++){
        ret[i]= delete_max(h);
    }

    return ret;
}
