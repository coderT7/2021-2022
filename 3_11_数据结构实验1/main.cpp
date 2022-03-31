#define _CRT_SECURE_NO_WARNINGS 1
#include"main.h"

//当前版本每次只能处理一个文件的信息，但可以多次进行（每次获得的文件信息仅针对当次处理的文件）
//扩展：可处理多个文件信息
//扩展思路一：将输出的文件名定义成随机生成，每次处理完毕时提示用户保存至了哪个文件
//扩展思路二：利用多态，本质是思路一，但优点在于代码延展性好，维护容易
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
			//hyperlink_delete(str.c_str());
			delete_all(str.c_str());
			system("pause");
		}
			break;
		case getWord:
		{
			//单词文件是以追加方式进行的，为了提高复用性，每次获取前先将原有文件删除
			remove("word.txt");
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
			//去重同统计单词同理
			remove("del_word.txt");
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