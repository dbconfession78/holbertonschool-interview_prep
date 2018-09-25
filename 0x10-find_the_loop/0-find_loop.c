#include "lists.h"


/**
 * find_listint_loop - finds the first node in a looped linked list
 * @head: pointer to the head of linked list
 * Return: pointer to node where loop begins
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *walk = head;

	while (walk)
	{
		if (walk->next)
		{
/* printf("&walk->n: %p\n", (void *)&walk->n); */
/* printf("&walk->next->n: %p\n", (void *)&walk->next->n); */
/* printf("%d\n", (void *)&walk->n < (void *)&walk->next->n); */

			if (&walk->n < &walk->next->n)
			{
				walk = walk->next;
				break;
			}
		}
		walk = walk->next;
	}
	return (walk);
}
