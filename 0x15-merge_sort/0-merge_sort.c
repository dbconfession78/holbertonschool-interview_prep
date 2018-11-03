#include "sort.h"

/**
 * merge_sort - sorts an int array using the merge sort algorithm
 * @array: pointer to the first int in the array to sort
 * @size: length of array
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	int *dupe, i;

	if (array == NULL || size < 2)
		return;

	dupe = malloc(sizeof(int) * size);
	if (dupe == NULL)
		return;

	for (i = 0; i < (int) size; i++)
		dupe[i] = array[i];

	helper(0, size, array, dupe);
	free(dupe);
}

/**
 * merge - orders members of subarrays and merges them together
 * @start: index of first element in subarray
 * @mid: index of center element in subarray
 * @size: index of last element in subarray
 * @array: the array that will end up sorted
 * @dupe: the array to draw elements from
 * Return: void
 */
void merge(size_t start, size_t mid, size_t size, int *array, int *dupe)
{
	size_t i, j, k;

	printf("Merging...\n[left]: ");
	print_array(dupe + start, mid - start);
	printf("[right]: ");
	print_array(dupe + mid, size - mid);
	i = start;
	j = mid;
	for (k = start; k < size; k++)
	{
		if (i < mid && (j >= size || dupe[i] <= dupe[j]))
			array[k] = dupe[i++];
		else
			array[k] = dupe[j++];
	}
	printf("[Done]: ");
	print_array(array + start, size - start);
}

/**
 * helper - helper function to recursively merge
 * @start: index of first element in array
 * @size: length of array
 * @array: pointer to the first int in the array to sort
 * @dupe: pointer to first int in copied array
 * Return: void
 */
void helper(size_t start, size_t size, int *array, int *dupe)
{
	size_t mid;

	if (size - start >= 2)
	{
		mid = (start + size) / 2;
		helper(start, mid, array, dupe);
		helper(mid, size, array, dupe);
		merge(start, mid, size, array, dupe);
		for (mid = start; mid < size; mid++)
			dupe[mid] = array[mid];
	}
}
