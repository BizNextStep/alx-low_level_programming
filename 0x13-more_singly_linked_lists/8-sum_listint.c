#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * sum_listint - returns the sum of all the data (n) of a listint_t linked list
 * @head: pointer to the head of the list
 *
 * Return: the sum of all the data (n), or 0 if the list is empty
 */
int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *current;

	if (head == NULL)
	return (0);

	current = head;
	while (current != NULL)
	{
		sum += current->n;
		current = current->next;
	}

	return (sum);
}
