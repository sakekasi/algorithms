/*
 * bubble-sort.c
 * author: Saketh Kasibatla
 */
#include "sorting.h"

/*
 * void bubble_sort(int [], size_t);
 *
 * input: unsorted array of integers with size num
 * output: sorted array of integers with size num
 */
int *bubble_sort(int *array, size_t num){
  int *copy;
  size_t i,j;
  
  copy = calloc(num, sizeof(int));
  memcpy(copy, array, num*sizeof(int));

  for(i=num;i>0;i--){
    for(j=0;j<i;j++){
      if(copy[j] > copy[j+1]){
	swap(&(copy[j]), &(copy[j+1]));
      }
    }
  }
  
  return copy;
}

