/*
 *main.c
 *
 *test of hash table.
 *
 *Author: Saketh Kasibatla
 */

#include "hash-table.h"

int main(void)
{
        hash_table *table = new_hash_table();
        insert(table, "Saketh Kasibatla", 9);
        printf("%d\n", *fetch(table, "Saketh Kasibatla"));

        return 0;
}
