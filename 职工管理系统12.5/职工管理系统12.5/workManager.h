#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<iostream>
#include<fstream>
#include"worker.h"
#include"Boss.h"
#include"Empoyee.h"
#include"Manager.h"
using namespace std;
#define FILENAME "empFile.txt"

class workManager
{
public:
	//���캯���Ը�����г�ʼ��
	workManager();

	//��Ϊ
	//չʾ����
	void showMenu();
	//�˳�����
	void ExitSystem();
	//���Ա���ĺ���
	void AddEmp();
	//����Ա��������
	void Save();
	//����
	//��¼Ա��������
	int m_Empnum;
	//��¼ÿλԱ����Ϣ������
	//��̬���й��������ָ��ָ��������Ķ��󣩹ʴ洢ʱ��Ҫ�洢�����ָ�룬����Ҫ�ö���ָ����д洢
	worker **m_EmpArray;
	//�ж��ļ��Ƿ�Ϊ��
	bool m_FileIsEmpty;
	//ͳ���ļ��ﹲ�ж�����
	int get_Empnum();
	//��ʼ��ְ���ļ�
	void Init_Emp();
	//��ӡְ������Ϣ
	void Show_Emp();
	//ɾ��ְ������Ϣ
	void Del_Emp();
	//�жϸ�ְ���Ƿ����
	int Exist(int dID);
	//�޸�Ա����Ϣ
	void Mod_Emp();
	//����Ա��
	void Find_Emp();
	//����ְ��
	void Sort_Emp();
	//�������
	void Clean_File();

	//��������
	~workManager();
};

enum Choice
{
	Exit,
	Add,
	DisPlay,
	Del,
	Modify,
	Search,
	Sort,
	Formate
};

enum m_Worker
{
	m_Empoyee = 1,
	m_Manager,
	m_Boss
};