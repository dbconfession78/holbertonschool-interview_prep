#include "binary_trees.h"

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: double pointer to root node of heap
 * Return: value stored in root node or 0 on fail
 */
int heap_extract(heap_t **root)
{
	int is_left_side, to_fill_is_left, extract;
	heap_t *walk, *max_node, *branch, *to_fill;

	if (root == NULL || *root == NULL)
		return (0);

	to_fill_is_left = extract = is_left_side = 0;
	walk = *root;
	extract = walk->n;
	branch = NULL;
	max_node = get_max_node(walk->left, walk->right);

	if (max_node == NULL)
	{
		*root = NULL;
		return (extract);
	}

	while (walk)
	{
		max_node = get_max_node(walk->left, walk->right);
		if (max_node == NULL)
			break;

		if (branch == NULL)
		{
			if (is_left_side == 1 && max_node == walk->right)
				branch = walk;
			if (is_left_side == 0 && max_node == walk->left)
				branch = walk;
		}

		walk->n = max_node->n;
		walk = max_node;
	}
	if (walk->parent->left == walk)
		to_fill_is_left = 1;

	if (branch == NULL)
		branch = walk->parent;

	to_fill = walk;
	if (is_left_side == 1)
		walk = *root;
	else
		walk = branch;

	walk_down(walk, to_fill, to_fill_is_left);
	return (extract);
}

/**
 * walk_down - traverse right side until at last parent node
 * @walk: pointer to node to start at
 * @to_fill: pointer to last node whose value was moved up
 * @to_fill_is_left: indicates if 'to_fill' is the left of it's parent
 * Return: void
 */
void walk_down(heap_t *walk, heap_t *to_fill, int to_fill_is_left)
{
	heap_t *left;
	heap_t *right;

	while (walk)
	{
		left = walk->left;
		right = walk->right;
		if (is_leaf(left) && is_leaf(right))
		{
			if (left && right == NULL)
			{
				to_fill->n = left->n;
				left->parent->left = NULL;
				return;
			}
			if (right && left == NULL)
			{
				walk->left = right;
				right->parent->right = NULL;
			}
			if (right == NULL)
			{
				if (to_fill_is_left)
				{
					to_fill->parent->left = NULL;
				}
				else
				{
					to_fill->n = walk->n;
					walk->parent->right = NULL;
				}
				return;
			}
		}

		walk = walk->right;
	}
	if (to_fill_is_left)
		to_fill->parent->left = NULL;
	else
		to_fill->parent->right = NULL;
}

/**
 * is_leaf - indicates if node is a leaf
 * @node: pointer to node to identify as leaf
 * Return: 1 if is a leaf or NULL, 0 otherwise
 */
int is_leaf(heap_t *node)
{
	if (node == NULL)
		return (1);

	if (node->left == NULL && node->right == NULL)
		return (1);
	return (0);
}

/**
 * get_max_node - returns node with higher 'n' of two nodes
 * @node_a: pointer to first node in comparison
 * @node_b: pointer to second node in comparison
 * Return: node_a if node_a->n is higher than node_b->n, node_b otherwise
 */
heap_t *get_max_node(heap_t *node_a, heap_t *node_b)
{
	if (node_a == NULL && node_b == NULL)
		return (NULL);
	if (node_a == NULL && node_b != NULL)
		return (node_b);
	if (node_a != NULL && node_b == NULL)
		return (node_a);
	if (node_a->n > node_b->n)
		return (node_a);
	return (node_b);
}
