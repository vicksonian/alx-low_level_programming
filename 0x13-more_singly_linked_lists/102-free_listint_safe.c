#include <stdlib.h>
#include <stdint.h>
#include "lists.h"

/**
* free_listint_safe - Frees a listint_t list with a loop.
* @head: A pointer to the pointer of the head of the list.
* Return: The size of the list that was freed.
*/
size_t free_listint_safe(listint_t **head)
{
size_t num_freed = 0;
listint_t *temp;

if (!head || !*head)
return (0);

while (*head)
{
intptr_t diff = (intptr_t)*head - (intptr_t)(*head)->next;

if (diff > 0)
{
temp = (*head)->next;
free(*head);
*head = temp;
num_freed++;
}
else
{
free(*head);
*head = NULL;
num_freed++;
break;
}
}

*head = NULL;

return (num_freed);
}

