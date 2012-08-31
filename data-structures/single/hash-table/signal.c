/*
 *signal.c
 *
 *signal definitions
 *
 *Author: Saketh Kasibatla
 */

#include "hash-table.h"

static datum *SIGNAL = NULL;

datum * _SIGNAL()
{
        if(SIGNAL == NULL)
                SIGNAL = (datum *) malloc(sizeof(datum));

        return SIGNAL;
}
