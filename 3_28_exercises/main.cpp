#define _CRT_SECURE_NO_WARNINGS 1


#include"contact.h"


void* my_memcpy(void* str1, void* str2, size_t count) {
	assert(str1 && str2);

	void* ret = str1;
	while (count--) {
		*(char*)str1 = *(char*)str2;
		str1 = (char*)str1 + 1;
		str2 = (char*)str2 + 1;
	}

	return str1;
}
void* my_memmove(void* str1, void* str2, size_t count) {
	assert(str1 && str2);

	void* ret = str1;

	if (str1 < str2) {
		while (count--) {
			*(char*)str1 = *(char*)str2;
			str1 = (char*)str1 + 1;
			str2 = (char*)str2 + 1;
		}
	}
	else {
		str1 = (char*)str1 + count - 1;
		str2 = (char*)str2 + count - 1;
		*(char*)str1 = *(char*)str2;
		str1 = (char*)str1 - 1;
		str2 = (char*)str2 - 1;
	}

	return ret;
}

void menu()
{
	printf("*****************************************\n");
	printf("******    1.Add        2.Del       ******\n");
	printf("****** 	  3.Search     4.Modify    ******\n");
	printf("******	  5.Print      6.Sort      ******\n");
	printf("******	  7.Save       0.Exit      ******\n");
	printf("*****************************************\n");
}

int main()
{
	//创建通讯录
	Contanct contanct;
	//初始化通讯录
	init_contanct(contanct);
	int input;
	string name;
	do
	{
		menu();
		printf("请选择：>");
		cin >> input;
		switch (input)
		{
			//利用枚举类型增加代码可读性；
		case EXIT:
			destroy_contanct(contanct);
			printf("退出通讯录\n");
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
			cout << "请输入要查找的联系人姓名：";
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
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
	return 0;
}