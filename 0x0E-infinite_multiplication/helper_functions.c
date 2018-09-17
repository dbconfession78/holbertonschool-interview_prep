#include "holberton.h"

/**
 * is_all_digits - checks to see if all characters in a string are digits
 * @s: string to check
 * Return: 1 if all chars are digits, 0 otherwise
 */
int is_all_digits(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] < 48 || s[i] > 57)
			return (0);
		i++;
	}
	return (1);
}

/**
 * build_row - multiplies 'a' with 'b[i]'
 * @size: length of buffer
 * @row_idx: i in b[i], index of current sum in progress
 * @a: first string of digits
 * @b: second string of digits
 * @len_a: length of first string
 * @len_b: length of second string
 * Return: string representation of product of 'a' and 'b[i]'
 */
char *build_row(int size, int row_idx, char *a, char *b, int len_a, int len_b)
{
	char *row = malloc(sizeof(char) * (size + 1));
	int column_index = row_idx;
	char char_b = b[len_b - 1];
	int int_b = char_to_int(char_b);
	int index_a = len_a - 1;
	int carry = 0;

	pad_zeros(row, row_idx);
	while (index_a >= 0)
	{
		char char_a = a[index_a];
		int int_a = char_to_int(char_a);
		int product = ((int_a * int_b) + carry);

		carry = 0;
		if (product > 9)
		{
			carry = product / 10;
			product %= 10;
		}
		row[column_index] = int_to_char(product);
		column_index++;
		index_a--;
	}
	if (carry > 0)
	{
		row[column_index] = int_to_char(carry);
		column_index++;
	}
	row[column_index] = '\0';
	return (row);
}

/**
 * print_string - prints a string to standard output
 * @s: string to print
 * Return: void
 */
void print_string(char *s)
{
	int i;
	int is_printing = 0;

	for (i = 0; i < get_string_length(s); i++)
	{
		if (!is_printing && s[i] != '0')
			is_printing = 1;
		if (is_printing)
			_putchar(s[i]);
	}
	if (!is_printing)
		_putchar('0');
	_putchar('\n');
}

/**
 * free_rows - frees each strings in an array of strings
 * @rows: array containing strings to be freed
 * @row_count: number of strings to be free
 * Return: void
 */
void free_rows(char **rows, int row_count)
{
	int i = 0;

	while (i < row_count)
	{
		free(*rows);
		rows++;
		i++;
	}
}

/**
 * get_string_length - gets the length of a character array
 * @s: character array to count
 * Return: length of character array
 */
int get_string_length(char *s)
{
	int length = 0;

	while (1 == 1)
	{
		if (s[length] == '\0')
			break;
		length++;
	}
	return (length);
}
