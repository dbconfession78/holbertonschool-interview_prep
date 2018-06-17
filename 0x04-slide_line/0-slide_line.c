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
	if (line == NULL)
		return (0);

	if (direction == SLIDE_LEFT)
		return (slide_left(line, size));
	if (direction == SLIDE_RIGHT)
		return (slide_right(line, size));
	return (0);

}


/**
 * idx_of_next_non_zero - returns idx of next non-zero in array
 * @line: array to traverse
 * @i: index to begin at
 * @size: size of the array
 * @d: direction of slide
 * Return: index of next non-zero or -1 if no non-zeros
 **/
int idx_of_next_non_zero(int *line, int i, size_t size, int d)
{
	if (d == 1)
	{
		while (i != (int) size && line[i] == 0)
			i += 1;
		return (i);
	}
	if (d == 2)
	{
		while (i != -1 && line[i] == 0)
			i -= 1;
		return (i);
	}
	return (i);
}


/**
 * slide_left - slides array left, parsing zeros and merging duplicate values
 * @line: ptr to array to slide.
 * @size: size of array
 * Return: 1 on success
 **/
int slide_left(int *line, size_t size)
{
	int mark = -1; int searching = 0; int i = 0; int ionnz;

	while (i < (int) size)
		if (line[i] == 0)
		{
			if (searching == 0)
			{
				searching = 1;
				if (mark == -1)
					mark = i;
			}
			i++;
		}
		else if (searching == 1)
		{
			ionnz = idx_of_next_non_zero(line, i + 1, size, 1); searching = 0;
			if ((ionnz < ((int) size)) && (line[i] == line[ionnz]))
			{
				line[i] = line[i] + line[ionnz]; line[ionnz] = 0;
			}
			line[mark] = line[i]; line[i] = 0; mark++; i = ionnz;
		}
		else
		{
			if (((i < ((int) size - 1))) && ((line[i] == line[i + 1])))
			{
				line[i] = line[i] + line[i + 1]; line[i + 1] = 0; mark = i + 1;
			}
			else if ((i < ((int) size) - 1) && ((line[i + 1] == 0)))
			{
				ionnz = idx_of_next_non_zero(line, i + 1, size, 1);
				if (line[i] == line[ionnz])
				{
					line[i] = line[i] + line[ionnz]; line[ionnz] = 0; mark = i + 1;
				}
			}
			i++;
		}
	post_process(line, size, &mark, &i, 1);
	return (1);
}

/**
 * post_process - handles mark reassignment after main loop
 * @line: integer array
 * @size: size of array
 * @mark: pointer to mark
 * @i: pointer to i
 * @direction: designates if line slides left or right
 * Return: void
 */
void post_process(int *line, size_t size, int *mark, int *i, int direction)
{
	if (direction == 1)
	{
		if (*i != -1 && *i > ((int) size) - 1)
		{
			*i = size - 1;
			if ((*mark < ((int) size)) && (*mark > -1) && ((*mark != (int) size - 1)))
			{
				if (line[*mark] == 0)
				{
					line[*mark] = line[*i]; line[*i] = 0;
				}
			}
		}
	}
	if (direction == 2)
	{
		if (*i != (int) size && *i < 0)
		{
			*i = 0;
			if (*mark < (int) size && *mark > -1 && *mark != 0)
			{
				if (line[*mark] == 0)
				{
					line[*mark] = line[*i];
					line[*i] = 0;
				}
			}
		}
	}
}


/**
 * slide_right - slides array right, parsing zeros and merging duplicate values
 * @line: ptr to array to slide.
 * @size: size of array
 * Return: 1 on success
 **/
int slide_right(int *line, size_t size)
{
	int searching = 0; int mark = (int) size; int i = ((int) size) - 1; int ionnz;

	while (i > -1)
		if (line[i] == 0)
		{
			if (searching == 0)
			{
				searching = 1;
				if (mark == (int) size)
					mark = i;
			}
			i--;
		}
		else if (searching == 1)
		{
			ionnz = idx_of_next_non_zero(line, i - 1, size, 2); searching = 0;
			if (ionnz > -1 && line[i] == line[ionnz])
			{
				line[i] = line[i] + line[ionnz]; line[ionnz] = 0;
			}
			line[mark] = line[i]; line[i] = 0; mark--; i = ionnz;
		}
		else
		{
			if ((i > 0) && (line[i] == line[i - 1]))
			{
				line[i] = line[i] + line[i - 1]; line[i - 1] = 0; mark = i - 1;
			}
			else if ((i > 0) && (line[i - 1] == 0))
			{
				ionnz = idx_of_next_non_zero(line, i - 1, size, 2);
				if (line[i] == line[ionnz])
				{
					line[i] = line[i] + line[ionnz]; line[ionnz] = 0; mark = i - 1;
				}
			}
			i--;
		}
	post_process(line, size, &mark, &i, 2);
	return (1);
}
