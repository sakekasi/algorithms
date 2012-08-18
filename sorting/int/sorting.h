#ifndef SORTING_H
#define SORTING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *bubble_sort(int *, size_t);
int *selection_sort(int *, size_t);
int *insertion_sort(int *, size_t);
int *merge_sort(int *, size_t);
int *quicksort(int *, size_t);
int *quicker_sort(int *, size_t);
int *heapsort(int *, size_t);


int *merge(int *, int *, size_t, size_t);
void swap(int *,int *);

#endif
