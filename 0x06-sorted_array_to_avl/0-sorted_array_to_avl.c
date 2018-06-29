#include <stdio.h>
#include<stdlib.h>
#include "binary_trees.h"

/*
 *void print_tree(avl_t *root)
 *{
 *	if (root == NULL)
 *		return;
 *	print_tree(root->left);
 *	printf("%d\n", root->n);
 *	print_tree(root->right);
 *}
*/

/**
 * sorted_array_to_avl - creates an avl tree from a sorted array
 * @array: array to convert into an avl tree
 * @size: length of array
 * Return: the completed avl tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *tree;

	tree = malloc(sizeof(avl_t));
	tree = helper(tree, array, 0, size - 1, size);
	return (tree);
}


/**
 * helper - recursive helper function for sorted_array_to_avl
 * @T: current node
 * @array: the source array
 * @left: ptr to the left node of 'T'
 * @right: ptr to the right node of 'T'
 * @size: length of array
 * Return: new node
 */
avl_t *helper(avl_t *T, int *array, int left, int right, size_t size)
{
	int mid;
	avl_t *new;

	if (right < left)
		return (NULL);

	new =  malloc(sizeof(avl_t));
	if (new == NULL)
		return (NULL);

	mid = (right + left) / 2;
	new->n = array[mid];

	new->left = helper(T, array, left, mid - 1, size);
	new->right = helper(T, array, mid + 1, right, size);
	return (new);
}
