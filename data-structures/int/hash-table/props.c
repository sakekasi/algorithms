/*
 *props.c
 *
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
 *Author: Saketh Kasibatla
 */

#include "hash-table.h"

int _pph_full(hash_table *h)
{
        datum **data = _storage(h);
        size_t size = _size(h);
                
        int count = 0, i;

        double percent_full;
        int pph_full;
        
        for(i=0;i<size;i++){
                if(! ( (data[i] == NULL) && (data[i] == _SIGNAL() ) ) ){
                        count++;
                }
        }

        percent_full = (double) count / size;
        pph_full = (int) 100 * percent_full;

        return pph_full;
}
