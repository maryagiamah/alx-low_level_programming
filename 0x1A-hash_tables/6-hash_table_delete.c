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
	unsigned long int i;
	hash_node_t *current, *next;

	if (!ht || !ht->array)
		return;
	for (i = 0; i < ht->size; i++)
	{
		current = ht->array[i];
		if (current)
		{
			while (current)
			{
				next = current->next;
				if (current->key)
					free(current->key);
				if (current->value)
					free(current->value);
				if (current)
					free(current);
				current = next;
			}
			ht->array[i] = NULL;
		}
	}
	free(ht->array);
	free(ht);
}
