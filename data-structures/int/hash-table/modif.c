/*
 *modif.c
 *
 *Modifiers of the hash table;
 *
 *Author: Saketh Kasibatla
 */

#include "hash-table.h"

void insert(hash_table *h, char *key, int value)
{
        datum *d = _new_datum();
        
        _set_key(d, key);
        _set_value(d, value);
        
        if(_pph_full(h) > PPH_THRESHOLD){
                resize(h);
        }
        
        int hash = _hash(h, _key_hash(key));
        int open_hash = _open_hash(_key_hash(key));
        datum **data = _storage(h);
        size_t size = _size(h);
        
        while((data[hash] != NULL) && (data[hash] != _SIGNAL())){
                hash = _increment(hash, open_hash, size);
        }
        
        data[hash] = d;
}

void resize(hash_table *h)
{
        datum **data = _storage(h), **new_data = _new_storage((int) (1+RESIZE_PERCENTAGE)*_size(h));
        size_t old_size = _size(h);
        int i;
        
        _set_size(h, 2*_size(h));
        _set_storage(h, new_data);
        
        for(i=0;i<old_size;i++){
                if(data[i] != NULL){
                        insert(h, _key(data[i]), _value(data[i]));
                }
        }
        
        _delete_data(data, old_size);
}


int *fetch(hash_table *h, char *key)
{
        int hash = _hash(h, _key_hash(key));
        int open_hash = _open_hash(_key_hash(key));
        size_t size = _size(h);
        datum **data = _storage(h);
        int *ret = (int *) malloc(sizeof(int));
        
        while( data[hash] != NULL ){
                if( strcmp( _key(data[hash]) , key ) == 0 ){
                        if( data[hash] == _SIGNAL() ){
                                hash = _increment(hash, open_hash, size);
                        } else {
                                *ret = _value(data[hash]);
                                return ret;
                        }
                } else {
                        hash = _increment(hash, open_hash, size);
                }
        }
        
        return NULL;
}

int *set(hash_table *h, char *key, int value)
{
        int hash = _hash(h, _key_hash(key));
        int open_hash = _open_hash(_key_hash(key));
        size_t size = _size(h);
        datum **data = _storage(h);
        int *ret= (int *)malloc(sizeof(int));
        
        
        while( data[hash] != NULL ){
                if( strcmp( _key(data[hash]) , key ) == 0 ){
                        if( data[hash] == _SIGNAL() ){
                                hash = _increment(hash, open_hash, size);
                        } else {
                                *ret = _value(data[hash]);
                                _set_value(data[hash], value);
                                return ret;
                        }
                } else {
                        hash = _increment(hash, open_hash, size);
                }
        }
        
        return NULL;
}


datum *rm(hash_table *h, char *key)
{
        int hash = _hash(h, _key_hash(key));
        int open_hash = _open_hash(_key_hash(key));
        size_t size = _size(h);
        datum **data = _storage(h);
        datum *ret;
        
        while( data[hash] != NULL ){
                if( strcmp( _key(data[hash]) , key ) == 0 ){
                        if( data[hash] == _SIGNAL() ){
                                hash = _increment(hash, open_hash, size);
                        } else {
                                ret = data[hash];
                                data[hash] = _SIGNAL();
                                return ret;
                        }
                } else {
                        hash = _increment(hash, open_hash, size);
                }
        }
        
        return NULL;
}
