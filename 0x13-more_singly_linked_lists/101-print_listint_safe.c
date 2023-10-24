#include "lists.h"
#include <stdio.h>

/**
* print_listint_safe - Prints a listint_t linked list.
* @head: A pointer to the head of the list.
* Return: The number of nodes in the list.
*/
size_t print_listint_safe(const listint_t *head)
{
	size_t node_count = 0;
	const listint_t *current = head;

	while (current != NULL)
	{
	size_t count_comp = 0;
	const listint_t *comp = head;

	while (count_comp < node_count)
	{
	if (current == comp)
	{
	printf("-> [%p] %d\n", (void *)current, current->n);
	return (node_count);
	}
	comp = comp->next;
	count_comp++;
	}

	printf("[%p] %d\n", (void *)current, current->n);
	node_count++;
	current = current->next;

	if (current == head)
	{
	printf("-> [%p] %d\n", (void *)current, current->n);
	return (node_count);
	}
}

return (node_count);
}

