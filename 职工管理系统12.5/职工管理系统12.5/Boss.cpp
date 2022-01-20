#include"Boss.h"


Boss::Boss(int ID, string name, int dID)
{
	this->m_ID = ID;
	this->m_name = name;
	this->m_DeptID = dID;
}
//显示员工信息
void Boss::showInfo()
{
	cout << "职工编号：" << this->m_ID
		<< "\t职工姓名：" << this->m_name
		<< "\t职工岗位: " << this->getDeptName()
		<< "\t职工职责：管理公司的日常事物" << endl;
}
//获取岗位名称
string Boss::getDeptName()
{
	return string("老板");
}