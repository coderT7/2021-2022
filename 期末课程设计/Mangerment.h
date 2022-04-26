#pragma once
#include"Window.h"
#include<vector>
#include"PushButton.h"
#include"Empoyee.h"
#include"Table.h"
class Mangerment
{
	enum Option {
		DISPLAY,
		ADD,
		ERASE,
		MODIFY,
		SEARCH,
		//还漏了个EXIT，有空再补
		MENU = 10
	};
public:
	//启动整个程序
	Mangerment();
	void run();
	//菜单，及各项功能
	int menu();
	void display();
	void add();
	void erase();
	void modify();
	void search();
	//画背景
	void drawBackground();
	//监听事件
	void event_loop();
	//读、写文件
	void readFile(const std::string& fileName);
	void saveFile(const std::string& fileName);

private://界面的相关属性
	IMAGE m_bk;
	ExMessage m_msg;
	std::vector<PushButton*> menu_btns;
private://数据的相关属性
	std::string m_header;
	std::vector<Empoyee> vec_staff;
private://表格
	Table* m_table;
};

