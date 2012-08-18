/*
  merge-sort.c
  author: Saketh Kasibatla
*/
#include "sorting.h"

/*
  void merge_sort(int [], size_t);
  
  input: unsorted array of integers with size num
  output: sorted array of integers with size num

  this function works recursively in tandem with merge to split then
  reassemble the array in a sorted manner.
*/
int *merge_sort(int *array, size_t num){
  int i, j, m, *left, *right;
  size_t left_num, right_num;
    
  if(num==1){
    return array;
  } else {
    
    m=num/2;

    left_num=m;
    right_num=num-m;

    left = (int *) calloc(left_num, sizeof(int));
    right = (int *) calloc(left_num, sizeof(int));
  
    for(i=0, j=0 ; i<m ; i++, j++){
      left[j] = array[i];
    }
  
    for(j=0 ; i<num ; i++, j++){
      right[j] = array[i];
    }
    
    left = merge_sort(left, left_num);
    right = merge_sort(right, right_num);
    
    return merge(left, right, left_num, right_num);
  }
}

/*
  int *merge(int *, int *, size_t, size_t);
  
  input: two lists to be merged and their sizes
  output: one merged and sorted list.
  
  this function is used by merge sort to combine functions after 
  splitting them.
*/
int *merge(int *left, int *right, size_t left_num, size_t right_num){
  int i, l, r, *merged;
  size_t merged_size;

  merged_size = left_num + right_num;
  merged = (int *) calloc(merged_size, sizeof(int));

  for(i=0, l=0, r=0 ; i<merged_size ; i++){
    
    if( r==right_num ){
      merged[i] = left[l];
      l++;
    } else if( l==left_num ){
      merged[i] = right[r];
      r++;
    } else if(left[l] < right[r]){
      merged[i] = left[l];
      l++;
    } else {
      merged[i] = right[r];
      r++;
    }
  }

  return merged;
}
  
  
