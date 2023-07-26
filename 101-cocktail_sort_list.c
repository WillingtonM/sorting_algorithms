#include "sort.h"

void swapme(listint_t *current, listint_t *current_old, listint_t **list);
void cocktail_sort_list(listint_t **list);

/**
 * cocktail_sort_list - cocktail_sort_list
 *
 * @list: doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *chck = *list, *frst = NULL, *lst = NULL;

	if (!list)
		return;
	if (!(*list))
		return;
	if (!(*list)->next)
		return;
	do
	{
		while (chck->next)
		{
			if (chck->n > chck->next->n)
				swapme(chck->next, chck, list);
			else
				chck = chck->next;
		}
		lst = chck;
		while (chck->prev != frst)
		{
			if (chck->n < chck->prev->n)
				swapme(chck, chck->prev, list);
			else
				chck = chck->prev;
		}
		frst = chck;
	} while (frst != lst);
}

/**
 * swapme - Swap nodes themselves.
 * @current: Pointer.
 * @current_old: Pointer.
 * @list: Doubly linked list
 */
void swapme(listint_t *current, listint_t *current_old, listint_t **list)
{
	listint_t *tmp_1 = current->next;
	listint_t *tmp_2 = current_old->prev;

	if (tmp_1 != NULL)
		tmp_1->prev = current_old;
	if (tmp_2 != NULL)
		tmp_2->next = current;
	current->prev = tmp_2;
	current_old->next = tmp_1;
	current->next = current_old;
	current_old->prev = current;
	if (*list == current_old)
		*list = current;
	print_list(*list);
}
