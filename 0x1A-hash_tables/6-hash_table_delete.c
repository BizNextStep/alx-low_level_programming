#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * hash_table_print - Prints a hash table
 * @ht: Pointer to the hash table
 * @print_callback: Pointer to a function to print the key and value
 */
void hash_table_print(const hash_table_t *ht, void (*print_callback)
		(const char *key, const char *value))
{
	if (ht == NULL)
	{
		return;
	}

	for (unsigned int i = 0; i < ht->size; i++)
	{
	for (hash_node_t *node = ht->array[i]; node != NULL; node = node->next)
	{
		print_callback(node->key, node->value);
		printf(" ");
	}
	printf("\n");
	}
}
