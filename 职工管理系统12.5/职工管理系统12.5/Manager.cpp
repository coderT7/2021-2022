#define _CRT_SECURE_NO_WARNINGS
#include"Manager.h"

Manager::Manager(int ID, string name, int dID)
{
	this->m_ID = ID;
	this->m_name = name;
	this->m_DeptID = dID;
}
//显示员工信息
void Manager::showInfo()
{
	cout << "职工编号：" << this->m_ID
		<< "\t职工姓名：" << this->m_name
		<< "\t职工岗位: " << this->getDeptName()
		<< "\t职工职责：完成老板下发的任务" << endl;
}
//获取岗位名称
string Manager::getDeptName()
{
	return string("经理");
}