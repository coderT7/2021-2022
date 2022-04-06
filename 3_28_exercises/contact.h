#pragma once

#include<iostream>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

//����
#define NAME_MAX 20
//�Ա�
#define SEX_MAX 5
//�绰
#define TELE_MAX 15
//��ַ
#define ADDR_MAX 30

//��ʼ�ܹ���ŵ����ݿռ����
#define  DEEAULT_MAX 4

typedef struct PeoInfo {
	char name[NAME_MAX];
	int num;
	int age;
	char sex[SEX_MAX];
	char address[ADDR_MAX];
	char phone[TELE_MAX];
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
	SAVE,//7
	DESTROY//8
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

void save_stu(Contanct& contanct);
