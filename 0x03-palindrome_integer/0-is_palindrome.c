#include <stdio.h>
#include <stdlib.h>
#include "palindrome.h"

/**
 * is_palindrome - checks to see if a number is a palindrome
 * @n: the number to check
 * Return: 1 if n is a palindrome; 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long l, r, div, _len;

	div = 1;
	_len = get_length(n);
	div = init_divisor(_len);

	while (n > 0)
	{
		l = n / div;
		r = n % 10;
		if (l != r)
			return (0);

		n %= div;
		n /= 10;
		div /= 100;
	}
	return (1);
}

/**
 * init_divisor - creates a divisor of 10^(n-1)
 * @n: number of zeros+1 in final devisor
 * Return: divisor
 */
unsigned long init_divisor(unsigned long n)
{
	unsigned long retval;
	unsigned long i;

	retval = 1;
	i = 0;
	if (n == 0)
		return (retval);

	while (i < n - 1)
	{
		retval *= 10;
		i++;
	}
	return (retval);
}

/**
 * get_length - returns the number of places in a given unsigned long integer
 * @n: the number to count places in
 * Return: an unsigned long into representing the number of places in the input
 */
unsigned long get_length(unsigned long n)
{
	unsigned long retval, i;

	retval = i = 0;
	while (n)
	{
		n /= 10;
		retval += 1;
	}
	return (retval);
}
