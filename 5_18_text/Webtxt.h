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
	//���캯�� 
	Webtxt();

	//�����ļ���
	void CreateFolder();
	
	//���ļ������ļ�������
	void Copyfile(string file1, string file2);
	void Folder();

	//����ļ���������ļ���
	void Getfilename();
	
	//�˵� 1--ѡ����ҳC.txt����ҳF.txt 
	void menu1();
	
	//�˵�2 -- �������
	void menu2(); 

	//��ӡ�ļ�
	void PrintFile(string filename);

	//ɾ��
	void Deal_delete(string filename);
	//ɾ��������<>
	void Delete_link(string filename, string file2,char sign1, char sign2);
	//ɾ��δ���ӻ�����{}
	//void Delete2(string filename, string file2);

	//ͳ��ʣ��ĵ�����
	void Fileword(string filename);
	void Filenum(string filename,string filename2);

	//��ӡ�������еĵ��� 		
	void slist_word(string filename);

	//ɾ���������ظ��ĵ���
	void Delete(string filename);

	//��������
	~Webtxt(); 
};


