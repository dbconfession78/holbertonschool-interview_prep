#ifndef MENGER_H
#define MENGER_H

void menger(int level);
char **recurse(char **sponge, int idx, int level, int height, int nxt);
void print_sponge(char **sponge, int heoght);

#endif
