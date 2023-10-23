#include "lists.h"
#include <stdlib.h>

/**
 * add_nodeint_end - adds a new node at the end of a listint_t list
 * @head: pointer to pointer of first node of listint_t list
 * @n: integer to be included in new node
 *
 * Return: address of the new element or NULL if it fails
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new, *current;

	if (head == NULL)
		return (NULL);
	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	
	new->n = n;
	new->next = NULL;
	
	if (*head == NULL)
	{
		*head = new;
		return (new);
       	}
	current = *head;
	while (current->next != NULL
			current = current->next;
			
			current->next = new;
			
			return (new);
}
