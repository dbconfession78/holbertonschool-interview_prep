#include "holberton.h"
#include "helper_functions.c"
#include "string_functions.c"
#include "char_functions.c"

/**
 * main - application entry point
 * @argc: argument count
 * @argv: argument array
 * Return: 0 on application completion
 */
int main(int argc, char **argv)
{
	if (argc != 3 || is_all_digits(argv[1]) == 0 || is_all_digits(argv[2]) == 0)
		_exit(98);

	multiply(argv[1], argv[2]);
	return (0);
}
