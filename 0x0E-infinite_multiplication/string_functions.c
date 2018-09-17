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
	char *retval = NULL, *temp_string;
	int len_a, len_b, total_length, i, j, temp, carry, temp_len;

	len_a = get_string_length(a);
	len_b = get_string_length(b);
	total_length = len_a + len_b;
	temp_string = NULL;
/*	retval = _calloc(total_length, sizeof(char)); */
/*	retval = malloc((total_length+1) * sizeof(char)); */
	retval = malloc(4068 * sizeof(char));
	if (!retval)
		_exit(98);

	for (i = 0; i < total_length; i++)
		retval[i] = '0';
	if (len_b > len_a)
	{
		temp_string = a;
		a = b;
		b = temp_string;
		temp_len = len_a;
		len_a = len_b;
		len_b = temp_len;
	}
	carry = 0;
	for (i = len_b - 1; i >= 0; i--)
	{
		for (j = len_a - 1; j >= 0; j--)
		{
			temp = (b[i] - '0') * (a[j] - '0');
			temp += (retval[(i + j + 1)] - '0') + carry;
			carry = temp / 10;
			retval[(i + j + 1)] = (temp % 10) + '0';
		}
		if (carry != 0)
			retval[i] = carry + '0';
		carry = 0;
	}
	print_string(retval);
	free(retval);
}


/**
 * _calloc- allocates memory + populates elems of char array with supplied char
 * @length: number of elements to allocate memory for
 * @element_size: amount of memory to allocate for each element
 * Return: the allocated array
 */
char *_calloc(int length, int element_size)
{
	int i;
	char *array = NULL;

	array = malloc(length * element_size);
	if (!array)
		_exit(98);

	for (i = 0; i < length; i++)
		array[i] = '0';
	return (array);

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
	char *retval;
/*	char *retval = malloc(sizeof(char) * max_last_index + 2); */
/* 	total_length = len_a + len_b; */
/* 	retval = malloc(total_length + 2 * sizeof(char)); */
	retval = NULL;
	if (retval == NULL)
	{
		print_string("Error");
		exit(98);
	}

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
		retval[i] = int_to_char(sum);
		if (i == max_last_index)
		{
			retval[i + 1] = '\0';
		}
/*		i++; */
		column_index++;
	}
	return (retval);
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
