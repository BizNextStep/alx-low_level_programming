#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * hash_table_set - adds or updates an element to the hash table
 * @ht: pointer to the hash table
 * @key: the key. Cannot be an empty string
 * @value: the value associated with the key. Must be duplicated.
 *	Value can be an empty string
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int hash_index;
	hash_node_t *new_node, *current;

	if (ht == NULL || key == NULL || value == NULL)
		return (0);

	hash_index = key_index((const unsigned char *)key, ht->size);
	current = ht->array[hash_index];

	while (current != NULL)
	{
		if (strcmp(current->key, key) == 0)
		{
			free(current->value);
			current->value = strdup(value);
			return (1);
		}
		current = current->next;
	}

	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
		return (0);

	new_node->key = strdup(key);
	new_node->value = strdup(value);
	if (new_node->key == NULL || new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node->value);
		free(new_node);
		return (0);
	}

	new_node->next = ht->array[hash_index];
	ht->array[hash_index] = new_node;

	return (1);
}
