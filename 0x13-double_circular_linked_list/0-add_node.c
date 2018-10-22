#include "list.h"
#include <string.h>

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
	{
		new->next = new;
		new->prev = new;
		*list = new;
		return (new);
	}

	new->next = *list;
	new->prev = (*list)->prev;
	new->prev->next = new;
	(*list)->prev = new;
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
	{
		new->next = new;
		new->prev = new;
		*list = new;
		return (new);
	}

	new->next = *list;
	new->prev = (*list)->prev;
	(*list)->prev = new;
	new->prev->next = new;
	*list = new;
	return (new);
}
