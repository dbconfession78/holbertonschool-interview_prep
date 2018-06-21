#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "menger.h"

/**
 * menger - creates one 2d face of a 3d menger sponge.
 * @level: level of fractal recusrion
 * Return: void
 */
void menger(int level)
{
	int p, i;
	char **sponge;

	if (level < 0)
		return;
	if (level == 0)
		printf("%c\n", '#');
	else if (level == 1)
		printf("###\n# #\n###\n");
	else
	{
		p = pow(3, level);
		sponge = malloc(sizeof(char *) * p);
		if (sponge == NULL)
			return;

		for (i = 0; i < p; i++)
			sponge[i] = malloc(sizeof(char) * p);

		for (i = 0; i < 3; i++)
			sponge[0][i] = '#';
		sponge[1][0] = '#';
		sponge[1][1] = ' ';
		sponge[1][2] = '#';
		for (i = 0; i < 3; i++)
			sponge[2][i] = '#';

		if (level == 1)
			print_sponge(sponge, 3);
		else
			recurse(sponge, 0, level, 3, 3);
	print_sponge(sponge, p);
	for (i=0; i < p; i++)
		free(sponge[i]);
	free(sponge);
	
	}
}

/**
 * recurse - increases sponge to level size
 * @sponge: ptr to char array representing current sponge
 * @idx: current level of sponge
 * @level: size of 2d menger sponge face
 * @height: current height of sponge
 * @nxt: the index in each row and column at which the sponge will expand
 * Return: ptr to current char array representing 2d menger sponge face
 */
char **recurse(char **sponge, int idx, int level, int height, int nxt)
{
	int i, j, k, div, mid_start, mid_end, limit;

	if (idx == level - 1)
		return (sponge);

/* expand width by 2 * current width  */
	for (i = 0; i < height; i++)
		for (j = 0, k = nxt; j < nxt * 2; j++, k++)
			sponge[i][k] = sponge[i][j];
	limit = height;

/* expand height by 2* current height */
	for (i = 0; i < limit * 2; i++, height++)
	{
		for (j = 0; sponge[i][j] != '\0'; j++)
		{
			sponge[height][j] = sponge[i][j];
		}
/*		strcpy(sponge[height], sponge[i]); */
	}

/* remove center */
	div = height / 3;
	mid_start = div;
	mid_end = (div * 2) - 1;
	for (i = 0; i < height; i++)
		if (i >= mid_start && i <= mid_end)
			for (j = 0; j < height; j++)
				if (j >= mid_start && j <= mid_end)
					sponge[i][j] = ' ';
	nxt = k;
	return (recurse(sponge, idx + 1, level, height, nxt));
}
/**
 * print_sponge - prints a 2d menger sponge face  to the standard output
 * @sponge: pointer to char array representing 2d menger sponge face to print
 * @height: height of 2d menger sponge face being printed
 * Return: void
 */
void print_sponge(char **sponge, int height)
{
	int i;

	for (i = 0; i < height; i++)
		printf("%s\n", sponge[i]);
}
