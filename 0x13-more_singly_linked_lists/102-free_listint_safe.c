#include "lists.h"

/**
* free_listint_safe - Frees a listint_t list safely.
* @h: A pointer to a pointer to the first node of the list.
* Return: The size of the list that was freed.
*/
size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	listint_t *current = *h;
	listint_t *next;

	while (current != NULL)
	{
	count++;

		if (current < current->next)
		{
		next = current->next;
		free(current);
	current = next;
	}
	else
	{
	free(current);
	*h = NULL;
	break;
	}
	}

	*h = NULL;

	return (count);
}
