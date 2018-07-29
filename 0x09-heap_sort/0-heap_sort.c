#include "sort.h"


/**
 * heap_sort - uses heap-sort algo to sort an array of ints in ascending order
 * @array: the array to sort
 * @size: the size of the array
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
	int end = size - 1;

	heapify(array, size);
	while (end > 0)
	{
		swap(array, end, 0);
		my_print_array(array, size);
		end--;
		sift_down(array, 0, end, size);
	}
}


/**
 * swap - swaps values of two indexes in an array
 * @a: array whose index values are swapped
 * @i: index of the first value
 * @j: index of the second value
 * @size: length of array
 * Return: void
 */
void swap(int *a, int i, int j)
{
	int tmp = a[j];

	a[j] = a[i];
	a[i] = tmp;
}


/**
 * heapify - converts unordered array into a heap-like array
 * @a: array to heapify
 * @size: length of array
 * Return: void
 */
void heapify(int *a, size_t size)
{
	int start;

	start = ((int) size - 2) / 2;
	while (start >= 0)
	{
		sift_down(a, start, size - 1, size);
		start--;
	}
}


/**
 * sift_down - reorders array while maintaing heap
 * @a: array to sift
 * @start: root index
 * @end: index of last element in heap
 * @size: length of array
 * Return: void
 */
void sift_down(int *a, int start, size_t end, size_t size)
{
	int root, child, child_val, next_val, root_val;

	root = start;
	while ((root * 2) + 1 <= (int) end)
	{
		child = (root * 2) + 1;
		child_val = a[child];
		next_val = a[child + 1];
		root_val = a[root];

		if (child + 1 <= (int) end && child_val < next_val)
			child++;
		if (root_val < child_val)
		{
			swap(a, root, child);
			my_print_array(a, size);
			root = child;
		}
		else
			return;
	}
}
