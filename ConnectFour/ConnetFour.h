#ifndef CONNECT_FOUR_H
#define CONNECT_FOUR_H

#include <stdio.h>
#include <stdlib.h>

typedef enum occupied
{
	EMPTY, NOTEMPTY
} Occupied;

typedef struct pos
{
	int row;
	int col;
}Pos;

typedef struct cell
{
	//int row;
	//int col;
	Occupied occ;
	Pos location;
	char token_color; // red, black -- 'r', 'b'
} Cell;

void init_board(Cell board[][7], 
	int num_rows,
	int num_cols);

void print_board (Cell board[][7],
	int num_rows,
	int num_cols);

#endif // !CONNECT_FOUR_H

