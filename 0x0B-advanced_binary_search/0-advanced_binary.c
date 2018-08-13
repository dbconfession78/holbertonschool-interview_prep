#include "search_algos.h"

/**
 * advanced_binary - returns the first index where th value is located
 * @array: pointer to the first element of the array to search in
 * @size: number of elemnts in 'array'
 * @value: value to search for
 * Return: index where 'value' is located
 */
int advanced_binary(int *array, size_t size, int value)
{
	size_t l_ptr = 0;
	size_t r_ptr = size - 1;
	int retval = -1;

	return (helper(array, value, l_ptr, r_ptr, retval));

}


/**
 * helper - recursively searches for first index corresponding to 'value'
 * @array: pointer to the first element of the array to search in
 * @value: value to search for
 * @l_ptr: start index of range to search
 * @r_ptr: end index of range to search
 * @retval: leftmost index where 'value' was last found
 * Return: last index where 'value' is located
 */
int helper(int *array, int value, size_t l_ptr, size_t r_ptr, int retval)
{
	size_t m;
	int m_val;

	if (l_ptr == r_ptr)
	{
		if (array[l_ptr] != array[l_ptr + 1])
		{
			printf("Searching in array: ");
			print_range(array, l_ptr, l_ptr);
		}
		if (array[l_ptr] == value)
			retval = l_ptr;
		return (retval);
	}
	printf("Searching in array: ");
	print_range(array, l_ptr, r_ptr);

	m = (l_ptr + r_ptr) / 2;
	m_val = array[m];
	if (m_val == value)
	{
		retval = m;
		r_ptr = m;
	}
	else if (m_val < value)
		l_ptr = m + 1;
	else
		r_ptr = m - 1;
	return (helper(array, value, l_ptr, r_ptr, retval));
}

/**
 * print_range - prints elements of array between 'l_ptr' and 'r_ptr'
 * @array: pointer to the first element of the array to print range of
 * @l_ptr: start index of range to print
 * @r_ptr: end index of range to print
 * Return: void
 */

void print_range(int *array, size_t l_ptr, size_t r_ptr)
{
	while (l_ptr < r_ptr)
	{
		printf("%d, ", array[l_ptr]);
		l_ptr++;
	}
	printf("%d\n", array[l_ptr]);

}
