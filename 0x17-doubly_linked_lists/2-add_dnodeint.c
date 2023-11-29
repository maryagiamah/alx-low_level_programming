#include "lists.h"

/**
 * add_dnodeint - Adds a new node at the beginning
 * @head: pointer to the head of the linked list.
 * @n: Value to add as a node structure.
 *
 * Return: pointer to new node.
 */

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new = (dlistint_t *) malloc(sizeof(dlistint_t));

	if (!new)
	{
		return (NULL);
	}
	new->n = n;
	new->prev = NULL;
	new->next = *head;
	if (*head)
	{
		(*head)->prev = new;
	}
	*head = new;
	return (new);
}
