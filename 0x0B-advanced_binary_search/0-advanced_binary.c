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
	size_t l_ptr, r_ptr;

	l_ptr = 0;
	r_ptr = size-1;

	while (l_ptr <= r_ptr)
	{
		size_t m = (l_ptr + r_ptr) / 2;
		int m_val = array[m];
		if (m_val == value)
			return (m);
		if (m_val < value)
			l_ptr = m + 1;
		else
			r_ptr = m - 1;
	}

	return (-1);
}
