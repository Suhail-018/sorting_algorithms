#include "sort.h"
#include <stdio.h>
/**
* swap_nodes - Swaps two nodes in a doubly linked list
*
* @list: A pointer to the head of the doubly linked list
* @node_a: The first node to be swapped
* @node_b: The second node to be swapped
*/
void swap_nodes(listint_t **list, listint_t *node_a, listint_t *node_b)
{
if (node_a->prev != NULL)
node_a->prev->next = node_b;
else
*list = node_b;
if (node_b->next != NULL)
node_b->next->prev = node_a;
node_a->next = node_b->next;
node_b->prev = node_a->prev;
node_a->prev = node_b;
node_b->next = node_a;
}
/**
* cocktail_sort_list - Sorts a doubly linked list of integers using
*                      the Cocktail Shaker Sort algorithm
*
* @list: A pointer to the head of the doubly linked list
*/
void cocktail_sort_list(listint_t **list)
{
int swapped;
listint_t *current;
if (list == NULL || *list == NULL)
return;
do {
swapped = 0;
current = *list;
while (current->next != NULL)
{
if (current->n > current->next->n)
{
swap_nodes(list, current, current->next);
swapped = 1;
print_list(*list);
}
else
current = current->next;
}
if (!swapped)
break;
swapped = 0;
while (current->prev != NULL)
{
if (current->n < current->prev->n)
{
swap_nodes(list, current->prev, current);
swapped = 1;
print_list(*list);
}
else
current = current->prev;
}
} while (swapped);
}
