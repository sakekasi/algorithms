/*
 *main.c
 *
 *tests heapsort
 *
 */
#include "sorting.h"
#include "heap.h"

int *get_array(size_t);


int main(void)
{
    size_t num,i;

    scanf("%d", &num);
    int *array = get_array(num);
    array = heapsort(array,num);

    printf("[");
    for(i=0;i<(num-1);i++){
        printf("%d,", array[i]);
    }
    printf("%d]\n", array[i]);

    return 0;
}

int *get_array(size_t num)
{
    size_t i;
    int *a=(int *) calloc(num, sizeof(int));
    
    for(i=0;i<num;i++){
        scanf("%d", &a[i]);
    }

    return a;
}
