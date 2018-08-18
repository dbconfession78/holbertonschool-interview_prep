#include "binary_trees.h"


/**
 * binary_tree_node - creates a binary tree node
 * @parent: pointer to the parent node of the node to create
 * @value: value to put in the new node
 * Return: pointer to the new node or 'NULL' on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *retval = malloc(sizeof(binary_tree_t));

	if (retval == NULL)
		return (NULL);

	retval->n = value;
	retval->parent = parent;
	retval->left = NULL;
	retval->right = NULL;

	return (retval);
}
