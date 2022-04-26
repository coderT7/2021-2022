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
		//��©�˸�EXIT���п��ٲ�
		MENU = 10
	};
public:
	//������������
	Mangerment();
	void run();
	//�˵����������
	int menu();
	void display();
	void add();
	void erase();
	void modify();
	void search();
	//������
	void drawBackground();
	//�����¼�
	void event_loop();
	//����д�ļ�
	void readFile(const std::string& fileName);
	void saveFile(const std::string& fileName);

private://������������
	IMAGE m_bk;
	ExMessage m_msg;
	std::vector<PushButton*> menu_btns;
private://���ݵ��������
	std::string m_header;
	std::vector<Empoyee> vec_staff;
private://���
	Table* m_table;
};

