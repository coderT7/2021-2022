#define _CRT_SECURE_NO_WARNINGS 1
#include"main.h"

//��ǰ�汾ÿ��ֻ�ܴ���һ���ļ�����Ϣ�������Զ�ν��У�ÿ�λ�õ��ļ���Ϣ����Ե��δ�����ļ���
//��չ���ɴ������ļ���Ϣ
//��չ˼·һ����������ļ��������������ɣ�ÿ�δ������ʱ��ʾ�û����������ĸ��ļ�
//��չ˼·�������ö�̬��������˼·һ�����ŵ����ڴ�����չ�Ժã�ά������
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
			cout << "������Ҫ������ļ�����";
			cin >> str;
			read_text(str.c_str());
			system("pause");
		}
			break;
		case delHyink:
		{
			cout << "������Ҫ���г�����ɾ�����ļ�����";
			cin >> str;
			//hyperlink_delete(str.c_str());
			delete_all(str.c_str());
			system("pause");
		}
			break;
		case getWord:
		{
			//�����ļ�����׷�ӷ�ʽ���еģ�Ϊ����߸����ԣ�ÿ�λ�ȡǰ�Ƚ�ԭ���ļ�ɾ��
			remove("word.txt");
			cout << "������Ҫ��ȡ�����б���ļ�����";
			cin >> str;
			int ret = get_word_num(str.c_str());
			cout << "������" << ret << "������" << endl;
			system("pause");
		}
			break;
		case delFile:
		{
			cout << "������Ҫɾ�����ļ�����";
			cin >> str;
			delete_file(str.c_str());
			system("pause");
		}
		break;
		case delDup:
		{
			//ȥ��ͬͳ�Ƶ���ͬ��
			remove("del_word.txt");
			cout << "������Ҫ���е���ȥ�ص��ļ�����";
			cin >> str;
			remove_duplicates(str.c_str());
			system("pause");
		}
		case Exit:
			cout << "��л����ʹ�ã�ף��������죡" << endl;
			break;
		default:
			cout << "�����������������룡" << endl;
			break;
		}

	} while (input);
	return 0;
}