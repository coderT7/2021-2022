#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include"workManager.h"
#include"worker.h"
#include"Manager.h"
#include"Boss.h"
#include"Empoyee.h"
int main()
{
	int choice = 0;
	workManager wM;
	while (true)
	{
		wM.showMenu();
		cin >> choice;
		switch (choice)
		{
		case Exit:
			wM.ExitSystem();
			break;
		case Add:
			wM.AddEmp();
			break;
		case DisPlay:
			wM.Show_Emp();
			break;
		case Del:
			wM.Del_Emp();
			break;
		case Modify:
			wM.Mod_Emp();
			break;
		case Search:
			wM.Find_Emp();
			break;
		case Sort:
			wM.Sort_Emp();
			break;
		case Formate:
			wM.Clean_File();
			break;
		default:
			cout << "输入有误，请重新输入" << endl;
			break;
			
		}
	}

	return 0;
}