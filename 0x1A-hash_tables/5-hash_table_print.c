#include "hash_tables.h"
#include <string.h>
#include <stdio.h>
/**
 *  hash_table_print  - prints a hash table.
 * @ht: double pointer to a linked list
 *
 * Return: void. Print the key/value in the order that they appear in the array of hash table.
 */
void hash_table_print(const hash_table_t *ht)
{
    int i;
    hash_node_t *current;

    if (!ht)
    {
        printf("{}\n");
    }

    printf("{");
    for (i = 0; i < ht->size; i++)
    {
        current = ht->array[i];
        while (current)
        {
            if (current->next == NULL)
                printf("'%s':'%s'", current->key, current->value);
            else
                printf("'%s':'%s', ", current->key, current->value);

            current = current->next;
        }
    }
    if (ht)
        printf("}\n");
}
