#ifndef SANDPILES_H
#define SANDPILES_H
#include <stdio.h>
#include <stdlib.h>
#define N 3

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
void check_piles(int grid[3][3], int overs[3][3]);
void my_print_grid(int grid[3][3]);
void set_overs(int grid[3][3], int retval[3][3]);
int is_done(int grid[3][3]);

#endif
