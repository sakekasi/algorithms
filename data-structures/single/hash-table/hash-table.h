#ifndef HASH_TABLE_H
#define HASH_TABLE_H

//TODO: thoroughly comment all c files.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define STARTING_SIZE 256
#define PART_SIZE sizeof(int)/sizeof(char)
#define CHAR_BINARY_PLACES 8
#define PPH_THRESHOLD 80
#define RESIZE_PERCENTAGE .30

typedef struct 
{
    char *key;
    int value;
}datum;

typedef struct {
    datum **storage;
    size_t size;
}hash_table;

/*
 *constructors/destructors
 */

//constructors
hash_table *_allocate_hash_table(size_t);
hash_table *new_hash_table();
datum *_new_datum();
datum **_new_storage(size_t);

//destructors
void delete(hash_table *);
void _delete_data(datum **, size_t);

/*
 *utils
 */

//hash functions
int _hash(hash_table *,int);
int _key_hash(char *);
int _key_part_hash(char *,size_t);
int _open_hash(int);

//hash table accessors
size_t _size(hash_table *);
datum **_storage(hash_table *);

//hash table mutators
void _set_size(hash_table *,size_t);
void _set_storage(hash_table *,datum **);

//datum accessors
char *_key(datum *);
int _value(datum *);

//datum mutators
void _set_key(datum *, char *);
int _set_value(datum *, int);

//miscellaneous
int _increment(int, int, int);

//signal node indicator
datum *_SIGNAL();


/*
 *accessors/mutators
 */

//create
void insert(hash_table *,char *, int);
void resize(hash_table *);

//modify
int *fetch(hash_table *,char *);
int *set(hash_table *,char *, int);

//remove
datum *rm(hash_table *,char *);


/*
 *properties
 */
int _pph_full(hash_table *);


#endif
