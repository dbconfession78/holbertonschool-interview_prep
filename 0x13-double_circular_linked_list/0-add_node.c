#include "list.h"

/**
 * add_node_end - adds a new node to the end of a double circular linked list
 * @list: list to modify
 * @str: string to copy into the new node
 * Return: address of new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	List *first, *last, *new;

	if (*list == NULL)
	{
		first = malloc(sizeof(List *));
		first->next = first;
		first->prev = first;
		first->str = str;
		*list = first;
		return (first);
	}
	first = *list;
	last = malloc(sizeof(List *));
	last = first->prev;
	new = malloc(sizeof(List *));
	new->str = str;

	last->next = new;
	new->prev = last;
	new->next = *list;
	first->prev = new;
	return (new);
}


/**
 * add_node_begin - adds a new node to the beginning of a double
 *                  circular linked list
 * @list: list to modify
 * @str: string to copy into the new node
 * Return: address of new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *first, *last, *new;

	if (*list == NULL)
	{
		first = malloc(sizeof(List *));
		first->next = first;
		first->prev = first;
		first->str = str;
		*list = first;
		return (first);
	}
	first = *list;
	last = malloc(sizeof(List *));
	last = first->prev;
	new = malloc(sizeof(List *));
	new->str = str;

	new->next = first;
	new->prev = last;
	first->prev = new;
	last->next = new;
	*list = new;

	return (*list);
}
