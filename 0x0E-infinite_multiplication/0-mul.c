#include "holberton.h"


/**
 * main - application entry point
 * @argc: argument count
 * @argv: argument array
 * Return: 0 on application completion
 */
int main(int argc, char **argv)
{
	if (argc != 3 || !(is_all_digits(argv[1]) || !(is_all_digits(argv[2]))))
	{
		printf("Error\n");
		exit(98);
	}
	
	multiply(argv[1], argv[2]);

	return (0);
}


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
 * multiply - takes two strings of any length and outputs their product
 * @a: first string of digits
 * @b: second string of digits
 * Return: void
 */
void multiply(char *a, char *b)
{
	int size, i, x, carry, max_last_index;
	char *row, *final_product_string;
	int buffer_size = 256;
	int column_index, row_index = 0;
	int len_a = get_string_length(a);
	int len_b = get_string_length(b);
	char **rows = malloc(sizeof(char *) * (len_b));

	while (len_b > 0)
	{
		char char_b;
		int int_b, index_a, carry;

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

	for (i = 0; i < get_string_length(s); i++)
		_putchar(s[i]);
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

/**
 * has_negative_product - determines if 2 digit strings has a negatove product
 * @first_char_of_a: first character of first string
 * @first_char_of_b: first character of second string
 * Return: 1 if product is negative, 0 otherwise
 */
int has_negative_product(char first_char_of_a, char first_char_of_b)
{
	if ((first_char_of_a == '-' && first_char_of_b != '-') ||
		(first_char_of_a != '-' && first_char_of_b == '-'))
		return (1);

	if ((first_char_of_a != '-' && first_char_of_b != '-') ||
		(first_char_of_a == '-' && first_char_of_b == '-'))
		return (0);
	return (0);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
