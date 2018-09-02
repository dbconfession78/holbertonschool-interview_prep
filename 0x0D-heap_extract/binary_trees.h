#ifndef BINARY_TREES_H
#define BINARY_TREES_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */

struct binary_tree_s
{
	int n;

	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s heap_t;

int heap_extract(heap_t **root);
void binary_tree_print(const binary_tree_t *tree);


binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
heap_t *heap_insert(heap_t **root, int value);
heap_t *sift_up(binary_tree_t *root);
void add_to_end(heap_t *root, heap_t *new_node);

void push(heap_t *stk[MAX], heap_t *node, int *top_idx);
heap_t *pop(heap_t *stk[MAX], int *top_idx);
void reset(heap_t *array[MAX]);
void copy_row(heap_t *source_row[MAX], heap_t *target_row[MAX]);
int len(heap_t *array[MAX]);



#endif
