#pragma once
#ifndef __GAME_H__
#define __GAME_H__

#define ROW 3
#define COL 3

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void menu();
void game(char board[ROW][COL]);
void display(char board[ROW][COL]);
int who_first();
void computer_start(char board[ROW][COL]);
void player_start(char board[ROW][COL]);
char gameOver(char board[ROW][COL]);
//int row = 3;
//int col = 3;


#endif // !__GAME_H__

