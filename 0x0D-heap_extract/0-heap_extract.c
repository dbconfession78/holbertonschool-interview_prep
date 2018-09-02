#include "binary_trees.h"

int heap_extract(heap_t **root)
{
	
	return (0);
}

/**
 * get_next_level_order_node - 
 * @root: pointer to starting heap_t node
 * @node_index: level order index of node value to get
 * Return: int value stored at target node
 */
int get_next_level_order_node(heap_t *root, int node_index)
{
	int i, top_idx, row_len, done;
	heap_t *top, *next_row[MAX], *curr_row[MAX];

	top_idx = -1;
	done = 0;
	for (i = 0; i < MAX; i++)
	{
		curr_row[i] = NULL;
		next_row[i] = NULL;
	}
	if (root == NULL)
		return (0);

	push(next_row, root, &top_idx);
	while (node_index > 0 && len(next_row) > 0)
	{
		if (done == 1)
			break;
		copy_row(next_row, curr_row);
		row_len = len(curr_row);
		reset(next_row);
		top_idx = 0;
		for (i = 0; i < row_len; i++)
		{
			top = pop(curr_row, &top_idx);
			if (top->left == NULL || top->right == NULL)
			{
				new_node->parent = top;
				done = 1;
				if (top->left == NULL)
				{
					top->left = new_node;
					break;
				}
				top->right = new_node;
				break;
			}
			if (top->left != NULL)
				push(next_row, top->left, &top_idx);
			if (top->right != NULL)
				push(next_row, top->right, &top_idx);
		}
		node_index--;
	}
	
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
