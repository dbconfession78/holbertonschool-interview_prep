#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
# include "hash_tables.h"

/**
 * check_cycle - checks if a linked list has a cycle
 * @list: the linked list to check for cycle
 * Return: 1 if cycle exists; 0 otherwise
 */

int check_cycle(listint_t *list)
{
	listint_t *slow;
	listint_t *fast;

	slow = list;
	fast = list;

	while (slow && fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			return (1);
		}
	}

	return (0);
}
