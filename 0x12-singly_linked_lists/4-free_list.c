#include "lists.h"
#include <stdlib.h>

/**
 * free_list - Deallocates a list_t list.
 * @list: A pointer to the list_t list.
 */
void free_list(list_t *list)
{
    list_t *temp_node;

    while (list)
    {
        temp_node = list->next;
        free(list->str);
        free(list);
        list = temp_node;
    }
}

