#include "holberton.h"

/**
 * char_to_int - converts a digit char to it's actual integer representation
 * @c: the character to convert
 * Return: integer representation of digit character
 */
int char_to_int(char c)
{
	if (c < 48 || c > 57)
	{
		printf("Error\n");
		exit(98);
	}
	return (c - 48);
}

/**
 * int_to_char - converts a single digit integer to it's char representation
 * @n: integer to convert
 * Return: character representation of single digit integer
 */
char int_to_char(int n)
{
	return ((char) (n + 48));
}
