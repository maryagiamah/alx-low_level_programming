#include "hash_tables.h"
#include <stdlib.h>
/**
 * hash_table_create - creates a hash table.
 * @size: size of the array.
 *
 * Return: A pointer to the newly created hash table.
 */

hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *table = NULL;
	unsigned long int i = 0;

	/* create new hash table */
	table = (hash_table_t *) malloc(sizeof(hash_table_t));

	if (!table)
		return (NULL);
	table->size = size;
	table->array = (hash_node_t **) malloc(table->size * sizeof(hash_node_t *));
	if (!table->array)
	{
		free(table);
		return (NULL);
	}
	for (i = 0; i < table->size; i++)
		table->array[i] = NULL;
	return (table);
}
