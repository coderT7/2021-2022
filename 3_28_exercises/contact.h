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
enum Option//选项类型-->增加代码可读性
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
//初始化通讯录
void init_contanct(Contanct& contanct);
//打印通讯录
void print_contanct(Contanct& contanct);
//增加联系人
void add_peoInfo(Contanct& contanct);
//删除联系人
void del_peoInfo(Contanct& contanct);
//查找联系人
bool search_peoInfo(Contanct& contanct, string name);
//修改联系人
void modify_peoInfo(Contanct& contanct);
//排序联系人
void sort_peoInfo(Contanct& contanct);
//销毁通讯录
void destroy_contanct(Contanct& contanct);
