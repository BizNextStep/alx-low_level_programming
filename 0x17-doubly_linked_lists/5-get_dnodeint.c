##include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * get_dnodeint_at_index - Returns the nth node of a dlistint_t linked list
 * @param head: The head of the linked list
 * @index: The index of the node, starting from 0
 *
 * Return: The nth node of the linked list, or NULL if the node does not exist
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *current = head;

	for (unsigned int i = 0; i < index; i++)
	{
		if (current == NULL)
		{
			return (NULL);

		}
		current = current->next;
	}

	return (current);
}
