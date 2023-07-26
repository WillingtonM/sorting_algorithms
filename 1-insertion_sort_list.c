#include "sort.h"
/**
 * insertion_sort_list - Sorts a doubly linked list of integers in asc order
 *                       using the Insertion sort algorithm
 *
 * @list: doubly linked list
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node;
	int x;

	if (!list)
		return;
	node = *list;
	while (node)
	{
		while (node)
		{
			if (node->next)
			{
				if (node->n > node->next->n)
				{
					x = node->n;
					*(int *)&node->n = node->next->n;
					*(int *)&node->next->n = x;
					node = *list;
					print_list(*list);
					break;
				}
			}
			node = node->next;
		}
	}
}
