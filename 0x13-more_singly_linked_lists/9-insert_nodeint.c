#include "lists.h"
#include <stdlib.h>

/**
* insert_nodeint_at_index - inserts a new node at a given position
* @head: pointer to a pointer to the head of the list
* @idx: index where the new node should be added
* @n: integer to be added to the new node
* Return: address of the new element, or NULL if it fails
*/
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node = malloc(sizeof(listint_t));
	listint_t *current = *head;
	unsigned int i = 0;

	if (new_node == NULL)
	return (NULL);
	new_node->n = n;

	if (idx == 0)
{
	new_node->next = *head;
	*head = new_node;
	return (new_node);
}

	while (current != NULL && i < idx - 1)
{
	current = current->next;
	i++;
}

if (current == NULL)
{
	free(new_node);
	return (NULL);
}

	new_node->next = current->next;
	current->next = new_node;

return (new_node);
}
