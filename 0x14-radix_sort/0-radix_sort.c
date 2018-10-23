#include "sort.h"


/**
 * radix_sort - sorts an array of integers in ascending order using Radix sort
 * @array: the array to sort
 * @size: size of array
 * Return: void
 */
void radix_sort(int *array, size_t size)
{

	int int_size = (int) size;
	int bucket[10][5], buck[10];
	int i, j, k, l, num, div, large, passes;

	div = 1;
	num = 0;
	large = array[0];

	for (i = 0; i < int_size; i++)
	{
		if (array[i] > large)
			large = array[i];

		while (large > 0)
		{
			num++;
			large = large / 10;
		}

		for (passes = 0; passes < num; passes++)
		{
			for (k = 0; k < 10; k++)
				buck[k] = 0;
			for (i = 0; i < int_size ; i++)
			{
				l = ((array[i] / div) % 10);
				bucket[l][buck[l]++] = array[i];
			}

			i = 0;
			for (k = 0; k < 10; k++)
				for (j = 0; j < buck[k]; j++)
					array[i++] = bucket[k][j];
			print_array(array, int_size);
			div *= 10;
		}
	}
}
