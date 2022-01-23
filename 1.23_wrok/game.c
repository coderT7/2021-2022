#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

//������Ų���׵Ĳ�����Ϊȫ�ֱ���
//���Ų�һ�ε������Ӧ��1�����Ų����Ϊ0ʱ��ʤ��
int step_num = 0;
void menu()
{
	printf("***************************************\n");
	printf("******          1.PLAY           ******\n");
	printf("******          0.EXIT           ******\n");
	printf("***************************************\n");
}
//flag���ڱ�ʶ�ǽ��б�ǻ��ǽ���ȡ�����
void mark_mine(char show[ROWS][COLS], int row, int col, int flag)
{
	if(flag == 2)
		printf("��������Ҫ��ǵ����꣺");
	else if(flag == 3)
		printf("��������Ҫȡ����ǵ����꣺");
	int x, y;
	while (1)
	{
		scanf("%d %d", &x, &y);
		//��show[x][y]Ϊ' 'ʱ����˵����϶����ǵ��ף���������б�ǻ���ȡ�����
		if (x <= 0 || x > row || y <= 0 || y > col || show[x][y] == ' ')
			printf("��������Ƿ�������������\n");
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
					printf("������δ����ǣ�\n");
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
//�����Ѷ�ѡ��
static void select_difficulty(char mine[ROWS][COLS])
{
	int choose = 0;
	do
	{
		printf("��ѡ���Ѷȣ�\n");
		printf("1.���Ѷ� 2.�е��Ѷ� 3.�����Ѷȣ�");
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			set_mine(mine, EASY);
			//���õ���ʱ��˳�����������г�ʼ��
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
			printf("������������������!\n");
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
	//���в�����ѡ��
	while (step_num)
	{
		int choose = 0;
		printf("��������Ҫ���еĲ�����\n");
		printf("1.�Ų���� 2.��ǵ��� 3.ȡ����ǣ�");
		scanf("%d", &choose);
		//flag���ڱ�ʶ�ǽ��б�ǻ���ȡ����ǵĲ���
		int flag = choose;
		switch (choose)
		{
		//ֻ�н����Ų����ʱ�������Ż��һ
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
			printf("������������������!\n");
			break;
		}
	}

}
//��ʼ�����飨��������
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
	printf("��������������������������������\n");
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
	//�����ѶȲ�ͬ�����ò�ͬ�����ĵ���
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
//����һ��������Χ�м������׵ļ���
static int count_mine(char mine[ROWS][COLS], int x, int y)
{
	int sum = 0;
	for (int i = -1; i <= 1; i++)
		for (int j = -1; j <= 1; j++)
			sum += mine[x - i][y - j];
	return sum - 8 * '0';
}
//��һ�����겻�ǵ��ף�������˸�λ�ö����ǵ�������и�������λ�õĲ���
//����������ʵɨ��
static void find_more(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	//��ֹ�ݹ��������߽�
	if (x <= 0 || x > ROW || y <= 0 || y > COL)
		return;
	//�������ϲ��ǵ���
	if (mine[x][y] == '1')
		return;
	//������δ�����
	if (show[x][y] == ' ')
		return;
	//����������˸�λ�ö��޵���
	if (count_mine(mine, x, y) != '0')
		return;
	//��Ը�λ�ý��б��
	show[x][y] = ' ';
	//��Ǻ����Ӧ�����������Ӧ�ļ���
	step_num--;
	//�ٶԸ�����ĸ���������еݹ������������λ��
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
		printf("������Ҫ�Ų�����꣺");
		scanf("%d %d", &x, &y);
		printf("\n");
		if (x <= 0 || x > row || y <= 0 || y > col)
			printf("��������Ƿ�������������\n");
		else if(mine[x][y] == '1')
		{
			show_board(mine, row, col);
			printf("�����������Ϊ��%d %d\n", x, y);
			printf("���ź�����Ϸʧ�ܣ��ٽ�����Ŷ��\n");
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
	//�������һ�����׺�����Ϊ0��˵����Ϸʤ��
	if (!step_num) printf("��ϲ�㣬��Ϸʤ����\n");
}