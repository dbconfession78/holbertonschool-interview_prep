#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void multiply(char *a, char *b);
int _putchar(char c);
int char_to_int(char c);
int get_string_length(char *s);
int has_negative_product(char first_char_of_a, char first_char_of_b);
char int_to_char(int n);
void reverse_string(char *s);
void pad_zeros(char *row, int last_index);
int sum_column(char **rows, int column_index, int num_rowss);

int is_all_digits(char *s);
void free_rows(char **rows, int row_count);
void print_string(char *s);
char *build_row(int size, int row_idx, char *a, char *b, int len_a, int len_b);
char *sum_strings(int max_last_index, char **rows, int last_row_index);

#endif
