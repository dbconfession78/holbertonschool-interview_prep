#include "holberton.h"

/**
 * sum_column - adds digit representation of char string[i][j]
 * @rows: string array containing column to sum
 * @column_index: index of column to sum
 * @num_rows: length of string array
 * Return: integer representation of summed strings
 */
int sum_column(char **rows, int column_index, int num_rows)
{
	int i = 0;
	int sum = 0;

	while (i < num_rows)
	{
		char *row = rows[i];
		int row_length = get_string_length(row);
		int n = 0;

		if (row_length > column_index)
			n = char_to_int(row[(row_length - 1) - column_index]);
		sum += n;
		i++;
	}
	return (sum);
}

/**
 * multiply - takes two strings of any length and outputs their product
 * @a: first string of digits
 * @b: second string of digits
 * Return: void
 */
void multiply(char *a, char *b)
{
	int size, max_last_index;
	char *row, *final_product_string;
	int buffer_size = 256;
	int row_index = 0;
	int len_a = get_string_length(a);
	int len_b = get_string_length(b);
	char **rows = malloc(sizeof(char *) * (len_b));

	while (len_b > 0)
	{
		size = buffer_size + row_index;
		row  = build_row(size, row_index, a, b, len_a, len_b);
		reverse_string(row);
		rows[row_index] = row;
		row_index++, len_b--;
	}
	max_last_index = get_string_length(rows[row_index - 1]) - 1;
	final_product_string = sum_strings(max_last_index, rows, row_index);
	reverse_string(final_product_string);
	print_string(final_product_string);
	free_rows(rows, row_index);
	free(rows);
	free(final_product_string);
}


/**
 * sum_strings - sums digit representation of x character arrays
 * @max_last_index: last index of longest string
 * @rows: array of strings
 * @last_row_index: index of last string in array of strings
 * Return: string representation of sum
 */
char *sum_strings(int max_last_index, char **rows, int last_row_index)
{
	int i, column_index, carry;
	char *final_product_string = malloc(sizeof(char) * max_last_index + 2);

	i = column_index = carry = 0;
	while (column_index <= max_last_index)
	{
		int sum = sum_column(rows, column_index, last_row_index) + carry;

		carry = 0;
		if (sum > 9)
		{
			carry = sum / 10;
			sum %= 10;
		}
		final_product_string[i] = int_to_char(sum);
		if (i == max_last_index)
		{
			final_product_string[i + 1] = '\0';
		}
		i++;
		column_index++;
	}
	return (final_product_string);
}

/**
 * pad_zeros - adds number of zeros to string equal to the row minus 1
 * @row: string to pad
 * @last_index: last index of row
 * Return void
 */
void pad_zeros(char *row, int last_index)
{
	int i = 0;

	while (i < last_index)
	{
		row[i] = '0';
		i++;
	}
}

/**
 * reverse_string - reverses the order of characters in a character array
 * @s: character array  to reverse
 * Return: void
 */
void reverse_string(char *s)
{
	int x = 0;
	int i = get_string_length(s) - 1;

	while (x <= i)
	{
		char temp = s[x];

		s[x] = s[i];
		s[i] = temp;
		x++;
		i--;
	}
}
