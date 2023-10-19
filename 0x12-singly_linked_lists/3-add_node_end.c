#include "lists.h"
#include <stdlib.h>
#include <string.h>

/**
* add_node_end - Add a new node at the end of a list_t list.
* @list: The head of the list.
* @content: The content for the new node.
*
* Return: If the function fails - NULL.
*         Otherwise - the address of the new element.
*/
list_t *add_node_end(list_t **list, const char *content)
{
char *copy = NULL;
int length = 0;
list_t *new_node, *last_node;

new_node = malloc(sizeof(list_t));
if (new_node == NULL)
return (NULL);

copy = strdup(content);
if (copy == NULL)
{
free(new_node);
return (NULL);
}

for (length = 0; content[length];)
length++;

new_node->str = copy;
new_node->len = length;
new_node->next = NULL;

if (*list == NULL)
*list = new_node;
else
{
last_node = *list;
while (last_node->next != NULL)
last_node = last_node->next;
last_node->next = new_node;
}

return (*list);
}

