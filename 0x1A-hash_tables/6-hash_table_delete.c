#include "hash_tables.h"
#include <stdio.h>
/**
 *  hash_table_print  - deletes a hash table.
 * @ht: double pointer to a linked list
 *
 * Return: Void.
 *
 */
void hash_table_print(const hash_table_t *ht)
{
        int i;
        
        for (i = 0; i < ht->size; i++)
        {
                current = ht->array[i];
                while (current)
                {
                        free(current->key);
                        free(current->value);
                        free(current);
                        current = current->next;
                }
        }
        if (ht)
        {
                free(ht->array);
                free(ht);
        }
}
