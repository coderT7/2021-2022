#define _CRT_SECURE_NO_WARNINGS
#include"Manager.h"

Manager::Manager(int ID, string name, int dID)
{
	this->m_ID = ID;
	this->m_name = name;
	this->m_DeptID = dID;
}
//��ʾԱ����Ϣ
void Manager::showInfo()
{
	cout << "ְ����ţ�" << this->m_ID
		<< "\tְ��������" << this->m_name
		<< "\tְ����λ: " << this->getDeptName()
		<< "\tְ��ְ������ϰ��·�������" << endl;
}
//��ȡ��λ����
string Manager::getDeptName()
{
	return string("����");
}