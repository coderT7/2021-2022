#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

//将最多排查地雷的步数设为全局变量
//当排查一次地雷则对应减1，当排查次数为0时则胜出
int step_num = 0;
void menu()
{
	printf("***************************************\n");
	printf("******          1.PLAY           ******\n");
	printf("******          0.EXIT           ******\n");
	printf("***************************************\n");
}
//flag用于标识是进行标记还是进行取消标记
void mark_mine(char show[ROWS][COLS], int row, int col, int flag)
{
	if(flag == 2)
		printf("请输入你要标记的坐标：");
	else if(flag == 3)
		printf("请输入你要取消标记的坐标：");
	int x, y;
	while (1)
	{
		scanf("%d %d", &x, &y);
		//当show[x][y]为' '时，则说明其肯定不是地雷，则无需进行标记或者取消标记
		if (x <= 0 || x > row || y <= 0 || y > col || show[x][y] == ' ')
			printf("输入坐标非法，请重新输入\n");
		else
		{
			if (flag == 2)
			{
				show[x][y] = '#';
				show_board(show, row, col);
			}
			else if(flag == 3)
			{
				if (show[x][y] != '#' || show[x][y] == ' ')
				{
					show_board(show, row, col);
					printf("该坐标未被标记！\n");
				}
				else
				{
					show[x][y] = '*';
					show_board(show, row, col);
				}
			}
			break;
		}
	}
}
//进行难度选择
static void select_difficulty(char mine[ROWS][COLS])
{
	int choose = 0;
	do
	{
		printf("请选择难度：\n");
		printf("1.简单难度 2.中等难度 3.困难难度：");
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			set_mine(mine, EASY);
			//布置地雷时，顺带将步数进行初始化
			step_num = ROW * COL - EASY;
			break;
		case 2:
			set_mine(mine, MEDIUM);
			step_num = ROW * COL - MEDIUM;
			break;
		case 3:
			set_mine(mine, DIFFICULT);
			step_num = ROW * COL - DIFFICULT;
			break;
		default:
			printf("输入有误，请重新输入!\n");
			break;
		}
	} while (choose != 1 && choose != 2 && choose != 3);
}

void game()
{

	char mine[ROWS][COLS]; init_board(mine, '0');
	char show[ROWS][COLS]; init_board(show, '*');
	select_difficulty(mine);
	show_board(show, ROW, COL);
	printf("\n");
	//进行操作的选择
	while (step_num)
	{
		int choose = 0;
		printf("请输入你要进行的操作：\n");
		printf("1.排查地雷 2.标记地雷 3.取消标记：");
		scanf("%d", &choose);
		//flag用于标识是进行标记还是取消标记的操作
		int flag = choose;
		switch (choose)
		{
		//只有进行排查地雷时，步数才会减一
		case 1:
			find_mine(mine, show, ROW, COL);
			step_num--;
			break;
		case 2:
			mark_mine(show, ROW, COL, flag);
			break;
		case 3:
			mark_mine(show, ROW, COL, flag);
			break;
		default:
			printf("输入有误，请重新输入!\n");
			break;
		}
	}

}
//初始化数组（排雷区域）
void init_board(char arr[ROWS][COLS], char c)
{
	for (int i = 0; i < ROWS; i++)
		for (int j = 0; j < COLS; j++)
			arr[i][j] = c;
}

void show_board(char arr[ROWS][COLS], int row, int col)
{
	system("cls");
	for (int i = 0; i < ROWS - 1; i++)
		printf(" %d ", i);
	printf("\n");
	printf("————————————————\n");
	for (int i = 1; i <= row; i++)
	{
		printf(" %d|",i);
		for (int j = 1; j <= col; j++)
			printf(" %c ", arr[i][j]);
		printf("\n");
	}
}

void set_mine(char mine[ROWS][COLS], enum DIFFICULTY_SELE D_S)
{
	//根据难度不同，布置不同数量的地雷
	int count = D_S;
	while (count)
	{
		int x = rand() % ROW + 1;
		int y = rand() % COL + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}
//进行一个坐标周围有几个地雷的计算
static int count_mine(char mine[ROWS][COLS], int x, int y)
{
	int sum = 0;
	for (int i = -1; i <= 1; i++)
		for (int j = -1; j <= 1; j++)
			sum += mine[x - i][y - j];
	return sum - 8 * '0';
}
//当一个坐标不是地雷，且周身八个位置都不是地雷则进行更多类似位置的查找
//更加贴切真实扫雷
static void find_more(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	//防止递归出了数组边界
	if (x <= 0 || x > ROW || y <= 0 || y > COL)
		return;
	//该坐标上不是地雷
	if (mine[x][y] == '1')
		return;
	//该坐标未被标记
	if (show[x][y] == ' ')
		return;
	//该坐标周身八个位置都无地雷
	if (count_mine(mine, x, y) != '0')
		return;
	//则对该位置进行标记
	show[x][y] = ' ';
	//标记后则对应步数则进行相应的减少
	step_num--;
	//再对该坐标的各个方向进行递归查找有无类似位置
	find_more(mine, show, x - 1, y);
	find_more(mine, show, x + 1, y);
	find_more(mine, show, x, y - 1);
	find_more(mine, show, x, y + 1);
	find_more(mine, show, x - 1, y - 1);
	find_more(mine, show, x - 1, y + 1);
	find_more(mine, show, x + 1, y - 1);
	find_more(mine, show, x + 1, y + 1);
}

void find_mine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0, y = 0;
	while (1)
	{
		printf("请输入要排查的坐标：");
		scanf("%d %d", &x, &y);
		printf("\n");
		if (x <= 0 || x > row || y <= 0 || y > col)
			printf("输入坐标非法，请重新输入\n");
		else if(mine[x][y] == '1')
		{
			show_board(mine, row, col);
			printf("您输入的坐标为：%d %d\n", x, y);
			printf("很遗憾，游戏失败！再接再厉哦！\n");
			system("pause");
			system("cls");
			break;
		}
		else
		{
			int count = count_mine(mine, x, y);
			if (count == '0')
				find_more(mine, show, x, y);
			show[x][y] = count;
			show_board(show, ROW, COL);
			step_num--;
			break;
		}
	}
	//进行最后一步排雷后则步数为0，说明游戏胜利
	if (!step_num) printf("恭喜你，游戏胜利！\n");
}