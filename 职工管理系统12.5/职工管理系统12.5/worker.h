#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<iostream>
#include<string>
using namespace std;

//职工的抽象类
class worker
{
public:
	//显示员工信息
	virtual void showInfo() = 0;
	//获取岗位名称
	virtual string getDeptName() = 0;

	//职工的属性
	int m_ID;//职工编号
	string m_name;//职工姓名
	int m_DeptID;//岗位编号
};