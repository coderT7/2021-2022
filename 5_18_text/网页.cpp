#include "Webtxt.h"

void OperateFile(Webtxt wb,const string filename)
{
	while(true)
	{
		wb.menu2();
		int input;
		cin >> input;
		switch (input)
		{
		case 1://打印原文件
			wb.PrintFile(filename);
			break;
		case 2://删除超链接或可视化内容
			wb.Deal_delete(filename);
			break;
		case 3://计算单词数
			wb.Fileword(filename);
			break;
		case 4://打印单链表中的单词 		
			wb.slist_word(filename);
			break;
		case 5://打印单链表中去重后的单词			
			wb.Delete(filename);
			break;
		case 0:
			cout << "退出操作界面！" << endl;
			return ;
			break;
		default:
			cout << "输入错误！请重新输入：" << endl;
			break;
		}
	}
}

int main()
{
	Webtxt wb;
	int input=1;
	string filename;
	wb.CreateFolder();
	wb.Folder();
	wb.Getfilename();
	while(true)
	{
		wb.menu1();
		cin>>input;
		switch(input)
		{
			case 1:
				OperateFile(wb,"F.txt");
				break;
			case 2:
				OperateFile(wb,"C.txt");
				break;
			case 0:
				cout<<"退出程序！"<<endl;
				return 0;
			default:
				cout<<"输入错误！请重新输入："<<endl;
				break;									
		}
		
	}
}
