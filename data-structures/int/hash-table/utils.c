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
        int num=0;
        
        for(i=0; i<s;i++){
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


size_t _size(hash_table *h)
{
        return h->size;
}

datum **_storage(hash_table *h)
{
        return h->storage;
}


void _set_size(hash_table *h, size_t s)
{
        h->size = s;
}

void _set_storage(hash_table *h, datum **data)
{
        h->storage = data;
}


char *_key(datum *d)
{
        return d->key;
}

int _value(datum *d)
{
        return d->value;
}


void _set_key(datum *d, char *k)
{
        d->key = k;
}

int _set_value(datum *d, int v)
{
        int ret = d->value;
        
        d->value = v;
        
        return ret;
}

int _increment(int hash, int open, int size)
{
        if(hash + open < size){
                return hash + open;
        } else {
                return open - (size - hash);
        }
        
}

