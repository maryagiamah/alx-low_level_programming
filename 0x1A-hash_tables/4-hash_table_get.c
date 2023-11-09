#include "hash_tables.h"
#include <string.h>

/**
 * hash_table_get - Retrieves a value associated with a key.
 * @ht: double pointer to a linked list
 * @key: key, string
 *
 * Return: Returns the value associated with the element,
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
        hash_node_t *current;
        unsigned long int index = key_index((const unsigned char *)key, ht->size);
        if (*ht)
               current = ht->array[index];

        while (current)
        {
                        if (strcmp(current->key, key) == 0)
                        {
                                
                                return key->value;
                        }

                        current = current->next;
        }
        return NULL;
}
