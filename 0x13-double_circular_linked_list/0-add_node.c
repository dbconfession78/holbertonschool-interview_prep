#include "list.h"

/**
 * add_node_end - adds a new node to the end of a double circular linked list
 * @list: list to modify
 * @str: string to copy into the new node
 * Return: address of new node, or NULL on failure
 */
/* List *add_node_end_1(List **list, char *str) */
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
 * add_node_end_2 - adds a new node to the end of a double circular linked list
 * @list: list to modify
 * @str: string to copy into the new node
 * Return: address of new node, or NULL on failure
 */
List *add_node_end_2(List **list, char *str)
 /* List *add_node_end(List **list, char *str) */
{
	struct List *last, *new_node;

	if (*list == NULL)
	{
		new_node = malloc(sizeof(List));
		new_node->str = str;
		new_node->next = new_node->prev = new_node;
		*list = new_node;
		return (new_node);
	}

	last = (*list)->prev;
	new_node = malloc(sizeof(List));
	new_node->str = str;
	new_node->next = *list;
	(*list)->prev = new_node;
	new_node->prev = last;
	last->next = new_node;
	return (new_node);
}

/**
 * add_node_begin - adds a new node to the beginning of a double
 *                  circular linked list
 * @list: list to modify
 * @str: string to copy into the new node
 * Return: address of new node, or NULL on failure
 */
/* List *add_node_begin_1(List **list, char *str) */
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

	return (new);
}

/**
 * add_node_begin_2 - adds a new node to the beginning of a double
 *                  circular linked list
 * @list: list to modify
 * @str: string to copy into the new node
 * Return: address of new node, or NULL on failure
 */
List *add_node_begin_2(List **list, char *str)
/* List *add_node_begin(List **list, char *str) */
{
	struct List *last, *new_node;

	if (*list == NULL)
	{
		struct List *new_node = malloc(sizeof(List));

		new_node->str = str;
		new_node->next = new_node->prev = new_node;
		*list = new_node;
		return (new_node);
	}

	last = (*list)->prev;
	new_node = malloc(sizeof(List));

	new_node->str = str;
	new_node->next = *list;
	new_node->prev = last;
	last->next = (*list)->prev = new_node;
	*list = new_node;
	return (new_node);
}
