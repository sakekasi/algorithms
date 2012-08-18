/*
  insertion-sort.c
  author: Saketh Kasibatla
*/
#include "sorting.h"


/*
  void insertion_sort(int [], size_t);
  
  input: unsorted array of integers with size num
  output: sorted array of integers with size num
*/
int *insertion_sort(int *array, size_t num){
  int *copy;
  size_t i,j;
    
  copy = (int *) calloc(num, sizeof(int));
  memcpy(copy, array, num*sizeof(int));
  
  for(i=1;i<num;i++){
    j=i;
    while( (copy[j-1] > copy[j]) && (j>0) ){
      swap(&(copy[j-1]), &(copy[j]));
      j--;
    }
  }
  
  return copy;
}
