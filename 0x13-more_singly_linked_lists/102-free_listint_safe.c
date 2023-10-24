#include "lists.h"
#include <stdlib.h>

/**
* free_listint_safe - Frees a listint_t linked list.
* @h: A pointer to a pointer to the head of the list.
* Return: The size of the list that was freed.
*/
size_t free_listint_safe(listint_t **h)
{
	size_t count_new = 0, count_comp = 0;
	listint_t *tmp, *head, *comp;

	if (h == NULL || *h == NULL)
	return (0);

	head = comp = tmp = *h;
	count_new = 0;

	while (head != NULL)
{
	comp = *h;
	count_comp = 0;
	while (count_new > count_comp)
{
	if (tmp == comp)
{
	*h = NULL;
	return (count_new);
}
	count_comp++;
	comp = comp->next;
}
	count_new++;
	tmp = head->next;
	free((void *)head);
	head = tmp;
}

*h = tmp;
	return (count_new);
}

