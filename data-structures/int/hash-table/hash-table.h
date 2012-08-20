#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef int * hash_table;

/*
 *constructors/destructors
 */
hash_table *_allocate_hash_table(size_t);
hash_table *new_hash_table();

void delete(hash_table *);

#endif
