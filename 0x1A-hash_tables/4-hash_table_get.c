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
	unsigned long int index = 0;

	if (!ht || !ht->array || !key)
		return (NULL);
	index = key_index((const unsigned char *)key, ht->size);
	

	while (ht->array[index])
	{
		if (strcmp(ht->array[index]->key, key) == 0)
			return (ht->array[index]->value);
		ht->array[index] = ht->array[index]->next;
	}
	return (NULL);
}
