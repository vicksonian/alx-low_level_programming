#include "lists.h"

/**
* delete_nodeint_at_index - deletes the node at index of
* a listint_t linked list
* @head: pointer to a pointer to the head of the list
* @index: index of the node to delete
* Return: 1 if succeeded, -1 if it fails
*/
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current, *temp;
	unsigned int i = 0;

	if (*head == NULL)
	return (-1);

	if (index == 0)
{
	temp = *head;
	*head = temp->next;
	free(temp);
	return (1);
}

	current = *head;
	while (current != NULL && i < index - 1)
	{
	current = current->next;
	i++;
}

	if (current == NULL || current->next == NULL)
	return (-1);

	temp = current->next;
	current->next = temp->next;
	free(temp);
return (1);
}
