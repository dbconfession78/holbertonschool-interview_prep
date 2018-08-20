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

/**
 * push - appends pointer to heap_t node to end of stack
 * @stk: stqck to append to
 * @node: node to append
 * @top_idx: index to append at
 * Return: void
 */
void push(heap_t *stk[MAX], heap_t *node, int *top_idx)
{
	if (*top_idx == MAX - 1)
	{
		printf("\nStack is full!!");
		exit(1);
	}
	*top_idx = *top_idx + 1;
	stk[*top_idx] = node;
}

/**
 * pop - remvoes and returns heap_t node from stack
 * @stk: stqck to pop from
 * @top_idx: index to pop at
 * Return: popped heap_t node
 */
heap_t *pop(heap_t *stk[MAX], int *top_idx)
{
	heap_t *node;

	if (*top_idx == -1)
	{
		printf("\nStack is empty!!");
		exit(1);
	}
	node = stk[*top_idx];
	stk[*top_idx] = NULL;
	*top_idx = *top_idx - 1;
	return (node);
}

/**
 * reset - sets all elements in a heap_t array to NULL
 * @array heap_t array to reset
 * Return: void
 */
void reset(heap_t *array[MAX])
{
	int i;

	for (i = 0; array[i] != NULL; i++)
		array[i] = NULL;
}

/**
 * copy_row - duplicates a heap_t array
 * @source_row: array to copy from
 * @target_row: array to copy to
 * Return: void
 */
void copy_row(heap_t *source_row[MAX], heap_t *target_row[MAX])
{
	int i;

	for (i = 0; source_row[i]; i++)
		target_row[i] = source_row[i];
}
