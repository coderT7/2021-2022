#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<iostream>
#include<fstream>
#include"worker.h"
#include"Boss.h"
#include"Empoyee.h"
#include"Manager.h"
using namespace std;
#define FILENAME "empFile.txt"

class workManager
{
public:
	//构造函数对该类进行初始化
	workManager();

	//行为
	//展示界面
	void showMenu();
	//退出程序
	void ExitSystem();
	//添加员工的函数
	void AddEmp();
	//保存员工的数据
	void Save();
	//属性
	//记录员工的数量
	int m_Empnum;
	//记录每位员工信息的数组
	//多态进行管理（基类的指针指向派生类的对象）故存储时需要存储基类的指针，故需要用二级指针进行存储
	worker **m_EmpArray;
	//判断文件是否为空
	bool m_FileIsEmpty;
	//统计文件里共有多少人
	int get_Empnum();
	//初始化职工文件
	void Init_Emp();
	//打印职工的信息
	void Show_Emp();
	//删除职工的信息
	void Del_Emp();
	//判断该职工是否存在
	int Exist(int dID);
	//修改员工信息
	void Mod_Emp();
	//查找员工
	void Find_Emp();
	//排序职工
	void Sort_Emp();
	//清空数据
	void Clean_File();

	//析构函数
	~workManager();
};

enum Choice
{
	Exit,
	Add,
	DisPlay,
	Del,
	Modify,
	Search,
	Sort,
	Formate
};

enum m_Worker
{
	m_Empoyee = 1,
	m_Manager,
	m_Boss
};