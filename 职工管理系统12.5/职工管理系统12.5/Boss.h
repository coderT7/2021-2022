#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include"worker.h"

class Boss :public worker
{
public:
	Boss(int ID, string name, int dID);
	//��ʾԱ����Ϣ
	virtual void showInfo();
	//��ȡ��λ����
	virtual string getDeptName();
};