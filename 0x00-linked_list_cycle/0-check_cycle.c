#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * check_cycle - checks if a linked list has a cycle
 * @list: the linked list to check for cycle
 * Return: 1 if cycle exists; 0 otherwise
 */
int check_cycle(listint_t *list)
{
	listint_t *walk = list;

	if (list == NULL)
		return (0);

	while (walk)
	{
		if (walk->next == list)
			return (1);
		walk = walk->next;
	}
	return (0);
}
