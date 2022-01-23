#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

int main()
{
	srand((unsigned int)time(NULL));
	int choose = 0;
	do
	{
		system("cls");
		menu();
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			game();
			system("pause");
			break;
		case 0:
			printf("祝您生活愉快！\n");
			break;
		default:
			printf("输入有误，请重新输入!\n");
			break;
		}
	} while (choose);
	return 0;
}