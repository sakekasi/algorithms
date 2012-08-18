/*
 * swap.c
 * author: Saketh Kasibatla
 */
#include "sorting.h"

void swap(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}
