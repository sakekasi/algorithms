#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define STARTING_SIZE 256
#define PART_SIZE sizeof(int)/sizeof(char)

typedef int * hash_table;

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
int _key_part_hash(char *,size_t);

#endif
