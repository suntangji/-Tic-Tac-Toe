#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

int main()
{
	int input = 0;
	char board[ROW][COL];
	
	do
	{
		menu();
		
		
		for (int i = 0; i<ROW; i++)
			for (int j = 0; j<COL; j++)
				board[i][j] = ' ';
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			break;
		case 1:
			game(board);
			break;
		default:
			printf("����������������");
			break;
		}

	} while (input);

	system("pause");
	return 0;
}