#include "hash_tables.h"
#include <stdio.h>
/**
 * hash_table_print  - prints a hash table.
 * @ht: double pointer to a linked list
 *
 * Return:Print the key/value in a dict structure
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i, has_printed = 0;
	hash_node_t *current;

	if (!ht)
		return;

	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		current = ht->array[i];
		if (has_printed && i < ht->size - 1 && ht->array[i])
		{
			printf(", ");
		}
		while (current)
		{
			printf("'%s': '%s'", current->key, current->value);
			if (current->next)
				printf(", ");
			current = current->next;
			has_printed++;
		}

	}
	printf("}\n");
}
