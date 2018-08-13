#ifndef SEARCH_ALOGS_H
#define SEARCH_ALOGS_H
#include <stdio.h>
#include <stdlib.h>

int advanced_binary(int *array, size_t size, int value);
int helper(int *array, int value, size_t l_ptr, size_t r_ptr, int retval);
void print_range(int *array, size_t l_ptr, size_t r_ptr);

#endif
