#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

void merge_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
int *build_array(int *array, int start, size_t length);
int *merge(int *array, size_t size);

#endif
