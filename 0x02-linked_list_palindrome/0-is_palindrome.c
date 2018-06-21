#include <stdlib.h>
#include <stdio.h>
#include "lists.h"


/**
 * is_palindrome - checks if a linked list is a palindrome.
 * @head:  pointer to the head of a singly linked list.
 * Return: 1 if all is a palindrome; 0 otherwise.
 */
int is_palindrome(listint_t **head)
{
	listint_t *f;
	listint_t *s;
	listint_t *w;
	listint_t *mid;
	int _len;

	if (*head == NULL || head == NULL)
		return (1);

	f = *head;
	s = *head;
	_len = 0;
	while (f->next)
	{
		_len++;
		if (f->next->next)
		{
			f = f->next;
			_len++;
		}
		f = f->next;
		s = s->next;
	}
	if (f)
		_len++;
	mid = reverse(&s);
	w = mid;
	s = *head;
	while (w)
	{
		if (w->n != s->n)
			return (0);
		w = w->next;
		s = s->next;
	}
	return (1);
}


/**
 * reverse - reverses the order of nodes starting with the pointer to head
 * @head:  pointer to the node you want to start the reversal at
 * Return: new head
 */
listint_t *reverse(listint_t **head)
{
	listint_t *nxt;
	listint_t *prev;
	listint_t *walk;

	walk = *head;
	prev = NULL;
	while (walk)
	{
		nxt = walk->next;
		walk->next = prev;
		prev = walk;
		if (nxt == NULL)
			break;
		walk = nxt;
	}
	return (walk);
}
