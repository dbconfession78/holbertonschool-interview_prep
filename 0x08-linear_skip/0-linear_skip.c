#include "search.h"

/**
 * linear_skip - searches for a value in a soeted skip list of integers
 * @list: the skip list to search
 * @value: the target value to search for
 * Return: ptr to first node with target value or NULL if not found
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *walk, *express, *last_express_node;
	size_t last_express_idx;

	if (list == NULL)
		return (NULL);

	walk = list;
	while (walk)
	{
		last_express_idx = walk->index;
		last_express_node = walk;
		if (walk->express == NULL)
			return (NULL);
		walk = walk->express;
		printf("Value checked at index [%lu] = [%d]\n", walk->index,  walk->n);
		if (value <= walk->n)
		{
			printf("Value found between index [%lu] and [%lu]\n",
				   last_express_idx,  walk->index);
			walk = last_express_node;
			return (search_by_one(walk, value));
		}
	}
	return (NULL);
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
