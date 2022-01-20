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
	//显示员工信息
	virtual void showInfo();
	//获取岗位名称
	virtual string getDeptName();
};