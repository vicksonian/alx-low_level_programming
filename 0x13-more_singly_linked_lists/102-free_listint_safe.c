#include "lists.h"

/**
* free_listint_safe - Frees a listint_t list with a loop.
* @h: A pointer to the pointer of the head of the list.
* Return: The size of the list that was freed.
*/
size_t free_listint_safe(listint_t **h)
{
listint_t *current, *next;
size_t nodes = 0;
size_t i;
listint_t *node_addresses[1024];
if (h == NULL || *h == NULL)
return (0);

current = *h;
while (current)
{
node_addresses[nodes] = current;
nodes++;
next = current->next;

for (i = 0; i < nodes; i++)
{
if (current == node_addresses[i])
{
*h = NULL;
return (nodes);
}
}
free(current);
current = next;
}
*h = NULL;
return (nodes);
}

