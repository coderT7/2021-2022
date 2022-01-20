#define _CRT_SECURE_NO_WARNINGS
#include"Empoyee.h"

Empoyee::Empoyee(int ID, string name, int dID)
{
	this->m_ID = ID;
	this->m_name = name;
	this->m_DeptID = dID;
}
//显示员工信息
void Empoyee::showInfo()
{
	cout << "职工编号：" << this->m_ID
		<< "\t职工姓名：" << this->m_name
		<< "\t职工岗位: " << this->getDeptName()
		<< "\t职工职责：完成经理下发的任务" << endl;
}
//获取岗位名称
string Empoyee::getDeptName()
{
	return string("员工");
}