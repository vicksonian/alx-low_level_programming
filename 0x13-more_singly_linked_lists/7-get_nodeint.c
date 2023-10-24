#include "lists.h"
#include <stddef.h>

/**
* get_nodeint_at_index - returns the nth node of a listint_t linked list
* @head: pointer to the head of the list
* @index: index of the node to retrieve
* Return: pointer to the node at the given index, or NULL if it doesn't exist
*/
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)

{

unsigned int i = 0;

while (head != NULL)

{

if (i == index)

return (head);

head = head->next;

i++;

}

return (NULL);
}
