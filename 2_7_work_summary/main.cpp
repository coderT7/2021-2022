#define _CRT_SECURE_NO_WARNINGS 1

#include"menu.h"
#include"All.h"

int main()
{
	int input = 0;
	do
	{
		menu* m = new all_menu;
		m->show_menu();
		cin >> input;
		m->get_enter(input);
		delete m;
	} while (input);
	return 0;
}