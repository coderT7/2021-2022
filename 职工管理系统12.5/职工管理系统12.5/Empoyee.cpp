#define _CRT_SECURE_NO_WARNINGS
#include"Empoyee.h"

Empoyee::Empoyee(int ID, string name, int dID)
{
	this->m_ID = ID;
	this->m_name = name;
	this->m_DeptID = dID;
}
//��ʾԱ����Ϣ
void Empoyee::showInfo()
{
	cout << "ְ����ţ�" << this->m_ID
		<< "\tְ��������" << this->m_name
		<< "\tְ����λ: " << this->getDeptName()
		<< "\tְ��ְ����ɾ����·�������" << endl;
}
//��ȡ��λ����
string Empoyee::getDeptName()
{
	return string("Ա��");
}