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
	listint_t *walk;
	int *arr;
	int i;

	walk = *head;
	if (walk == NULL)
		return (1);
	arr = malloc(sizeof(int) * 256);
	i = 0;
	while (walk->next)
	{
		arr[i] = walk->n;
		i++;
		walk = walk->next;
	}
	arr[i] = walk->n;
	walk = *head;
	while (arr[i])
	{
		if (arr[i] != walk->n)
			free(arr);
			return (0);
		walk = walk->next;
		i--;
	}
	free(arr);
	return (1);
}
