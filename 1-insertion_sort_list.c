#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: pointer to pointer to head of list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *tmp, *prev_node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}
	curr = (*list)->next;
	while (curr != NULL)
	{
		prev_node = curr->prev;
		while (prev_node != NULL && curr->n < prev_node->n)
		{
			tmp = prev_node->prev;
			if (tmp != NULL)
			{
				tmp->next = curr;
			}
			else
			{
				*list = curr;
			}
			if (curr->next != NULL)
			{
				curr->next->prev = prev_node;
			}
			else
			{
				prev_node->next = NULL;
			}
			prev_node->prev = curr;
			prev_node->next = curr->next;
			curr->prev = tmp;
			curr->next = prev_node;
			print_list(*list);
			prev_node = curr->prev;
		}
		curr = curr->next;
	}
}
