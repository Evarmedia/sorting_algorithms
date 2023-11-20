#include "sort.h"

void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker);
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker);
void cocktail_sort_list(listint_t **list);

/**
 * swap_node_ahead - Swap a node in a listint_t doubly-linked list
 *                   list of integers with the node ahead of it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @shaker: A pointer to the current swapping node of the cocktail shaker algo.
 */
void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmpVal = (*shaker)->next;

	if ((*shaker)->prev != NULL)
		(*shaker)->prev->next = tmpVal;
	else
		*list = tmpVal;
	tmpVal->prev = (*shaker)->prev;
	(*shaker)->next = tmpVal->next;
	if (tmpVal->next != NULL)
		tmpVal->next->prev = *shaker;
	else
		*tail = *shaker;
	(*shaker)->prev = tmpVal;
	tmpVal->next = *shaker;
	*shaker = tmpVal;
}

/**
 * swap_node_behind - Swap a node in a listint_t doubly-linked
 *                    list of integers with the node behind it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @shaker: A pointer to the current swapping node of the cocktail shaker algo.
 */
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmpVal = (*shaker)->prev;

	if ((*shaker)->next != NULL)
		(*shaker)->next->prev = tmpVal;
	else
		*tail = tmpVal;
	tmpVal->next = (*shaker)->next;
	(*shaker)->prev = tmpVal->prev;
	if (tmpVal->prev != NULL)
		tmpVal->prev->next = *shaker;
	else
		*list = *shaker;
	(*shaker)->next = tmpVal;
	tmpVal->prev = *shaker;
	*shaker = tmpVal;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers in
 *                      ascending order using the cocktail shaker algorithm.
 * @list: A pointer to the head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *shaker;
	bool shaken_nt_strd = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (shaken_nt_strd == false)
	{
		shaken_nt_strd = true;
		for (shaker = *list; shaker != tail; shaker = shaker->next)
		{
			if (shaker->n > shaker->next->n)
			{
				swap_node_ahead(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				shaken_nt_strd = false;
			}
		}
		for (shaker = shaker->prev; shaker != *list;
				shaker = shaker->prev)
		{
			if (shaker->n < shaker->prev->n)
			{
				swap_node_behind(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				shaken_nt_strd = false;
			}
		}
	}
}

