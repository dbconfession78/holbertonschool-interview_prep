#include "list.h"
#include <string.h>
#include <stdlib.h>

/**
 * add_node_end - adds a new node to the end of a double circular linked list
 * @list: list to modify
 * @str: string to copy into the new node
 * Return: address of new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	List *new = NULL;

	if (list == NULL || str == NULL)
		return (NULL);

	new = malloc(sizeof(List));
	if (new == NULL)
		return (NULL);

	new->str = strdup(str);
	if (new->str == NULL)
	{
		free(new);
		return (NULL);
	}

	if (*list == NULL)
		new->next = new;
	else
		new->next = *list;

	if (*list == NULL)
		new->prev = new;
	else
		new->prev = (*list)->prev;

	if (*list != NULL)
	{
		(*list)->prev->next = new;
		(*list)->prev = new;
	}
	else
		*list = new;
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
/*	List *first, *last, *new; */
	List *new = NULL;

	if (list == NULL || str == NULL)
		return (NULL);

	new = malloc(sizeof(List));
	if (new == NULL)
		return (NULL);

	new->str = strdup(str);
	if (new->str == NULL)
	{
		free(new);
		return (NULL);
	}

	if (*list == NULL)
		new->next = new;
	else
		new->next = *list;

	if (*list == NULL)
		new->prev = new;
	else
		new->prev = (*list)->prev;

	if (*list != NULL)
	{
		(*list)->prev->next = new;
		(*list)->prev = new;
	}
	*list = new;
	return (new);
}
