#include"Boss.h"


Boss::Boss(int ID, string name, int dID)
{
	this->m_ID = ID;
	this->m_name = name;
	this->m_DeptID = dID;
}
//��ʾԱ����Ϣ
void Boss::showInfo()
{
	cout << "ְ����ţ�" << this->m_ID
		<< "\tְ��������" << this->m_name
		<< "\tְ����λ: " << this->getDeptName()
		<< "\tְ��ְ�𣺹���˾���ճ�����" << endl;
}
//��ȡ��λ����
string Boss::getDeptName()
{
	return string("�ϰ�");
}