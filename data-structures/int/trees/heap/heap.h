#ifndef HEAP_H
#define HEAP_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct{
    int **data;
    int last;
    int size;
}heap;

//////backend functions

////integer functions
int _level_size(int n);
int _size(int n);
int _level_of(int index);
int _last_level(int size);
int _in_last_level(int index, int size);
int _parent_index(int i);
int _left_child_index(int i);
int _right_child_index(int i);
int _num_levels(int n);

////utility functions
void _swap(void *i, void *j, size_t size);
int **_array(int num_levels);
int _empty(heap *h);
void _grow(heap *h);

//value functions
int _parent_value(heap *h,int index);
int _left_child_value(heap *h,int index);
int _right_child_value(heap *h,int index);
int _value(heap *h, int index);
int _greater_child_index(heap *h, int index);

//pointer functions
int *_greater_child_pointer(heap *h, int index);
int *_pointer(heap *h, int index);
int *_left_child_pointer(heap *h,int index);
int *_right_child_pointer(heap *h,int index);
int *_parent_pointer(heap *h, int index);
int _leaf(heap *h, int index);

//re-heapify functions
void _re_heapify_up(heap *h,int index);
void _re_heapify_down(heap *h,int index);


//////user functions

heap *new_heap(int num_levels);
heap *default_new_heap();
int max(heap *h);
int *root(heap *h);
int delete_max(heap *h);
void set(heap *h,int index, int num);
int get(heap *h,int index);
void insert(heap *h, int num);
heap *merge_heaps(heap *a,heap *b);
heap *heap_from_array(int *a,size_t size);
void insert_array(heap *h, int *a, size_t size);

#endif
