#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include"worker.h"

class Boss :public worker
{
public:
	Boss(int ID, string name, int dID);
	//显示员工信息
	virtual void showInfo();
	//获取岗位名称
	virtual string getDeptName();
};