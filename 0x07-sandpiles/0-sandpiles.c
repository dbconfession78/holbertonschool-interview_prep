#include "sandpiles.h"

/**
 * sandpiles_sum - computes the sum of two sandpiles
 * @grid1: first sandpile
 * @grid2: second sandpile
 * Return: void
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;
	int done = 0;
	int overs[3][3];
	int flag = 0;

	if (sum_grid(grid1) > 0 && sum_grid(grid2) > 0)
		flag = 1;

	for (i = 0; i < 3; i++)
		for (j = 0;  j < 3; j++)
			grid1[i][j] = grid1[i][j] + grid2[i][j];
	if (flag == 1)
		my_print_grid(grid1);
	while (done == 0)
	{
		set_overs(grid1, overs);
		check_piles(grid1, &done, overs);
	}
}

/**
 * check_piles - checks and spills sandpiles where necessary
 * @grid: the sandpile to check
 * @done: ptr to variable indicating if pile is stable
 * @overs: map of source grid indicating which values have overflow
 * Return: void
 */

void check_piles(int grid[3][3], int *done, int overs[3][3])
{
	int i, j;

	*done = 1;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
		{
			if (overs[i][j] == 1)
			{
				grid[i][j] -= 4;
				if (grid[i][j] > 3)
					*done = 0;
				if (i > 0)
				{
					grid[i - 1][j] += 1;
					if (grid[i - 1][j] > 3)
						*done = 0;
				}
				if (i < 2)
				{
					grid[i + 1][j] += 1;
					if (grid[i + 1][j] > 3)
						*done = 0;
				}
				if (j > 0)
				{
					grid[i][j - 1] += 1;
					if (grid[i][j - 1] > 3)
						*done = 0;
				}
				if (j < 2)
				{
					grid[i][j + 1] += 1;
					if (grid[i][j + 1] > 3)
						*done = 0;
				}
			}
		}
	if (*done == 0)
		my_print_grid(grid);
}

/**
 * set_overs - marks grid values that are over 3
 * @grid: the grid to check values in
 * @retval: the grid that maps values over 3
 * Return: 1 (over 3) and 0 (under 4) map of source grid
 */
void set_overs(int grid[3][3], int retval[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			retval[i][j] = 0;
	for (i = 0; i < 3; i++)
		for (j = 0;  j < 3; j++)
			if (grid[i][j] > 3)
				retval[i][j] = 1;
}


/**
 * my_print_grid - p a 3x3 grid
 * @grid: the grid to print
 * Return: void
 */
void my_print_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%d", grid[i][j]);
			if (j < 2)
				printf(" ");
			else
				printf("\n");
		}
	}
}

/**
 * sum_grid - adds all values in a grid
 * @grid: the grid to sum
 * Return: the int sum of the input grid
 */
int sum_grid(int grid[3][3])
{
	int i, j;
	int retval = 0;

	for (i = 0; i < 3; i++)
		for (j = 0;  j < 3; j++)
			retval += grid[i][j];
	return (retval);
}
