#include "deck.h"

int _str_cmp(const char *s1, const char *s2);
void insertion_sort_deck_kind(deck_node_t **deck);
void insertion_sort_deck_value(deck_node_t **deck);
void sort_deck(deck_node_t **deck);
char get_val(deck_node_t *card);

/**
 * _str_cmp - Compares two strings.
 * @s1: First string to be compared.
 * @s2: Second string to be compared.
 *
 * Return: Positive byte difference
 */
int _str_cmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 != *s2)
		return (*s1 - *s2);
	return (0);
}

/**
 * get_val - Get numerical value of a card.
 * @card: Pointer to a deck_node_t card.
 * Return: Numerical value of card.
 */
char get_val(deck_node_t *card)
{
	if (_str_cmp(card->card->value, "Ace") == 0)
		return (0);
	if (_str_cmp(card->card->value, "1") == 0)
		return (1);
	if (_str_cmp(card->card->value, "2") == 0)
		return (2);
	if (_str_cmp(card->card->value, "3") == 0)
		return (3);
	if (_str_cmp(card->card->value, "4") == 0)
		return (4);
	if (_str_cmp(card->card->value, "5") == 0)
		return (5);
	if (_str_cmp(card->card->value, "6") == 0)
		return (6);
	if (_str_cmp(card->card->value, "7") == 0)
		return (7);
	if (_str_cmp(card->card->value, "8") == 0)
		return (8);
	if (_str_cmp(card->card->value, "9") == 0)
		return (9);
	if (_str_cmp(card->card->value, "10") == 0)
		return (10);
	if (_str_cmp(card->card->value, "Jack") == 0)
		return (11);
	if (_str_cmp(card->card->value, "Queen") == 0)
		return (12);
	return (13);
}

/**
 * insertion_sort_deck_kind - Sort deck of cards from spades to diamonds.
 * @deck: Pointer to head of a deck_node_t doubly-linked list.
 * Return: void
 */
void insertion_sort_deck_kind(deck_node_t **deck)
{
	deck_node_t *iterator, *insrt, *tmp;

	for (iterator = (*deck)->next; iterator != NULL; iterator = tmp)
	{
		tmp = iterator->next;
		insrt = iterator->prev;
		while (insrt != NULL && insrt->card->kind > iterator->card->kind)
		{
			insrt->next = iterator->next;
			if (iterator->next != NULL)
				iterator->next->prev = insrt;
			iterator->prev = insrt->prev;
			iterator->next = insrt;
			if (insrt->prev != NULL)
				insrt->prev->next = iterator;
			else
				*deck = iterator;
			insrt->prev = iterator;
			insrt = iterator->prev;
		}
	}
}

/**
 * sort_deck - Sort deck cards from ace to king & from spades to diamonds
 * @deck: Pointer to head of a deck_node_t doubly-linked list.
 * Return: void
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	insertion_sort_deck_kind(deck);
	insertion_sort_deck_value(deck);
}

/**
 * insertion_sort_deck_value - Sort cards spades to diamonds, ace to king
 * @deck: Pointer to head of a deck_node_t doubly-linked list.
 * Return: void
 */
void insertion_sort_deck_value(deck_node_t **deck)
{
	deck_node_t *iterator, *insrt, *tmp;

	for (iterator = (*deck)->next; iterator != NULL; iterator = tmp)
	{
		tmp = iterator->next;
		insrt = iterator->prev;
		while (insrt != NULL &&
		       insrt->card->kind == iterator->card->kind &&
		       get_val(insrt) > get_val(iterator))
		{
			insrt->next = iterator->next;
			if (iterator->next != NULL)
				iterator->next->prev = insrt;
			iterator->prev = insrt->prev;
			iterator->next = insrt;
			if (insrt->prev != NULL)
				insrt->prev->next = iterator;
			else
				*deck = iterator;
			insrt->prev = iterator;
			insrt = iterator->prev;
		}
	}
}

