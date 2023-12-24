#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>

/**
 * hash_table_get - retrieves a value associated with a key
 * @ht: the hash table to look into
 * @key: the key to look for
 *
 * Return: the value associated with the element,
 * or NULL if key couldn't be found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *current;

	if (ht == NULL || key == NULL)
	return (NULL);

	/* Get the index where the key should be stored */
	index = key_index((unsigned char *)key, ht->size);

	/* Traverse the linked list at the computed index */
	current = ht->array[index];
	while (current != NULL)
	{
	/* Check if the key matches */
	if (strcmp(current->key, key) == 0)
		return (current->value);

	/* Move to the next node in the linked list */
	current = current->next;
	}

	/* Key not found, return NULL */
	return (NULL);
}
