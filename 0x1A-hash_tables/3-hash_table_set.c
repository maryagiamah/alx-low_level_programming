#include "hash_tables.h"
#include <stdlib.h>
/**
 * hash_table_create - creates a hash table.
 * @size: size of the array.
 *
 * Return: A pointer to the newly created hash table.
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
        if (!key || !value)
                return 0;
        index = key_index(key,ht->size);
        hash_node_t *new = (hash_node_t*) malloc(sizeof(hash_node_t));
        if (!new)
                return 0;
        new->key = (const char *) malloc(strlen(key) + 1);
        new->value = (const char *) malloc(strlen(value) + 1);
        if (!new->key || !new->value)
                return 0;
        strcpy(new->key, key);
        strcpy(new->value, value);
        hash_node_t *current = ht->array[index];
        if (current == NULL)
        {
                /* KEY DOES NOT EXIST */
                ht->array[index] = new;
        }
        else
        {
                if(strcmp(current->key, key) == 0)
                {
                        strcpy(ht->array[index]->value, value)
                }
                else
                {
                        
                }
        }
}
