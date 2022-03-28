#pragma once

#include<iostream>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;


typedef struct PeoInfo {
	char name[20];
	int num;
	int age;
	char sex[10];
	char address[30];
	char phone[15];
}PeoInfo;

typedef struct Contanct {
	PeoInfo* info;
	int size;
	int capacity;
}Contanct;
enum Option//ѡ������-->���Ӵ���ɶ���
{
	EXIT,//0
	ADD,//1
	DEL,//2
	SEARCH,//3
	MODIFY,//4
	PRINT,//5
	SORT,//6
	SAVE//7
};
//��ʼ��ͨѶ¼
void init_contanct(Contanct& contanct);
//��ӡͨѶ¼
void print_contanct(Contanct& contanct);
//������ϵ��
void add_peoInfo(Contanct& contanct);
//ɾ����ϵ��
void del_peoInfo(Contanct& contanct);
//������ϵ��
bool search_peoInfo(Contanct& contanct, string name);
//�޸���ϵ��
void modify_peoInfo(Contanct& contanct);
//������ϵ��
void sort_peoInfo(Contanct& contanct);
//����ͨѶ¼
void destroy_contanct(Contanct& contanct);
