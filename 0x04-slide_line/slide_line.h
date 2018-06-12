#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H
#define SLIDE_LEFT 1
#define SLIDE_RIGHT 2

int slide_line(int *line, size_t size, int direction);
int get_next(int *line, int i, size_t size);
int slide_left(int *line, size_t size);
int slide_right(int *line, size_t size);

#endif
