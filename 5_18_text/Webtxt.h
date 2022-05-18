#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <direct.h>
#include <io.h>
#include <string.h>

using namespace std;

#include "SList.h"

class  Webtxt
{
	friend SList::SList();

public:
	//构造函数 
	Webtxt();

	//创建文件夹
	void CreateFolder();
	
	//把文件放在文件夹里面
	void Copyfile(string file1, string file2);
	void Folder();

	//获得文件夹里面的文件名
	void Getfilename();
	
	//菜单 1--选择网页C.txt或网页F.txt 
	void menu1();
	
	//菜单2 -- 具体操作
	void menu2(); 

	//打印文件
	void PrintFile(string filename);

	//删除
	void Deal_delete(string filename);
	//删除超链接<>
	void Delete_link(string filename, string file2,char sign1, char sign2);
	//删除未可视化内容{}
	//void Delete2(string filename, string file2);

	//统计剩余的单词数
	void Fileword(string filename);
	void Filenum(string filename,string filename2);

	//打印单链表中的单词 		
	void slist_word(string filename);

	//删除链表中重复的单词
	void Delete(string filename);

	//析构函数
	~Webtxt(); 
};


