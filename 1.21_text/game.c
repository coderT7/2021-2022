#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"
int X = 0, Y = 0;
void menu()
{
	printf("***************************************\n");
	printf("******          1.PLAY           ******\n");
	printf("******          0.EXIT           ******\n");
	printf("***************************************\n");
}

void game()
{
	int board[ROW][COL];
	init_board(board, ROW, COL);
	display_board(board, ROW, COL);
	int result = 0;
	while (1)
	{
		//每次落子都要判断输赢
		player_move(board);
		display_board(board, ROW, COL);
		result = is_over(board, X, Y);
		//当判断结果不为NEXT时，则说明棋局已结束，则跳出循环
		if (result != NEXT) break;
		robot_move(board);
		display_board(board, ROW, COL);
		result = is_over(board, X, Y);
		if (result != NEXT) break;
	}
	if (result == PLAYER_WIN)
		printf("恭喜你赢得本局胜利！\n");
	else if (result == ROBOT_WIN)
		printf("很遗憾，机器胜出！再接再厉~\n");
	else
		printf("平局了哦~\n");
}

void init_board(int board[][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			board[i][j] = '\0';
}

void display_board(int board[][COL], int row, int col)
{
	system("cls");
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == PLAYER)
				printf(" * ");
			else if (board[i][j] == ROBOT)
				printf(" # ");
			else
				printf("   ");
			if (j < col - 1) printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			for (int j = 0; j < col; j++)
			{
				printf("___");
				if (j < col - 1) printf("|");
			}
		}
		printf("\n");
	}
}

void player_move(int board[][COL])
{
	printf("请输入你要落子的坐标：");
	while (1)
	{
		scanf("%d %d", &X, &Y);
		if (X - 1 < 0 || X - 1 > ROW || Y - 1 < 0 || Y - 1 > COL)
			printf("输入的坐标有误，不在棋盘范围内，请重新输入：\n");
		else if (board[X - 1][Y - 1] != '\0')
			printf("该位置已有棋子，请重新输入：\n");
		else
		{
			board[X - 1][Y - 1] = PLAYER;
			break;
		}		
	}
}

void robot_move(int board[][COL])
{
	while (1)
	{
		X = rand() % 3 + 1;
		Y = rand() % 3 + 1;
		if (board[X - 1][Y - 1] == '\0' && X != 0 && Y != 0)
		{
			board[X - 1][Y - 1] = ROBOT;
			break;
		}
	}
}

static int check_result(int board[][COL], int x, int y, enum DIV div)
{
	int _x = x - 1;
	int _y = y - 1;
	int count = 0;
	while (1)
	{
		switch (div)
		{
		case LEFT:
			_y--;
			break;
		case RIGHT:
			_y++;
			break;
		case UP:
			_x++;
			break;
		case DOWN:
			_x--;
			break;
		case LEFT_UP:
			_y--; _x--;
			break;
		case RIGHT_DOWN:
			_y++; _x++;
			break;
		case LEFT_DOWN:
			_y--; _x++;
			break;
		case RIGHT_UP:
			_y++; _x--;
			break;
		default:
			break;
		}
		if (_x < 0 || _x > ROW || _y < 0 || _y > COL)	
			break;
		if (board[_x][_y] == board[x - 1][y - 1])
			count++;
		else
			break;
	}
	return count;
}
int is_over(int board[][COL],int x, int y)
{
	int count1 = check_result(board, x, y, LEFT) + check_result(board, x, y, RIGHT) + 1;
	int count2 = check_result(board, x, y, UP) + check_result(board, x, y, DOWN) + 1;
	int count3 = check_result(board, x, y, LEFT_UP) + check_result(board, x, y, RIGHT_DOWN) + 1;
	int count4 = check_result(board, x, y, RIGHT_UP) + check_result(board, x, y, LEFT_DOWN) + 1;
	if (count1 == 3 || count2 == 3 || count3 == 3 || count4 == 4)
		return board[x - 1][y - 1];
	for(int i = 0; i < ROW; i++)
		for (int j = 0; j < COL; j++)
		{
			if (board[i][j] == '\0')
				return NEXT;
		}
	return DRAW;
}