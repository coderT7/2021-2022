#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include"worker.h"


class Empoyee:public worker
{
public:
	Empoyee(int ID,string name,int dID);
	//��ʾԱ����Ϣ
	virtual void showInfo();
	//��ȡ��λ����
	virtual string getDeptName();
};