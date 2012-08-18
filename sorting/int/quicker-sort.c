/*
  quicker-sort.c
  author: Saketh Kasibatla
*/
#include "sorting.h"

#define SMALL_SIZE 4

/*
  void quicker_sort(int [], size_t);
  
  input: unsorted array of integers with size num
  output: sorted array of integers with size num
*/
int *quicker_sort(int *array, size_t num){
  int i, l, r, left_num, right_num, pivot, *copy, *left, *right, *sorted;
  
  if(num<=1){
    return array;
  }else if(num<=SMALL_SIZE){
    copy = (int *) calloc(num, sizeof(int));
    memcpy(copy, array, num*sizeof(int));
    insertion_sort(copy, num);
    return copy;
  }else {
  
    pivot = array[num-1];
    
    left = calloc(num-1, sizeof(int));
    right = calloc(num-1, sizeof(int));
    
    left_num=0;
    right_num=0;
    
    for(i=0 ; i<num-1 ; i++){
      if(array[i] < pivot){
	left[left_num]=array[i];
	left_num++;
      } else {
	right[right_num]=array[i];
	right_num++;
      }
    }
    
    left = quicker_sort(left, left_num);
    right = quicker_sort(right, right_num);
    
    sorted = (int *) calloc(num, sizeof(int));
    for(i=0, l=0;l<left_num;i++, l++){
      sorted[i] = left[l];
    }
    sorted[i] = pivot;
    for(++i, r=0; r<right_num;i++,r++){
      sorted[i] = right[r];
    }
    
    free(left);
    free(right);
    
    return sorted;
  }
}
  

