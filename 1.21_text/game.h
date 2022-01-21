#pragma once

#include <stdio.h>
#include <stdlib.h>
#include<Windows.h>

#define ROW 3
#define COL 3

enum DIV
{
	LEFT,
	RIGHT,
	UP,
	DOWN
};
enum player
{
	PLAYER = 1,
	ROBOT
};
enum RESULT
{
	PLAYER_WIN = 1,
	ROBOT_WIN,
	DRAW,
	NEXT
};
enum MENU
{
	EXIT,
	PLAY
};

void menu();

void game();

void init_board(int board[][COL], int row, int col);

void display_board(int board[][COL], int row, int col);

void player_move(int board[][COL]);

void robot_move(int board[][COL]);

int is_over(int board[][COL], int x, int y);
