#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

int who_first()
{
	int n = 0;
	printf("请选择电脑先手，还是玩家先手。输入0表示电脑先手，非0表示玩家先手\n");
	scanf("%d", &n);
	if (n == 0)
		return 0;
	else
		return 1;
}
void computer_start(char board[ROW][COL])
{
	int x = 0;
	int y = 0;
	int k = 0;
	if ((board[1][1] == board[0][0] ) && (board[1][1]) != ' ')   
	{
		if (board[2][2] == ' ')
		{
			board[2][2] = '0';
			return;
		}
	}
	else if ((board[1][1] == board[2][2]) && (board[1][1]) != ' ')
	{
		if (board[0][0] == ' ')
		{
			board[0][0] = '0';
			return;
		}
	}
	else if ((board[0][0] == board[2][2]) && (board[0][0]) != ' ')
	{
		if (board[1][1] == ' ')
		{
			board[1][1] = '0';
			return;
		}
	}
	else if (((board[1][1] == board[0][2])  && (board[1][1]) != ' '))
	{
		if (board[2][0] == ' ')
		{
			board[2][0] = '0';
			return;
		}
	}
	else if (((board[1][1] == board[2][0]) && (board[1][1]) != ' '))
	{
		if (board[0][2] == ' ')
		{
			board[0][2] = '0';
			return;
		}
	}
	else if (((board[0][2] == board[2][0]) && (board[0][2]) != ' '))
	{
		if (board[1][1] == ' ')
		{
			board[1][1] = '0';
			return;
		}
	}
	else
	{
		for (int i = 0; i < ROW; i++)
		{
			//for(int j =0;j<COL;j++)
			if (((board[i][1] == board[i][0])) && (board[i][1]) != ' ')
			{
				if (board[i][2] == ' ')
				{
					board[i][2] = '0';
					//k++;
					return;
				}
			}
			else if (((board[i][1] == board[i][2])) && (board[i][1]) != ' ')
			{

				if (board[i][0] == ' ')
				{
					board[i][0] = '0';
					//k++;
					return;
				}
			}
			else if (((board[i][0] == board[i][2])) && (board[i][0]) != ' ')
			{

				if (board[i][1] == ' ')
				{
					board[i][1] = '0';
					//k++;
					return;
				}
			}


			else if (((board[1][i] == board[0][i])) && (board[1][i]) != ' ')
			{
				if (board[2][i] == ' ')
				{
					board[2][i] = '0';
					//k++;
					return;
				}
			}
			else if (((board[1][i] == board[2][i])) && (board[1][i]) != ' ')
			{

				if (board[0][i] == ' ')
				{
					board[0][i] = '0';
					//k++;
					return;
				}
			}
			else if (((board[0][i] == board[2][i])) && (board[0][i]) != ' ')
			{

				if (board[1][i] == ' ')
				{
					board[1][i] = '0';
					//k++;
					return;
				}
			}
		}


	}
	do
	{
		x = rand() % ROW;
		y = rand() % COL;
	} while (board[x][y] != ' ');
	board[x][y] = '0';
}

void player_start(char board[ROW][COL])
{
	
	int n1 = 0;
	int n2 = 0;
reinput:
	//fflush(stdin);
	printf("请输入坐标，坐标以(0,0)开始:\n");
	scanf("%d%d", &n1, &n2);
	if ((n1 < 0 || n1 >= ROW) || (n1 < 0 || n1 >= COL))
		{
			printf("坐标不存在，重新输入\n");
			goto reinput;
		}
	if (board[n1][n2] == '1' || board[n1][n2] == '0')
	{
		printf("已有旗子，请重新输入\n");
		goto reinput;
	}
		if (board[n1][n2] == ' ')
		{
			board[n1][n2] = '1';
		}
	    
	
}
//0 computer
//1 player
//2 no one win
//3 go on
char gameOver(char board[ROW][COL])
{
	for(int i = 0;i<ROW;i++)
		{
			if ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]) && (board[i][1] != ' '))
				return board[i][0];
			if ((board[0][i] == board[1][i]) && (board[1][i] == board[2][i]) && (board[1][i] != ' '))
				return board[0][i];
			if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) && (board[1][1] != ' '))
				return board[1][1];
			if((board[0][2] == board[1][1]) && (board[1][1] == board[2][0]) && (board[1][1] != ' '))
				return board[1][1];
		}
	int count = 0;
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			
			if (board[i][j] != ' ')
				count++;
			if (count ==9)
				return '2';
		}
	}
	return '3';
}
void game(char board[ROW][COL])
{
	unsigned  int seed = (unsigned int)time(NULL);
	srand(seed);
	
	if (who_first() == 0)
	{
		do
		{
			computer_start(board);
			system("cls");
			printf("computer:\n");
			display(board);
			
			if (gameOver(board) == '0')
			{
				printf("computer win\n");
				break;
			}
			if (gameOver(board) == '1')
			{
				printf("player win\n");
				break;
			}
			if (gameOver(board) == '2')
			{
				printf("no one win\n");
				break;
			}
			player_start(board);
			system("cls");
			printf("player:\n");
			display(board);
			
			if (gameOver(board) == 0)
			{
				printf("computer win\n");
				break;
			}
			if (gameOver(board) == '1')
			{
				printf("player win\n");
				break;
			}
			if (gameOver(board) == '2')
			{
				printf("no one win\n");
				break;
			}
		} while (1);

	}
	else
		{
			display(board);
			do
			{
				player_start(board);
				system("cls");
				printf("player:\n");
				display(board);
				if (gameOver(board) == '0')
				{
					printf("computer win\n");
					break;
				}
				if (gameOver(board) =='1')
				{
					printf("player win\n");
					break;
				}
				if (gameOver(board) == '2')
				{
					printf("no one win\n");
					break;
				}
				computer_start(board);
				system("cls");
				printf("computer:\n");
				display(board);
				if (gameOver(board) == '0')
				{
					printf("computer win\n");
					break;
				}
				if (gameOver(board) == '1')
				{
					printf("player win\n");
					break;
				}
				if (gameOver(board) == '2')
				{
					printf("no one win\n");
					break;
				}
				
			} while (1);

		}
			


	
	
}

