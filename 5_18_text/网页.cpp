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
		case 1://��ӡԭ�ļ�
			wb.PrintFile(filename);
			break;
		case 2://ɾ�������ӻ���ӻ�����
			wb.Deal_delete(filename);
			break;
		case 3://���㵥����
			wb.Fileword(filename);
			break;
		case 4://��ӡ�������еĵ��� 		
			wb.slist_word(filename);
			break;
		case 5://��ӡ��������ȥ�غ�ĵ���			
			wb.Delete(filename);
			break;
		case 0:
			cout << "�˳��������棡" << endl;
			return ;
			break;
		default:
			cout << "����������������룺" << endl;
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
				cout<<"�˳�����"<<endl;
				return 0;
			default:
				cout<<"����������������룺"<<endl;
				break;									
		}
		
	}
}
