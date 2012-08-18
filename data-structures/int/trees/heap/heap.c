/*
 *heap.c
 *author:Saketh Kasibatla
 *
 *reorganize and compile this
 */
#include "heap.h"

/*
 *integer operations
 *
 *these are operations on indices and the like.
 *generally should not be called by users.
 *
 */

int _level_size(int n)
{
    return (int) pow(2.0,(double)n);
}

int _size(int n)
{
    int i,num=0;

    for(i=0;i<n;i++){
        num+=_level_size(i);
    }

    return num;
}

int _level_of(int index)
{
    return floor(log2((double)index));
}

int _last_level(int size)
{
    return _num_levels(size)-1;
}


int _in_last_level(int index, int size)
{
    int last_level = _last_level(size);
    int ind_level = _level_of(index);
    return last_level == ind_level;
}


int _parent_index(int i)
{
    if((i%2)==0){
        return (i-2)/2;
    }else{
        return (i-1)/2;
    }
}

int _left_child_index(int i)
{
    return (2*i)+1;
}

int _right_child_index(int i)
{
    return (2*i)+2;
}

int _num_levels(int n)
{
    int l=0,c=n;

    while(c>0){
        c-=_level_size(l);
        l++;
    }

    return l;
}


/*
 *utility functions
 *
 *these deal with pointers and actual heaps to make the code more readable
 *most names indicate pretty well what the function does.
 *
 */

void _swap(void *i, void *j, size_t size)
{
    char *temp=malloc(size);
    memcpy(temp, i,size);
    memcpy(i,j,size);
    memcpy(j,temp,size);
}

int **_array(int num_levels)
{
    int **a,size=_size(num_levels),i;
    a=(int **) calloc(size,sizeof(int *));

    for(i=0;i<size;i++){
        a[i]=NULL;
    }
    return a;
}

int _empty(heap *h)
{
    return h->last == 0;
}

void _grow(heap *h)
{
    if(h->last == h->size){
        int levels = _num_levels(h->size);
        int **n_data = _array(2*levels), **o_data = h->data;

        memcpy(n_data, o_data, (h->size)*sizeof(int *));
        h->data = n_data;

        h->size = _size(2*levels);
        free(o_data);
    }
}
        




//value functions return values py going all the way to the end
//of the pointer path.

//these functions have inherent error checking to ensure that
//when you ask for the parent of the root node, you get the root node or
//that you get the proper values for cases where you have a leaf or
//a node with just a left child so as to not get actual errors.
int _parent_value(heap *h,int index)
{
    if(index==0){ //root node has no parents
        return _value(h,0);
    }else{
        return _value(h,_parent_index(index));
    }
}

int _left_child_value(heap *h,int index)
{
    int *l_child = _pointer(h,_left_child_index(index));
    if(l_child==NULL){
        return _value(h,index);
    }else{
        return _value(h,_left_child_index(index));
    }
}
    
int _right_child_value(heap *h,int index)
{
    int *r_child = _pointer(h,_right_child_index(index));
    if(r_child==NULL){
        return _value(h,index);
    }else{
        return _value(h,_right_child_index(index));
    }
}


int _value(heap *h, int index)
{
    int **data = h->data;
    return *data[index];
}

//needs error checking
int _greater_child_index(heap *h, int index)
{
    int *l_child=_left_child_pointer(h,index);
    int *r_child=_right_child_pointer(h,index);

    if(l_child==NULL || r_child==NULL){
        if(l_child==NULL && r_child==NULL){
            return index;
        }else{
            return _left_child_index(index);
        }
    }else{
        return (*l_child > *r_child)? _left_child_index(index)\
            : _right_child_index(index);
    }
}


//these are pointer functions and as such, return pointers.

int *_greater_child_pointer(heap *h, int index)
{
    int *l_child=_left_child_pointer(h,index);
    int *r_child=_right_child_pointer(h,index);

    if(l_child==NULL || r_child==NULL){
        if(l_child==NULL && r_child==NULL){
            return NULL;
        }else{
            return l_child;
        }
    }else{
        return (*l_child > *r_child)? l_child : r_child;
    }
}

int *_pointer(heap *h, int index)
{
    int **data = h->data;
    if( data[index] == NULL){
        data[index] = (int *) malloc(sizeof(int));
    }
    return data[index];
}

int *_left_child_pointer(heap *h,int index)
{
    return _pointer(h,_left_child_index(index));
}

int *_right_child_pointer(heap *h,int index)
{
    return _pointer(h,_right_child_index(index));
}


int *_parent_pointer(heap *h, int index)
{
    if(index==0){
        return _pointer(h,0);
    }else{
        return _pointer(h,_parent_index(index));
    }
}

int _leaf(heap *h, int index)
{
    if(_in_last_level(index, h->size)){
        return 1;
    }else if(_greater_child_pointer == NULL){
        return 1;
    }
    return 0;
}

//re-heapify up and down are used in insert and delete

void _re_heapify_up(heap *h,int index)
{
    if( _value(h,index) > _parent_value(h,index) ){
        _swap( _pointer(h,index) , _parent_pointer(h,index), sizeof(int) );
        _re_heapify_up(h, _parent_index(index));
    }
}

void _re_heapify_down(heap *h,int index)
{
    if( _leaf(h,index) ){
        return;
    } else if( (_left_child_value(h,index) > _value(h,index)) || \
               (_right_child_value(h,index) > _value(h,index)) ){
        _swap( _pointer(h,index) , _greater_child_pointer(h,index),\
               sizeof(int) );
        _re_heapify_down(h, _greater_child_index(h,index));
    }
}


/*
 *public functions
 *
 *these are made to be used by the user.
 *indices are referred to with child index functions.
 *for example, the first right node is the right child of root.
 *
 */

heap *new_heap(int num_levels)
{
    heap *h=(heap *) malloc(sizeof(heap));
    h->data = _array(num_levels);
    h->last = 0;
    h->size = _size(num_levels);

    return h;
}

heap *default_new_heap()
{
    return new_heap(4);
}

int max(heap *h)
{
    return _value(h,0);
}

int *root(heap *h)
{
    return _pointer(h,0);
}

int delete_max(heap *h)
{
    int m=max(h);

    (h->last)--;
    _swap( root(h), _pointer(h,h->last), sizeof(int) );
    free(_pointer(h,h->last));
    _re_heapify_down(h,0);

    return m;
}

void set(heap *h,int index, int num)
{
    int *p = _pointer(h,index);
    *p=num;

        /* try re-heapifying downward. if it works downward,
         * the upward re-heapify operation will immediately
         * return. otherwise, it will re-heapify up as required.
         */
    _re_heapify_down(h,index);
    _re_heapify_up(h,index);
}

int get(heap *h,int index)
{
    return _value(h,index);
}

void insert(heap *h, int num)
{
    if(h->last == h->size){
        _grow(h);
    }
    int *last = _pointer(h,h->last);
    *last=num;
    _re_heapify_up(h,(h->last)++);
}

heap *merge_heap(heap *a,heap *b)
{
    heap *new = default_new_heap();
    while(!_empty(a)){
        insert(new, delete_max(a));
    }
    while(!_empty(b)){
        insert(new, delete_max(b));
    }
    return new;
}

heap *heap_from_array(int *a,size_t size)
{
    heap *new = default_new_heap();
    int i;
    
    for(i=0;i<size;i++){
        insert(new,a[i]);
    }

    return new;
}

void insert_array(heap *h, int *a, size_t size)
{
    int i;
    for(i=0;i<size;i++){
        insert(h,a[i]);
    }
}
