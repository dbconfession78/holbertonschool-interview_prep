#ifndef SORT_H
#define SORT_H
#include <stdio.h>
#include <stdlib.h>

void heap_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void sift_down(int *a, int start, size_t end, size_t size);
void heapify(int *a, size_t size);
void swap(int *a, int i, int j, size_t size);

#endif
