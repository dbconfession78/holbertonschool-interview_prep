#include "search.h"

/**
 * linear_skip - searches for a value in a soeted skip list of integers
 * @list: the skip list to search
 * @value: the target value to search for
 * Return: ptr to first node with target value or NULL if not found
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *walk, *last_express_node;
	size_t last_express_idx;

	if (list == NULL)
		return (NULL);
	walk = list;
	if (walk->n == value)
	{
		printf("Value checked at index [%lu] = [%d]\n", walk->index,  walk->n);
		return (walk);
	}
	while (walk)
	{
		last_express_idx = walk->index;
		last_express_node = walk;
		if (walk->express == NULL)
		{
			printf("Value found between index [%lu] and [%d]\n",
				   last_express_idx, list_length(list) - 1);
			return (search_by_one(last_express_node, value));
		}
		walk = walk->express;
		printf("Value checked at index [%lu] = [%d]\n", walk->index,  walk->n);
		if (walk->n == value)
			return (walk);
		if (value <= walk->n)
		{
			if (value == walk->n)
				return (walk);
			printf("Value found between index [%lu] and [%lu]\n",
				   last_express_idx,  walk->index);
			walk = last_express_node;
			return (search_by_one(walk, value));
		}
	}
	printf("Value found between index [%lu] and [%lu]\n",
		   last_express_idx,  walk->index);
	return (search_by_one(last_express_node, value));
}

/**
 * search_by_one - searches in a regular node by node fashion
 * @node: the node to begin at
 * @value: the target value to search for
 * Return: ptr to first node with target value or NULL if not found
 */
skiplist_t *search_by_one(skiplist_t *node, int value)
{
	while (node)
	{
		printf("Value checked at index [%lu] = [%d]\n", node->index,  node->n);
		if (node->n == value)
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * list_length - gets the length of a linked list
 * @root: ptr to first node in linked list
 * Return: the length of the linked list
 */
int list_length(skiplist_t *root)
{
	int i;

	for (i = 0; root; root = root->next, i++)
	return (i);
}
