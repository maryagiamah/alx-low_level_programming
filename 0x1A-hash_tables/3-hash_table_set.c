#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>

/**
 * add_node - adds a node to the beginning of a linked list
 * @head: double pointer to a linked list
 * @new: pointer to the new node
 *
 * Return: pointer to the new node
 */
hash_node_t *add_node(hash_node_t **head, const char *key, const char *value)
{
        hash_node_t *new = (hash_node_t *)malloc(sizeof(hash_node_t));
        
        if (!new)
                return NULL;

        new->key = strdup(key);   
        new->value = strdup(value); 
        
        if (!new->key || !new->value)
        {   
                free(new);
                return NULL;
        }

        new->next = *head;
        *head = new;
        return new;
}

/**
 * hash_table_set - adds an element to the hash table.
 * @ht: pointer to the hash table.
 * @key: key to add.
 * @value: value to associate with the key.
 *
 * Return: 1 if it succeeded, 0 otherwise.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
        unsigned long int index;
        if (!key || !value)
                return 0;
        if(!ht)
             ht = hash_table_create(1024); /* create a hash table is not present */  
        index = key_index((const unsigned char *)key, ht->size);
        
        if (ht->array[index] == NULL)
        {
                ht->array[index] = add_node(&(ht->array[index]), key, value);
        }
        else
        {
                hash_node_t *current = ht->array[index];

                while (current)
                {
                        if (strcmp(current->key, key) == 0)
                        {
                                free(current->value); /* Free the old value */
                                current->value = strdup(value); /* Update value */
                                return 1;
                        }

                        if (current->next == NULL)
                        {
                                add_node(&(current->next), key, value);
                                return 1;
                        }

                        current = current->next;
                }
        }

        return 1;
}
