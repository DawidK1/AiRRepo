#ifndef GAME
#define GAME

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "array.h"

void check_board(cell** board, int col, int row);
void change_status(cell** board, int col, int row);
void file_open(cell*** board, int* col, int* row, char* name);
void file_save(cell** board, int col, int row, char* name);
void rand_data(cell** board, int col, int row);

#endif
