#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<iostream>
#include<string>
using namespace std;

//ְ���ĳ�����
class worker
{
public:
	//��ʾԱ����Ϣ
	virtual void showInfo() = 0;
	//��ȡ��λ����
	virtual string getDeptName() = 0;

	//ְ��������
	int m_ID;//ְ�����
	string m_name;//ְ������
	int m_DeptID;//��λ���
};