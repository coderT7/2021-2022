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
	printf("******    ��ӭʹ�ò�����С����   ******\n");
	printf("***************************************\n");
	printf("******    1.play       0.exit    ******\n");
	printf("***************************************\n");
}
static void guess_num()
{
	ProcBar();
	printf("��ӭ������Ϸ��\n");
	Sleep(1000);
	system("cls");
	int num = rand() % 100 + 1;
	while (1)
	{
		printf("��������µ����֣�");
		int enter = 0;
		scanf("%d", &enter);
		if (enter == num)
		{
			printf("��ϲ��¶��ˣ�\n��������ص����˵�~\n");
			system("pause");
			break;
		}
		if (enter > num)
			printf("�´���Ŷ~���ٲ�һ�ΰɣ�\n");
		else
			printf("��С��Ŷ~���ٲ�һ�ΰɣ�\n");
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
			printf("��лʹ�øó���ף��������죡\n");
			break;
		case 1:
			guess_num();
			break;
		}
	} while (choose);
}