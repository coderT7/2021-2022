#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//单链表结点
class Node
{
public:
	string word;//存单词
	Node* next;
	/*Node()
	{
		next = nullptr;
	}*/
};


class SList
{
public:
	//构造单链表
	SList();

	//深拷贝
	SList(const SList& p);

	//创建单链表
	void CreateSList(string filename);

	//打印单链表
	void PrintSList();

	//删除链表中重复的单词
	void DeleteRepeat();	

	//析构函数
	~SList();

private:
	Node* head;
};
