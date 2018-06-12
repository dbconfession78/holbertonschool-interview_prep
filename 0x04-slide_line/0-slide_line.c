#include <stdio.h>
#include <stdlib.h>
#include "slide_line.h"

/**
 * slide_line - Given an array of integers, we want to be able to slide & merge
 *              it to the left or to the right. Identical numbers, if they are
 *              contiguous or separated by zeros, should be merged.
 * @line: points to an array of integers.
 * @size: number of elements in 'line'.
 * @direction: direction line must be slide in (SLIDE_LEFT or SLIDE_RIGHT)
 * Return: 1 on success of merge; 0 otherwise
 */
int slide_line(int *line, size_t size, int direction)
{
	if (direction == SLIDE_LEFT)
		return (slide_left(line, size));
	if (direction == SLIDE_RIGHT)
		return (slide_right(line, size));
	return (0);

}


/**
 * get_idx_of_next_non_zero - returns idx of next non-zero in array
 * @line: array to traverse
 * @i: index to begin at
 * @size: size of the array
 * Return: index of next non-zero or -1 if no non-zeros
 **/
int get_idx_of_next_non_zero(int *line, int i, size_t size)
{
	while (i < (int) size)
	{
		if (line[i] != 0)
			return (i);
		i++;
	}
	return (-1);
}


/**
 * merge - shifts array right and adds dupe ints while parsing zeros
 * @mark: ptr to next zero to replace
 * @i: ptr to current index
 * @line: ptr the line to merge
 * @size: size of the array
 * @next_idx: ptr to idx of next non-zero
 * Return: void
 **/
void merge(int *mark, int *i, int *line, int *next_idx)
{
	if (*next_idx > -1 && line[*next_idx] == line[*i])
	{
		if (*mark != -1)
		{
			line[*mark] = line[*i] + line[*next_idx];
			line[*i] = 0;
			*mark = *mark + 1;
		} else
		{
			line[*i] = line[*i] + line[*next_idx];
			*mark = *i + 1;
		}
		line[*next_idx] = 0;
		*i = *next_idx;
	}
}

/**
 * slide_left - slides array left, parsing zeros and merging duplicate values
 * @line: ptr to array to slide.
 * @size: size of array
 * Return: 1 on success
 **/
int slide_left(int *line, size_t size)
{
	int searching, i, mark, next_idx;

	searching = 0; mark = -1;
	for (i = 0; i < (int) size; i++)
	{
		if (line[i] == 0)
		{
			if (searching == 0)
			{
				searching = 1;
				if (mark == -1)
					mark = i;
			}
		} else if (searching == 1)
		{
			searching = 0;
			if (i < (int) size - 1)
			{
				next_idx =  get_idx_of_next_non_zero(line, i + 1, size);
				merge(&mark, &i, line, &next_idx);
			} else
				line[mark] = line[i];
				line[i] = 0;
		} else
			if (i < (int) size - 1)
			{
				next_idx =  get_idx_of_next_non_zero(line, i + 1, size);
				merge(&mark, &i, line, &next_idx);
			}
	}
	return (1);
}

/**
 * slide_right - slides array right, parsing zeros and merging duplicate values
 * @line: ptr to array to slide.
 * @size: size of array
 * Return: 1 on success
 **/
int slide_right(int *line, size_t size)
{
	int searching, i, mark;

	searching = 0; mark = size;
	for (i = (int) size - 1; i > 0; i--)
		if (line[i] == 0)
		{
			if (searching == 0)
			{
				searching = 1;
				if (mark == (int) size)
					mark = i;
			}
		}
		else if (searching == 1)
		{
			searching = 0;
			if (i > 0 && (line[i] == line[i - 1]))
			{
				line[mark] = line[i] + line[i - 1]; line[i - 1] = 0;
			}
			else
				line[mark] = line[i];
			line[i] = 0; mark--;
		} else
			if (i > 0 && (line[i] == line[i - 1]))
			{
				if (mark != (int) size)
				{
					line[mark] = line[i] + line[i - 1]; line[i] = 0; mark--;
				} else
				{
					line[i] = line[i] + line[i - 1]; mark = i - 1;
				}
				line[i - 1] = 0;
			}
	if (mark != (int) size)
	{
		line[mark] = line[i]; line[i] = 0;
	}
	return (1);
}
