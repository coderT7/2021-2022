#include "Webtxt.h"
#include "SList.h"


//���캯�� 
Webtxt::Webtxt() {}

//�����ļ���--ͷ�ļ�<io.h><direct.h>
void Webtxt::CreateFolder()
{
	char foldername[] = "webfolder";//�ļ�������
	//�ļ��в������򴴽��ļ���
	if (_access(foldername, 0) == -1)
	{
		_mkdir(foldername);//�����ļ���
	}
		cout << "�����ļ��гɹ���" << endl;
}


//���ļ������ļ�������
//rename�������������ļ���Ŀ¼�������ı��ļ�·��
void Webtxt::Copyfile(string file1,string file2)
{
	ifstream ifs;
	ifs.open(file1, ios::in);
	ofstream ofs;
	ofs.open(file2, ios::out);
	string buf;
	while (getline(ifs,buf))
	{
		ofs << buf << endl;
	}
	ifs.close();
	ofs.close();
}
void Webtxt::Folder()
{
	Copyfile("F.txt", ".//webfolder//F.txt");
	Copyfile("C.txt", ".//webfolder//C.txt");
	cout << "�ļ��ѳɹ����Ƶ��ļ������棡" << endl;
}

//����ļ���������ļ���
void Webtxt::Getfilename()
{
	cout << "����ļ���������ļ��У�" << endl;
	long long handle;//���ڲ��ҵľ��
	struct _finddata_t fileinfo;//�ļ���Ϣ�Ľṹ��
	handle = _findfirst("webfolder\\*.txt", &fileinfo);//��һ�β���
	if (handle == -1)
		return;
	cout << fileinfo.name << endl;//��ӡ�ҵ����ļ���
	while (!_findnext(handle, &fileinfo))//ѭ�������ļ�
	{
		cout << fileinfo.name << endl;
	}
	_findclose(handle);//�رվ��

}

//�˵� 1--ѡ����ҳC.txt����ҳF.txt 
void Webtxt::menu1()
{
	cout << "##########################################" << endl;
	cout << "########## ѡ�������ҳ�ļ�   ############" << endl;
	cout << "########## 1��F.txt           ############" << endl;
	cout << "########## 2��C.txt           ############" << endl;
	cout << "########## 0���˳�            ############" << endl;
	cout << "##########################################" << endl;
	cout << "����������ѡ��" << endl;
}

//�˵� -- �������
void Webtxt::menu2()
{
	cout << "*******************************************" << endl;
	cout << "******1����ӡԭʼ�ļ�                ******" << endl;
	cout << "******2��ɾ�������ӣ����ӻ���������  ******" << endl;
	cout << "******3��ͳ��ʣ��ĵ�����            ******" << endl;
	cout << "******4����ӡ�������еĵ���          ******" << endl;
	cout << "******5����ӡ��������ȥ�غ�ĵ���    ******" << endl;
	cout << "******0���˳�                        ******" << endl;
	cout << "*******************************************" << endl;
	cout << "����������ѡ��" << endl;
}

//��ӡ�ļ�
void Webtxt::PrintFile( string filename)
{
	ifstream ifs;
	ifs.open(filename, ios::in);
	if (!ifs.is_open())
	{
		cout << "���ļ�ʧ�ܣ�" << endl;
		exit(0);
	}
	char c;
	while ((c = ifs.get()) != EOF)
	{
		cout << c;
	}
	ifs.close();
	system("pause");
	system("cls");
}


//ɾ��
void Webtxt::Deal_delete(string filename)
{
	if (filename == "F.txt")
	{
		Delete_link(filename, "Delete_F.txt",'<','>');
		PrintFile("Delete_F.txt");
	}
	else
	{
		Delete_link(filename, "Delete_C1.txt",'<','>');
		Delete_link("Delete_C1.txt", "Delete_C.txt", '{', '}');
		Delete_link("Delete_C.txt", "Delete_C2.txt", '(', ')');
		//Delete2("Delete_C1.txt", "Delete_C2.txt");
		PrintFile("Delete_C2.txt");
	}
}

//ɾ��������<>
void Webtxt::Delete_link(string filename,string file2,char sign1,char sign2)
{
	ifstream ifs;
	ifs.open(filename, ios::in);
	if (!ifs.is_open())
	{
		cout << "���ļ�ʧ�ܣ�" << endl;
		exit(0);
	}
	char c;
	int flag = 0;
	ofstream ofs;
	ofs.open(file2, ios::out);
	while ((c = ifs.get()) != EOF)
	{
		if (c == sign1)
			flag = 1;
		if (c == sign2)
			flag = 0;
		if (flag == 0 && c != sign2)
			ofs << c;
		/*if (c == '<')
			flag = 1;
		if (c == '>')
			flag = 0;
		if (flag == 0 && c!='>')
			ofs << c;*/
	}
	ifs.close();
	ofs.close();
}

////ɾ��δ���ӻ�����{}
//void Webtxt::Delete2(string filename, string file2)
//{
//	ifstream ifs;
//	ifs.open(filename, ios::in);
//	if (!ifs.is_open())
//	{
//		cout << "���ļ�ʧ�ܣ�" << endl;
//		exit(0);
//	}
//	char c;
//	int flag = 0;
//	ofstream ofs;
//	ofs.open(file2, ios::out);
//	while ((c = ifs.get()) != EOF)
//	{
//		if (c == '{')
//			flag = 1;
//		if (c == '}')
//			flag = 0;
//		if (flag == 0 && c != '}')
//			ofs << c;
//	}
//	ifs.close();
//	ofs.close();
//}

//ͳ��ʣ��ĵ�����
void Webtxt::Fileword(string filename)
{
	if (filename == "F.txt")
	{
		Filenum("Delete_F.txt","Del_F.txt");
	}
	else
	{
		Filenum("Delete_C2.txt","Del_C.txt");
	}
	system("pause");
	system("cls");
}
void Webtxt::Filenum(string filename, string filename2)
{
	ifstream ifs;
	ifs.open(filename, ios::in);
	if (!ifs.is_open())
	{
		cout << "��ʧ�ܣ�" << endl;
		exit(0);
	}
	char buf[1024];//�ļ�����
	int num = 0;//��������
	ofstream ofs;
	ofs.open(filename2, ios::out);
	int max = 0;//������ʵĳ���
	string maxw;//�������
	while (ifs >> buf)
	{
		if ((buf[0] >= 'a' && buf[0] <= 'z') || (buf[0] >= 'A' && buf[0] <= 'Z'))
		{
			num++;
			int i = 0;
			for (; ((buf[i] >= 'a' && buf[i] <= 'z') || (buf[i] >= 'A' && buf[i] <= 'Z')); i++)//�������飬������ĸ��һ�����ʽ���
			{
				if ((buf[i] >= 'A' && buf[i] <= 'Z'))
					buf[i] = buf[i] + 32;//ȫ������Сд
			
			}
			buf[i] = '\0';
			ofs << buf << endl;//��ÿ������ת����Сд д���ļ���
			if (max < strlen(buf))
			{
				max = strlen(buf);//��ǰ����ʳ��ȸ�max��
				maxw = buf;//��ǰ����ʸ���buf
			}
		}
	}
	cout << "�ļ��ĵ�����Ϊ��" << num << endl;
	cout << "��ĵ���Ϊ��" << maxw << endl;
	ifs.close();
	ofs.close();
}

//ѡ���ļ����ɵ�������ӡ
void Webtxt::slist_word(string filename)
{
	SList sl;
	if (filename == "F.txt")
	{
		sl.CreateSList("Del_F.txt");//����һ��������
		sl.PrintSList();//��ӡ������

	}
	else
	{
		sl.CreateSList("Del_C.txt");
		sl.PrintSList();

	}
	system("pause");
	system("cls");
}

//ȥ�ز���ӡ
void Webtxt::Delete(string filename)
{
	SList s;
	if (filename == "F.txt")
	{
		s.CreateSList("Del_F.txt");//���ɵ�����
		s.DeleteRepeat();//ɾ���ظ�����
		s.PrintSList();//��ӡ����
	}
	else
	{
		s.CreateSList("Del_C.txt");
		s.DeleteRepeat();
		s.PrintSList();
	}
	system("pause");
	system("cls");
}


//��������
Webtxt::~Webtxt()
{

}
