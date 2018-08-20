#include "binary_trees.h"

/**
 * heap_insert - inserts a value into a Max Binary Heap
 * @root: double pointer to root node of Heap
 * @value: value store in node to be inserted
 * Return: pointer to inserted node or 'NULL' on failure
 */
heap_t *heap_insert(binary_tree_t **root, int value)
{
	binary_tree_t *new_node = binary_tree_node(NULL, value);

	if (*root == NULL)
	{
		new_node->parent = NULL;
		*root = new_node;
		return (new_node);
	}
	add_to_end(*root, new_node);
	new_node = sift_up(new_node);
	return (new_node);
}

/**
 * add_to_end - adds new heap_t node to first NULL level-order node in ree
 * @root: pointer to starting heap_t node
 * @new_node: pointer to heap_t node being added
 * Return: void
 */
void add_to_end(heap_t *root, heap_t *new_node)
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
		root = new_node;
	push(next_row, root, &top_idx);
	while (len(next_row) > 0)
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
	}
}

/**
 * sift_up - pushes heap_t node up branch until 'n' is higher than child 'n's
 * @root: pointer to heap_t node to sift up
 * Return: pointer to sifted node
 */
heap_t *sift_up(heap_t *root)
{
	heap_t *walk = root;
	int tmp;

	while (walk->parent && walk->n > walk->parent->n)
	{
		tmp = walk->n;
		walk->n = walk->parent->n;
		walk->parent->n = tmp;
		walk = walk->parent;
	}
	return (walk);
}

/**
 * len - gets array length
 * @array: array to measure
 * Return: int value of length
 */
int len(heap_t *array[MAX])
{
	int i = 0;

	while (*(array + i))
		i++;
	return (i);
}
