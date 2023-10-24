#include “lists.h”
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * delete_nodeint_at_index - deletes the node at index index of a listint_t linked list
 * @head: pointer to the head of the list
 * @index: index of the node that should be deleted
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int i;
	listint_t *current, *temp;

	if (head == NULL || *head == NULL)
	return (-1);

	if (index == 0)
	{
	temp = *head;
	*head = (*head)->next;
	free(temp);
	return (1);
	}

	current = *head;
	for (i = 0; i < index - 1; i++)
	{
		if (current == NULL)
		return (-1);
		current = current->next;
	}

	if (current == NULL || current->next == NULL)
	return (-1);

	temp = current->next;
	current->next = temp->next;
	free(temp);

	return (1);
}
