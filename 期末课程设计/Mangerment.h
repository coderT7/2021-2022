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
	//������������
	Mangerment();
	void run();
	//�˵����������
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
	//������
	void drawBackground();
	//�����¼�
	void event_loop();
	//����д�ļ�
	void readFile(const std::string& fileName);
	void saveFile(const std::string& fileName);
	
private://��������������
	int background = 3;
	std::vector<IMAGE> m_bks;
	ExMessage m_msg;
	std::vector<PushButton*> menu_btns;
	CirclePushButton* cPushButton;
private://���ݵ��������
	std::string m_header;
	std::vector<Empoyee> vec_staff;
private://���
	Table* m_table;
	SalaryTable* m_salaryTable;
public://������ݽ���
	PushButton* addBtn;
	EditLine* addEdit;
	Table* addTable;
public://ɾ������ҳ��
	PushButton* delBtnOfID;
	//inline static PushButton* confirmBtn;
	//inline static PushButton* cancelBtn;
	Table* delTable;
	EditLine* delEditOfID;
	EditLine* delEditOfName;
	PushButton* delBtnOfName;
public://�������ݽ���
	PushButton* searchBtn;
	Table* searchTable;
	EditLine* searchEdit;
	std::vector<Empoyee> vec_modifyStaff;
public://�޸����ݽ���
	std::vector<PushButton*> option_btns;
private://��������
	std::vector<PushButton*> sort_btns;
};

