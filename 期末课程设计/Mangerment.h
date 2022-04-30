#pragma once
#include"Window.h"
#include<vector>
#include"PushButton.h"
#include"Empoyee.h"
#include"EditLine.h"
#include"Table.h"
#include"SalaryTable.h"
#include"CirclePushButton.h"
class Mangerment
{
	enum Option {
		DISPLAY,
		ADD,
		ERASE,
		MODIFY,
		SEARCH,
		STATISTICS,
		EXIT,
		MENU = 10
	};
	enum Option_1 {
		ID,
		NAME,
		SALARY1,
		SALARY2,
		SALARY3,
		SALARY4,
		SALARY5
	};
public:
	//启动整个程序
	Mangerment();
	void run();
	//菜单，及各项功能
	int menu();
	void display();
	void add();
	void updateTableData();
	void updataSalaryTableData();
	void statistics();
	void erase();
	//inline static bool getChoice();
	void modify();
	int getAllSalary(Empoyee& empoyee);
	int getModifyOption();
	void search();
	//画背景
	void drawBackground();
	//监听事件
	void event_loop();
	//读、写文件
	void readFile(const std::string& fileName);
	void saveFile(const std::string& fileName);
	
private://主界面的相关属性
	int background = 3;
	std::vector<IMAGE> m_bks;
	ExMessage m_msg;
	std::vector<PushButton*> menu_btns;
	CirclePushButton* cPushButton;
private://数据的相关属性
	std::string m_header;
	std::vector<Empoyee> vec_staff;
private://表格
	Table* m_table;
	SalaryTable* m_salaryTable;
public://添加数据界面
	PushButton* addBtn;
	EditLine* addEdit;
	Table* addTable;
public://删除数据页面
	PushButton* delBtnOfID;
	//inline static PushButton* confirmBtn;
	//inline static PushButton* cancelBtn;
	Table* delTable;
	EditLine* delEditOfID;
	EditLine* delEditOfName;
	PushButton* delBtnOfName;
public://查找数据界面
	PushButton* searchBtn;
	Table* searchTable;
	EditLine* searchEdit;
	std::vector<Empoyee> vec_modifyStaff;
public://修改数据界面
	std::vector<PushButton*> option_btns;
private://排序数据
	std::vector<PushButton*> sort_btns;
};

