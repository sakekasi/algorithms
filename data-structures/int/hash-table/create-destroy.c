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
        
        hash_table *h = (hash_table *) malloc(sizeof(hash_table));
        
        datum **data = _new_storage(s);
        
        h->storage = data;
        h->size = s;
        
        return h;
}

hash_table *new_hash_table()
{
        return _allocate_hash_table(STARTING_SIZE);
}

datum *_new_datum()
{
        return (datum *) malloc(sizeof(datum));
}

datum **_new_storage(size_t s)
{
        datum **data = (datum **) calloc(s, sizeof(datum *));
        int i;
        
        for(i=0;i<s;i++){
                data[i] = NULL;
        }
        
        return data;
}


void delete(hash_table *h)
{
        _delete_data(h->storage, h->size);
        free(h);
}

void _delete_data(datum **d, size_t s)
{
        int i;
        for(i=0;i<s;i++){
                free(d[i]);
        }
        free(d);
}
