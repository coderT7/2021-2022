#pragma once
#include<iostream>
#include<string>

using namespace std;
class menu
{
public:
	//展示菜单
	virtual void show_menu() = 0;
	//获取用户选项
	virtual void get_enter(int input) = 0;
};
class all_menu :public menu
{
public:
	virtual void show_menu();
	virtual void get_enter(int input);
};
class menu1 :public menu
{
public:
	virtual void show_menu();
	virtual void get_enter(int input);
};
class menu2 :public menu
{
public:
	virtual void show_menu();
	virtual void get_enter(int input);
};
//class menu3 :public menu
//{
//public:
//	virtual void show_menu();
//	virtual void get_enter(int input);
//};
//class menu4 :public menu
//{
//public:
//	virtual void show_menu();
//	virtual void get_enter(int input);
//};
//class menu5 :public menu
//{
//public:
//	virtual void show_menu();
//	virtual void get_enter(int input);
//};
//class menu6 :public menu
//{
//public:
//	virtual void show_menu();
//	virtual void get_enter(int input);
//};