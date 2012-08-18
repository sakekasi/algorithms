/*
  selection-sort.c
  author: Saketh Kasibatla
*/
#include "sorting.h"

/*
  void selection_sort(int [], size_t);
  
  input: unsorted array of integers with size num
  output: sorted array of integers with size num
*/
int *selection_sort(int *array, size_t num){
  int *copy;
  size_t i,j,small;
  
  copy = (int *) calloc(num, sizeof(int));
  memcpy(copy, array, num*sizeof(int));
  
  for(i=0;i<num;i++){
    small=i;
    for(j=i;j<num;j++){
      if(copy[j] < copy[small]){
	small=j;
      }
    }
    swap(&(copy[i]), &(copy[small]));
  }
  
  return copy;
}

