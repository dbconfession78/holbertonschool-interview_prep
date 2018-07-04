#include "sandpiles.h"

void check_piles(int grid[3][3], int *done)
{
	int i, j;

	*done = 1;
	for (i = 0; i < 3; i++)
	{
		for (j=0; j < 3; j++)
		{ 
			if (grid[i][j] > 3)
			{
				grid[i][j] -= 4;
				if (i > 0)
				{
					grid[i - 1][j] += 1;
					if (grid[i-1][j] > 3)
						*done = 0;
				}

				if (i < 2)
				{
					grid[i + 1][j] += 1;
					if (grid[i+1][j] > 3)
						*done = 0;
				}
				
				if (j > 0)
				{
					grid[i][j - 1] += 1;
					if (grid[i][j-1] > 3)
						*done = 0;
				}

				if (j < 2)
				{
					grid[i][j + 1] += 1;
					if (grid[i][j+1] > 3)
						*done = 0;
				}
			}
		}
	}
}

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

	for (i = 0; i < 3; i++)
		for (j = 0;  j < 3; j++)
            grid1[i][j] = grid1[i][j] + grid2[i][j];

	while (done == 0)
	{
		print_grid(grid1);
		check_piles(grid1, &done);
	}
}

/**
 * print_grid - p a 3x3 grid
 * @grid: the grid to print
 * @grid2: second sandpile
 * Return: void
 */  
void print_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");
	for (i=0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%d", grid[i][j]);
			if (j < 2)
				printf(" ");
			else printf("\n");
		}
	}
}
