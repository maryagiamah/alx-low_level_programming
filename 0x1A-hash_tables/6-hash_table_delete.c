#include "hash_tables.h"
#include <stdlib.h>
/**
 *  hash_table_delete  - deletes a hash table.
 * @ht: double pointer to a linked list
 *
 * Return: Void.
 *
 */
void hash_table_delete(hash_table_t *ht)
{
        usigned long int i;
        hash_table_t *current
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
