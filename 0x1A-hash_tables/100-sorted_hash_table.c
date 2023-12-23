#include "hash_tables.h"
/**
 * shash_table_create - creates hash table
 * @size: size of the array of nodes
 *
 * Return: Table oe Null.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *table = calloc(1, sizeof(shash_table_t));

	if (!table)
		return (NULL);
	table->shead = NULL;
	table->stail = NULL;
	table->size = size;
	table->array = calloc(size, sizeof(shash_node_t *));
	if (!table->array)
	{
		free(table);
		return (NULL);
	}
	return (table);
}

/**
 * new_node - adds a node into a sorted linked list
 * @head: double pointer to a linked list
 * @key: value that was hashed
 * @value: value mapped to hashed key
 *
 * Return: pointer to the new node
 */
shash_node_t *new_node(shash_node_t **head, const char *key, const char *value)
{
	shash_node_t *new = (shash_node_t *)calloc(1, sizeof(shash_node_t));

	if (!new)
		return (NULL);

	new->key = strdup(key);
	new->value = strdup(value);

	if (!new->key)
	{
		free(new->value);
		free(new);
		return (NULL);
	}
	if (!new->value)
	{
		free(new->key);
		free(new);
	}
	new->next = *head;
	*head = new;
	return (new);
}
/**
 * sort_node - add new node to the sorted list
 * @ht: hash table
 * @new:  new node to add
 *
 * Return: Void.
 */
void sort_node(shash_table_t *ht, shash_node_t *new)
{
	shash_node_t *current = ht->shead;

	if (!ht->shead)
	{
		ht->stail = new;
		ht->shead = new;
		return;
	}
	else if (ht->shead && strcmp(ht->shead->key, new->key) > 0)
	{
		new->snext = current;
		new->sprev = current->sprev;
		current->sprev = new;
		ht->shead = new;
		return;
	}

	while (current->snext && strcmp(current->snext->key, new->key) < 0)
		current = current->snext;
	new->snext = current->snext;
	new->sprev = current;
	if (current->snext)
	{
		current->snext->sprev = new;
	}
	else
	{
		ht->stail = new;
	}
	current->snext = new;
}

/**
 * shash_table_set - adds a new key-value to the hash table
 * @ht: hash table
 * @key: key of the key-value to be stored
 * @value: value of the key-value to be stored
 *
 * Return: 0 on failure , 1 on Success
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index = 0;
	shash_node_t *new = NULL, *current = NULL;

	if (!ht || !ht->array || !key || !value || !ht->size)
		return (0);
	index = key_index((const unsigned char *)key, ht->size);
	current = ht->array[index];
	while (current)
	{
		if (strcmp(current->key, key) == 0)
		{
			if (current->value)
				free(current->value);
			current->value = strdup(value);
			return (current->value ? 1 : 0);
		}
		current = current->next;
	}
	new = new_node(&(ht->array[index]), key, value);

	if (!new)
		return (0);
	sort_node(ht, new);
	return (1);
}

/**
 * shash_table_get - Gets the value of a key
 * @ht: hash table
 * @key: key of key-value
 *
 * Return: NULL or value of key
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *current = NULL;

	if (!ht || !ht->array || !ht->shead)
		return (NULL);
	current = ht->shead;
	while (current)
	{
		if (strcmp(current->key, key) == 0)
			return (current->value);
		current = current->snext;
	}
	return (NULL);
}

/**
 * shash_table_print - prints hash table in asc sorted order
 * @ht: hash table
 *
 * Return: Void.
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *current = NULL;

	if (!ht || !ht->array || !ht->shead)
		return;
	current = ht->shead;
	printf("{");
	while (current)
	{
		printf("'%s': '%s'", current->key, current->value);
		if (current->snext)
			printf(", ");
		current = current->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - prints the hash table in reverse order
 * @ht: hash table
 *
 * Return: Void
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *current = NULL;

	if (!ht || !ht->array || !ht->stail)
		return;
	current = ht->stail;
	printf("{");
	while (current)
	{
		printf("'%s': '%s'", current->key, current->value);
		if (current->sprev)
			printf(", ");
		current = current->sprev;
	}
	 printf("}\n");
}

/**
 * shash_table_delete - deletes a hash table
 * @ht: hash table
 *
 * Return: Void.
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *current = NULL, *next = NULL;

	if (!ht)
		return;
	current = ht->shead;
	while (current)
	{
		next = current->snext;
		if (current->key)
			free(current->key);
		if (current->value)
			free(current->value);
		free(current);
		current = next;
	}
	free(ht->array);
	free(ht);
}
