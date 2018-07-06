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
	int overs[3][3];

	/* add sandpiles and put result in grid1 */
	for (i = 0; i < 3; i++)
		for (j = 0;  j < 3; j++)
			grid1[i][j] = grid1[i][j] + grid2[i][j];

	while (is_done(grid1) == 0)
	{
		my_print_grid(grid1);
		set_overs(grid1, overs);
		check_piles(grid1, overs);
	}
}

/**
 * is_done - checks stability of sandpile grid
 * @grid: the sandpile to check
 * Return: 1 if stable, 0 if unstable
 */
int is_done(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0;  j < 3; j++)
			if (grid[i][j] > 3)
				return (0);
	return (1);
}

/**
 * check_piles - checks and spills sandpiles where necessary
 * @grid: the sandpile to check
 * @overs: map of source grid indicating which values have overflow
 * Return: void
 */
void check_piles(int grid[3][3], int overs[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (overs[i][j] == 1)
			{
				grid[i][j] -= 4;
				if (i > 0)
					grid[i - 1][j] += 1;
				if (i < 2)
					grid[i + 1][j] += 1;
				if (j > 0)
					grid[i][j - 1] += 1;
				if (j < 2)
					grid[i][j + 1] += 1;
			}
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
