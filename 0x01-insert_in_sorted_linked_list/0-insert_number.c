#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - inserts a listint_t node into a sll
 * @head: pointer to pointer of first node in sll
 * @number: the value of inserted  node's 'n' attribute
 * Return: pointer to head
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *walk = *head;
	listint_t *new;

	if (*head == NULL)
	{

		walk = malloc(sizeof(listint_t));
		walk->n = number;
		*head = walk;
		return (*head);
	}

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = number;
	if (walk->n >= number)
	{
		new->next = walk;
		*head = new;
		return (*head);
	}
	while (walk && walk->next)
	{
		if (walk->n <= number && walk->next->n >= number)
		{
			new->next = walk->next;
			break;
		}
		walk = walk->next;
	}
	walk->next = new;
	return (*head);
}
