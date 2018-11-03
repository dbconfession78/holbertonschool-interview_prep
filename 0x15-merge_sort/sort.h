#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

void merge_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void helper(size_t start, size_t size, int *array, int *dupe);
void merge(size_t start, size_t mid, size_t size, int *array, int *dupe);

#endif
