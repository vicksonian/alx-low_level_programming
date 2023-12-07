#include "lists.h"
#include <stdlib.h>

/**
* delete_dnodeint_at_index - Deletes the node at index of a dlistint_t
* linked list.
* @head: A pointer to a pointer to the head of the doubly linked list.
* @index: The index of the node that should be deleted. Index starts at 0.
* Return: 1 if it succeeded, -1 if it failed.
*/
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
dlistint_t *temp, *del_node;
unsigned int i = 0;
if (head == NULL || *head == NULL)
return (-1);
temp = *head;
if (index == 0)
{
*head = temp->next;
if (*head != NULL)
(*head)->prev = NULL;
free(temp);
return (1);
}
while (temp != NULL && i < index - 1)
{
temp = temp->next;
i++;
}
if (temp == NULL || temp->next == NULL)
return (-1);
del_node = temp->next;
temp->next = del_node->next;
if (del_node->next != NULL)
del_node->next->prev = temp;
free(del_node);
return (1);
}
