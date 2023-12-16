#include "hash_tables.h"
#include <stdlib.h>
/**
 * key_index - calculates the index of a key.
 * @size: size of the array.
 *
 * @key: The key, string
 * Return: The index of key/value pair in the hash table
 */

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int index = hash_djb2((unsigned char *)key);

	return (index % size);
}
