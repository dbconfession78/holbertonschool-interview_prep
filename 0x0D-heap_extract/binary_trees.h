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
heap_t *get_max_node(heap_t *node_a, heap_t *node_b);
void walk_down(heap_t *walk, heap_t *to_fill, int to_fill_is_left);
int is_leaf(heap_t *node);

#endif
