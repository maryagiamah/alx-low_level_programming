#include "hash_tables.h"
#include <stdlib.h>
/**
 * key_index - calculates the index of a key.
 * @size: size of the array.
 *
 * @key: The key, string
 * Return: A pointer to the newly created hash table.
 */

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
        unsigned long int index = hash_djb2((unsigned char *)key);
        return index % size;
}
