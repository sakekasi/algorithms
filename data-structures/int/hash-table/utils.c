/*
 *utils.c
 *
 *Utility functions for hash table
 *
 *Author: Saketh Kasibatla
 */

#include "hash-table.h"

int _key_part_hash(char *str, size_t s)
{
    int ret=0, i;
    char temp;

    for(i=0; i<size;i++){
        temp=str[i];
        num <<= CHAR_BINARY_PLACES;
        num |= temp;
    }

    return num;
}

int _key_hash(char *str)
{
    int size = strlen(str);
    int num_parts, rem, p, i, hash=0;

    num_parts = size / PART_SIZE;
    rem = size % PART_SIZE;
    num_parts += (rem == 0)? 0 : 1;

    for(p=1, i=0;p<num_parts;p++, i+=PART_SIZE){
        hash += _key_part_hash(&str[i], PART_SIZE);
    }

    hash += _key_part_hash(&str[i], rem);

    return hash;
}

int _hash(hash_table *h,int i)
{
    return floor(abs(_size(h) * sin((double) i)));
}

int _open_hash(int hash)
{
    return hash % 31 + 1;
}

int _size(hash_table *h)
{
    return h->size;
}

/*
 *properties that it could be useful to compute for testing
 *
 *parts per hundred full (percent full * 100)
 *----------------------------------------------------
 *used to determine whether or not to resize the table
 *
 *key collisions per hash computation
 *-----------------------------------
 *used to determine the quality of hash function
 *
 *average relocations
 *-------------------
 *used to determine good parts per hundred to resize at
 *
 */

    

