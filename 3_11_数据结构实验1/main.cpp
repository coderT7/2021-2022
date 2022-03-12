#define _CRT_SECURE_NO_WARNINGS 1
#include"text.h"

int main()
{
	int input = 0;
	string str;
	do
	{
		system("cls");
		menu();
		cin >> input;
		switch (input)
		{
		case readTxt:
		{
			cout << "请输入要浏览的文件名：";
			cin >> str;
			read_text(str.c_str());
			system("pause");
		}
			break;
		case delHyink:
		{
			cout << "请输入要进行超链接删除的文件名：";
			cin >> str;
			hyperlink_delete(str.c_str());
			system("pause");
		}
			break;
		case getWord:
		{
			cout << "请输入要获取单词列表的文件名：";
			cin >> str;
			int ret = get_word_num(str.c_str());
			cout << "共捕获到" << ret << "个单词" << endl;
			system("pause");
		}
			break;
		case delFile:
		{
			cout << "请输入要删除的文件名：";
			cin >> str;
			delete_file(str.c_str());
			system("pause");
		}
		break;
		case delDup:
		{
			cout << "请输入要进行单词去重的文件名：";
			cin >> str;
			remove_duplicates(str.c_str());
			system("pause");
		}
		case Exit:
			cout << "感谢您的使用，祝您生活愉快！" << endl;
			break;
		default:
			cout << "输入有误，请重新输入！" << endl;
			break;
		}

	} while (input);
	return 0;
}