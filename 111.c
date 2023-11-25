#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using Insertion Sort.
 *
 * @list: A pointer to a pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
listint_t *current;
if (list == NULL || *list == NULL || (*list)->next == NULL)
return;
current = (*list)->next;
while (current != NULL)
{
listint_t *insertion_point = current->prev;
while (insertion_point != NULL && insertion_point->n)
{
insertion_point = insertion_point->prev;
}
if (insertion_point == NULL)
{
listint_t *temp = current->next;
current->next = (*list);
current->prev = NULL;
(*list)->prev = current;
(*list) = current;
current = temp;
}
else if (insertion_point->next != current)
{
listint_t *temp = current->next;
insertion_point->next->prev = current;
current->next = insertion_point->next;
insertion_point->next = current;
current->prev = insertion_point;
current = temp;
}
else
{
current = current->next;
}
print_list(*list);
}
}
