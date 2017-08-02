#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
void display(char board[ROW][COL])
{

	for (int i = 0; i < ROW; i++)
	{
	/*	for (int j = 0; j < COL; j++)
		{*/
			//printf(" %c", board[i][j]);
		printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
		if(i < ROW - 1)
			printf("___ ___ ___\n");
	
			/*if(j<COL-1)
				printf(" %c |", board[i][j]);
			else
				printf(" %c \n", board[i][j]);*/
	//	}
	}
	printf("\n");
	//printf("%d",board[i][j]);

}