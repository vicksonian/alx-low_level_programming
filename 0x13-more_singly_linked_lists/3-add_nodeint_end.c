#include "lists.h"
#include <stdlib.h>

/**
* add_nodeint_end - adds a new node at the end of a listint_t list
* @head: pointer to a pointer to the head of the list
* @n: integer to be added to the new node
* Return: address of the new element, or NULL if it fails
*/
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new_node = malloc(sizeof(listint_t));
	listint_t *current = *head;

	if (new_node == NULL)
	return (NULL);
	new_node->n = n;
	new_node->next = NULL;

	if (*head == NULL)
{
	*head = new_node;
	return (new_node);
}

	while (current->next != NULL)
	current = current->next;

	current->next = new_node;
	return (new_node);
}
