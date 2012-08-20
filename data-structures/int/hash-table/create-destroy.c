/*
 *create-destroy.c
 *
 *Contains constructors and destructors for hash table
 *
 *Author: Saketh Kasibatla
 */

#include "hash-table.h"

hash_table *_allocate_hash_table(size_t s)
{
    hash_table h = (hash_table) calloc(s, sizeof(int));
    return &h;
}

hash_table *new_hash_table()
{
    return _allocate_hash_table(STARTING_SIZE);
}


void delete(hash_table *h)
{
    free(*h);
    h=NULL;
}
