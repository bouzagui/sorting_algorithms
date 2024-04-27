#include "sort.h"

/**
 * insertion_sort_list - sorts a list of integers using insertion sort
 * @list: The list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
listint_t *current, *next_node, *new_head;

if (list == NULL || *list == NULL)
{
return;
}

new_head = (*list);
current = new_head->next;

while (current)
{
next_node = current->next;

while (current->prev && current->n < current->prev->n)
{
current->prev->next = current->next;
if (current->next)
{
current->next->prev = current->prev;
}

current->next = current->prev;
current->prev = current->next->prev;
current->next->prev = current;

if (current->prev)
{
current->prev->next = current;
}
else
{
new_head = current;
}
print_list(new_head);
}
current = next_node;
}
*list = new_head;
}
