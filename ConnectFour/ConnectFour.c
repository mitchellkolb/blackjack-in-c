#include "ConnetFour.h"

void init_board(Cell board[][7],
	int num_rows,
	int num_cols)
{
	int row_index = 0, col_index = 0;

	for (; row_index < num_rows; ++row_index)
	{
		for (col_index = 0; col_index < num_cols;
			++col_index)
		{
			board[row_index][col_index].token_color = '\0';
			board[row_index][col_index].occ = EMPTY;
			board[row_index][col_index].location.row = row_index;
			board[row_index][col_index].location.col =  col_index;
		}	

	}
}

// we'll finish this function 4/8
void print_board(Cell board[][7],
	int num_rows,
	int num_cols)
{
	int row_index = 0, col_index = 0;

	printf("%3d", 0);
	for (; row_index < num_rows; ++row_index)
	{
		for (col_index = 0; col_index < num_cols;
			++col_index)
		{
	
		}

	}
}