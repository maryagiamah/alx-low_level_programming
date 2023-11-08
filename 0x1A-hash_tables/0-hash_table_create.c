/**
 * hash_table_create - creates a hash table.
 * @size: size of the array.
 *
 * Return: A pointer to the newly created hash table.
 */
hash_table_t *hash_table_create(unsigned long int size)
{
        /* create new hash table */
        hash_table_t* table = (hash_table_t*) malloc(sizeof(hash_table_t));
        table->size = size;
        table->array = (hash_node_t**) malloc(table->size * sizeof(hash_node_t*));
        return table;
}