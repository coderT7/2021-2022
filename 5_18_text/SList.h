#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//��������
class Node
{
public:
	string word;//�浥��
	Node* next;
	/*Node()
	{
		next = nullptr;
	}*/
};


class SList
{
public:
	//���쵥����
	SList();

	//���
	SList(const SList& p);

	//����������
	void CreateSList(string filename);

	//��ӡ������
	void PrintSList();

	//ɾ���������ظ��ĵ���
	void DeleteRepeat();	

	//��������
	~SList();

private:
	Node* head;
};
