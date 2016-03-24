#ifndef ARRAY
#define ARRAY
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cell{
	int status;
	int surround;
}cell;


cell** create(int col, int row);
void resize(cell*** tab, int old_col, int old_row, int new_col, int new_row);
void insert(cell** tab, int row, int col, cell new_element);
int at(cell** tab, int col, int row);
void show_array(cell** tab, int col, int row);
void delet(cell*** tab, int row);
#endif
