#pragma once
#include"Window.h"
class Mangerment
{
	enum Option {
		ADD,
		ERASE,
		MODIFY,
		SEARCH,
		MENU
	};
public:
	void run();
	
	int menu();
	void display();
	void add();
	void erase();
	void modify();
	void search();

private:
	ExMessage m_msg;
};

