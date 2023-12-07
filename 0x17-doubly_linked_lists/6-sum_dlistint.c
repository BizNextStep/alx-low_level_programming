#include "lists.h"

/**
 * sum_dlistint - Computes the sum of all the elements in a doubly linked list.
 * @head: Pointer to the head of the list.
 *
 * Return: Sum of all elements in the list.
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;
	dlistint_t *current = head;

	while (current != NUL)L
		{
		sum += current->n;
		current = current->next;
		}
			
	return (sum);
}
