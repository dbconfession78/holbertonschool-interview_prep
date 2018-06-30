#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * sorted_array_to_avl - creates an avl tree from a sorted array
 * @array: array to convert into an avl tree
 * @size: length of array
 * Return: the completed avl tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *tree;

	if (array == NULL)
		return (NULL);

	tree = init_node();
	helper(tree, array, 0, size - 1);
	return (tree);
}


/**
 * init_node - initializes a new node with NULL parent and child ptrs
 * Return: ptr to new node
 */
avl_t *init_node()
{
	avl_t *node_ptr;

	node_ptr = malloc(sizeof(avl_t));
	if (node_ptr == NULL)
		return (NULL);

	node_ptr->left = NULL;
	node_ptr->right = NULL;
	node_ptr->parent = NULL;
	return (node_ptr);
}


/**
 * helper - recursive helper function for sorted_array_to_avl
 * @node: ptr to current node
 * @array: source array
 * @left: ptr to 'node' left child
 * @right: ptr to 'node' right child
 * Return: ptr to current noede
 */
avl_t *helper(avl_t *node, int *array, int left, int right)
{
	int mid, val;
	avl_t *L, *R;

	if (left > right)
		return (NULL);

	mid = (left + right) / 2;
	val = array[mid];
	node->n = val;
	L = init_node();
	R = init_node();
	L->parent = node;
	R->parent = node;
	node->left = helper(L, array, left, mid - 1);
	node->right = helper(R, array, mid + 1, right);

	return (node);
}
