#define _CRT_SECURE_NO_WARNINGS 1


#include"contact.h"

void menu()
{
	printf("*****************************************\n");
	printf("******    1.Add        2.Del       ******\n");
	printf("****** 	  3.Search     4.Modify    ******\n");
	printf("******	  5.Print      6.Sort      ******\n");
	printf("******	  7.Save       8.Destroy   ******\n");
	printf("******          0.Exit             ******\n");
	printf("*****************************************\n");
}

int main()
{
	//����ͨѶ¼
	Contanct contanct;
	//��ʼ��ͨѶ¼
	init_contanct(contanct);
	int input;
	string name;
	do
	{
		menu();
		printf("��ѡ��>");
		cin >> input;
		switch (input)
		{
			//����ö���������Ӵ���ɶ��ԣ�
		case EXIT:
			save_stu(contanct);
			printf("�˳�ͨѶ¼\n");
			break;
		case ADD:
			system("cls");
			add_peoInfo(contanct);
			break;
		case DEL:
			system("cls");
			del_peoInfo(contanct);
			break;
		case SEARCH:
			system("cls");
			cout << "������Ҫ���ҵ���ϵ��������";
			cin >> name;
			search_peoInfo(contanct,name);
			break;
		case MODIFY:
			system("cls");
			modify_peoInfo(contanct);
			break;
		case PRINT:
			system("cls");
			print_contanct(contanct);
			break;
		case SORT:
			system("cls");
			sort_peoInfo(contanct);
			break;
		case SAVE:
			system("cls");
			save_stu(contanct);
			break;
		case DESTROY:
			system("cls");
			destroy_contanct(contanct);
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input);
	return 0;
}