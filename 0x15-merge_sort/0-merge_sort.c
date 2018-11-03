#include "sort.h"

/**
 * merge_sort - sorts an int array using the merge sort algorithm
 * @array: pointer to the first int in the array to sort
 * @size: length of array
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	merge(array, size);
}

/**
 * merge - helper function to recursively merge
 * @array: pointer to the first int in the array to sort
 * @size: length of array
 * Return: pointer to the first int in the merged array
 */
int *merge(int *array, size_t size)
{
	int *left, *right;
	int i, j, k;
	size_t l_size, r_size;

	if (size >= 2)
	{
		l_size = size / 2;
		r_size = size - l_size;
		left = merge(build_array(array, 0, l_size), l_size);
		right = merge(build_array(array, (int)size / 2, r_size), r_size);
		printf("Merging...\n[left]: ");
		print_array(left, l_size);
		printf("[right]: ");
		print_array(right, r_size);
		i = j = k = 0;
		while (i < (int) l_size && j < (int) r_size)
		{
			if (left[i] > right[j])
				array[k] = right[j++];
			else
				array[k] = left[i++];
			k++;
		}

		while (i < (int) l_size)
		{
			array[k] = left[i];
			i++;
			k++;
		}

		while (j < (int) r_size)
			array[k++] = right[j++];
		printf("[Done]: ");
		print_array(array, (size));

	}
	return (array);
}

/**
 * build_array - creates a new array from a range in the source array
 * @array: pointer to the first int in the source array
 * @start: index of the first element in the slice
 * @length: size of new array
 * Return: pointer to the first int in the new array
 */
int *build_array(int *array, int start, size_t length)
{
	int *new_array = malloc(sizeof(int) * length);
	int i;

	for (i = 0; i < (int) length; i++)
	{
		new_array[i] = *(array + start + i);
	}

	return (new_array);
}
