#include "lists.h"

/**
 * add_dnodeint_end - Adds a new node at the end
 *
 * @head: struct
 *
 * @n: const int
 *
 * Return: dlistint_t
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{

	dlistint_t *new = (dlistint_t *) malloc(sizeof(dlistint_t)), *current = *head;

	if (!new || !head)
	{
		return (NULL);
	}
	new->n = n;
	new->next = NULL;
	if (!*head)
	{
		new->prev = NULL;
		*head = new;
		return (new);
	}
	while (current->next)
	{
		current = current->next;
	}
	current->next = new;
	new->prev = current;
	return (new);
}
