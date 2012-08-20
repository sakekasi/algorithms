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

        
