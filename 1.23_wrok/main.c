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
			printf("ף��������죡\n");
			break;
		default:
			printf("������������������!\n");
			break;
		}
	} while (choose);
	return 0;
}