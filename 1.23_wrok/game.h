#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>

#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2


//ÄÑ¶ÈÑ¡Ôñ
enum DIFFCULTY_SELE
{
	EASY = 10,
	MEDIUM = 20,
	DIFFICULT = 30
};

void game();

void menu();

void init_board(char arr[ROWS][COLS], char c);

void show_board(char arr[ROWS][COLS], int row, int col);

void set_mine(char mine[ROWS][COLS],enum DIFFICULTY_SELE D_S);

void find_mine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);

