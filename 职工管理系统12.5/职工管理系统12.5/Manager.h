#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<iostream>
using namespace std;
#include<string>
#include"worker.h"

class Manager:public worker
{
public:
	Manager(int ID, string name, int dID);
	//��ʾԱ����Ϣ
	virtual void showInfo();
	//��ȡ��λ����
	virtual string getDeptName();
};