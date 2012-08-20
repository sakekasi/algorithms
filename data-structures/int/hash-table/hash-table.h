#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define STARTING_SIZE 256
#define PART_SIZE sizeof(int)/sizeof(char)
#define CHAR_BINARY_PLACES 8

typedef struct {
    int *storage;
    size_t size;
}hash_table;

/*
 *constructors/destructors
 */
hash_table *_allocate_hash_table(size_t);
hash_table *new_hash_table();

void delete(hash_table *);

/*
 *utils
 */
int _hash(int);
int _key_hash(char *);
int _open_hash(int);

/*
 *accessors/mutators
 */
void insert(hash_table *,char *, int);

/*
 *properties
 */
int _pph_full(hash_table *);


#endif
