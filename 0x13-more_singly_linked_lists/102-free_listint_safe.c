#include <stdlib.h>
#include "lists.h"

/**
* free_listint_safe - Frees a listint_t linked list.
* @h: A pointer to a pointer to the head of the list.
* Return: The size of the list that was freed.
*/

size_t free_listint_safe(listint_t **h)
{
size_t node_count = 0;
listint_t *current;
listint_t *temp;

current = *h;

while (current != NULL)
{
node_count++;
temp = current;
current = current->next;
free(temp);
if (current == *h)
{
*h = NULL;
break;
}
}

return (node_count);
}
