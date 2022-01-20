#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

static void ProcBar()
{
	char Bar[NUM];
	memset(Bar, '\0', sizeof(Bar));
	const char* lable = "-|/\\";
	int i = 0;
	while (i <= 100)
	{
		printf("[%-100s][%-3d%%][%c]\r", Bar, i, lable[i % 4]);
		fflush(stdout);
		Bar[i++] = '#';
		Sleep(25);
	}
	printf("\n");
}
static void menu()
{
	printf("******    欢迎使用猜数字小程序   ******\n");
	printf("***************************************\n");
	printf("******    1.play       0.exit    ******\n");
	printf("***************************************\n");
}
static void guess_num()
{
	ProcBar();
	printf("欢迎进入游戏！\n");
	Sleep(1000);
	system("cls");
	int num = rand() % 100 + 1;
	while (1)
	{
		printf("请输入你猜的数字：");
		int enter = 0;
		scanf("%d", &enter);
		if (enter == num)
		{
			printf("恭喜你猜对了！\n按任意键回到主菜单~\n");
			system("pause");
			break;
		}
		if (enter > num)
			printf("猜大了哦~请再猜一次吧！\n");
		else
			printf("猜小了哦~请再猜一次吧！\n");
	}
}
void game()
{
	int choose = 1;
	do
	{
		system("cls");
		menu();
		scanf("%d", &choose);
		switch (choose)
		{
		case 0:
			printf("感谢使用该程序，祝您生活愉快！\n");
			break;
		case 1:
			guess_num();
			break;
		}
	} while (choose);
}