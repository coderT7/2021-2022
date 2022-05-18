#include "Webtxt.h"
#include "SList.h"


//构造函数 
Webtxt::Webtxt() {}

//创建文件夹--头文件<io.h><direct.h>
void Webtxt::CreateFolder()
{
	char foldername[] = "webfolder";//文件夹名称
	//文件夹不存在则创建文件夹
	if (_access(foldername, 0) == -1)
	{
		_mkdir(foldername);//创建文件夹
	}
		cout << "创建文件夹成功！" << endl;
}


//把文件放在文件夹里面
//rename函数可重命名文件（目录）名、改变文件路径
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
	cout << "文件已成功复制到文件夹里面！" << endl;
}

//获得文件夹里面的文件名
void Webtxt::Getfilename()
{
	cout << "获得文件夹里面的文件有：" << endl;
	long long handle;//用于查找的句柄
	struct _finddata_t fileinfo;//文件信息的结构体
	handle = _findfirst("webfolder\\*.txt", &fileinfo);//第一次查找
	if (handle == -1)
		return;
	cout << fileinfo.name << endl;//打印找到的文件名
	while (!_findnext(handle, &fileinfo))//循环查找文件
	{
		cout << fileinfo.name << endl;
	}
	_findclose(handle);//关闭句柄

}

//菜单 1--选择网页C.txt或网页F.txt 
void Webtxt::menu1()
{
	cout << "##########################################" << endl;
	cout << "########## 选择操作网页文件   ############" << endl;
	cout << "########## 1、F.txt           ############" << endl;
	cout << "########## 2、C.txt           ############" << endl;
	cout << "########## 0、退出            ############" << endl;
	cout << "##########################################" << endl;
	cout << "请输入您的选择：" << endl;
}

//菜单 -- 具体操作
void Webtxt::menu2()
{
	cout << "*******************************************" << endl;
	cout << "******1、打印原始文件                ******" << endl;
	cout << "******2、删除超链接（可视化）并保存  ******" << endl;
	cout << "******3、统计剩余的单词数            ******" << endl;
	cout << "******4、打印单链表中的单词          ******" << endl;
	cout << "******5、打印单链表中去重后的单词    ******" << endl;
	cout << "******0、退出                        ******" << endl;
	cout << "*******************************************" << endl;
	cout << "请输入您的选择：" << endl;
}

//打印文件
void Webtxt::PrintFile( string filename)
{
	ifstream ifs;
	ifs.open(filename, ios::in);
	if (!ifs.is_open())
	{
		cout << "打开文件失败！" << endl;
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


//删除
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

//删除超链接<>
void Webtxt::Delete_link(string filename,string file2,char sign1,char sign2)
{
	ifstream ifs;
	ifs.open(filename, ios::in);
	if (!ifs.is_open())
	{
		cout << "打开文件失败！" << endl;
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

////删除未可视化内容{}
//void Webtxt::Delete2(string filename, string file2)
//{
//	ifstream ifs;
//	ifs.open(filename, ios::in);
//	if (!ifs.is_open())
//	{
//		cout << "打开文件失败！" << endl;
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

//统计剩余的单词数
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
		cout << "打开失败！" << endl;
		exit(0);
	}
	char buf[1024];//文件数组
	int num = 0;//单词总数
	ofstream ofs;
	ofs.open(filename2, ios::out);
	int max = 0;//存最长单词的长度
	string maxw;//存最长单词
	while (ifs >> buf)
	{
		if ((buf[0] >= 'a' && buf[0] <= 'z') || (buf[0] >= 'A' && buf[0] <= 'Z'))
		{
			num++;
			int i = 0;
			for (; ((buf[i] >= 'a' && buf[i] <= 'z') || (buf[i] >= 'A' && buf[i] <= 'Z')); i++)//遍历数组，到非字母是一个单词结束
			{
				if ((buf[i] >= 'A' && buf[i] <= 'Z'))
					buf[i] = buf[i] + 32;//全部换成小写
			
			}
			buf[i] = '\0';
			ofs << buf << endl;//把每个单词转换成小写 写进文件中
			if (max < strlen(buf))
			{
				max = strlen(buf);//当前最长单词长度给max，
				maxw = buf;//当前最长单词赋给buf
			}
		}
	}
	cout << "文件的单词数为：" << num << endl;
	cout << "最长的单词为：" << maxw << endl;
	ifs.close();
	ofs.close();
}

//选择文件串成单链表并打印
void Webtxt::slist_word(string filename)
{
	SList sl;
	if (filename == "F.txt")
	{
		sl.CreateSList("Del_F.txt");//串成一个单链表
		sl.PrintSList();//打印单链表

	}
	else
	{
		sl.CreateSList("Del_C.txt");
		sl.PrintSList();

	}
	system("pause");
	system("cls");
}

//去重并打印
void Webtxt::Delete(string filename)
{
	SList s;
	if (filename == "F.txt")
	{
		s.CreateSList("Del_F.txt");//串成单链表
		s.DeleteRepeat();//删除重复单词
		s.PrintSList();//打印链表
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


//析构函数
Webtxt::~Webtxt()
{

}
