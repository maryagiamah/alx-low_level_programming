#include "lists.h"

/**
 * free_dlistint - Free list
 *
 * @head: struct
 *
 * Return: void
 */

void free_dlistint(dlistint_t *head)
{
	if (head)
	{
		free_dlistint(head->next);
		free(head);
	}
}
