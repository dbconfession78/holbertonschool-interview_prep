#include "binary_trees.h"

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: double pointer to root node of heap
 * Return: value stored in root node or 0 on fail
 */
int heap_extract(heap_t **root)
{
	heap_t *walk, *last_node;
	int extract, last_val;

	last_node = NULL;
	if (root == NULL || *root == NULL)
		return (0);
	walk = *root;
	extract = walk->n;
	last_node = get_last_insert(*root);
	last_val = walk == last_node ? -1 : last_node->n;
	if (walk == last_node)
	{
		free(*root);
		*root = NULL;
	}
	else
	{
		walk->n = last_val;
		if (last_node->parent != NULL && last_node->parent->left == last_node)
			last_node->parent->left = NULL;
		else if (last_node->parent != NULL)
			last_node->parent->right = NULL;
		free(last_node);
		heapify(walk);
	}
	return (extract);
}

/**
 * get_last_insert - returns a pointer to the last node inserted into heap
 * @walk: pointer to root node of current recurse
 * Return: pointer to last node ineserted into heap
 */
heap_t *get_last_insert(heap_t *walk)
{
	int left_height, right_height, left_count, right_count;

	if (walk == NULL)
		return (NULL);

	if (walk->left == NULL && walk->right == NULL)
		return (walk);

	left_height = get_height(walk->left);
	left_count = get_node_count(walk->left);
	right_height = get_height(walk->right);
	right_count = get_node_count(walk->right);
	if (left_height > right_height)
		return (get_last_insert(walk->left));

	if (left_count > right_count)
		return (get_last_insert(walk->right));

	return (get_last_insert(walk->right));
}


/**
 * get_height - recursively gets height of tree from node 'walk'
 * @walk: pointer to root node of current recurse
 * Return: int height of heap from starting node
 */
int get_height(heap_t *walk)
{
	int right_height, left_height;

	right_height = left_height = 0;

	if (walk != NULL)
	{
		if (walk->left == NULL && walk->right == NULL)
			return (1);
		if (walk->left != NULL)
			left_height += get_height(walk->left) + 1;
		if (walk->right != NULL)
			right_height += get_height(walk->right) + 1;
	}
	if (left_height > right_height)
		return (left_height);
	return (right_height);
}

/**
 * heapify - maintains a max heap data structure
 * @node: node to begin heapify with
 * Return: void
 */
void heapify(heap_t *node)
{
	heap_t *walk = node;
	int curr_val, l_val, r_val;

	if (node == NULL)
		return;
	while (walk->left != NULL || walk->right != NULL)
	{
		curr_val = walk->n;
		r_val = walk->right == NULL ? -1 : walk->right->n;
		l_val = walk->left == NULL ? -1 : walk->left->n;
		if (walk->left != NULL && walk->right != NULL)
		{
			if ((walk->n < l_val) && (l_val > r_val))
			{
				walk->n = l_val;
				walk->left->n = curr_val;
				walk = walk->left;
			}
			else
			{
				walk->n = r_val;
				walk->right->n = curr_val;
				walk = walk->right;
			}
		}
		else if (walk->left != NULL && (curr_val < l_val))
		{
			walk->n = l_val;
			walk->left->n = curr_val;
			walk = walk->left;
		}
		else if (walk->right != NULL && curr_val < r_val)
		{
			walk->n = r_val;
			walk->right->n = curr_val;
			walk = walk->right;
		}
		else
			return;
	}
}

/**
 * get_node_count - finds total node count of heap
 * @walk: pointer of node to start counting from
 * Return: int vaue of total count
 */
int get_node_count(heap_t *walk)
{
	int retval;

	retval = 0;
	if (walk != NULL)
	{
		if (walk->left != NULL)
			retval += get_node_count(walk->left);
		if (walk->right)
			retval += get_node_count(walk->right);
		retval++;
	}
	return (retval);
}
