#pragma once

#include<iostream>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

//名字
#define NAME_MAX 20
//性别
#define SEX_MAX 5
//电话
#define TELE_MAX 15
//地址
#define ADDR_MAX 30

//初始能够存放的数据空间个数
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
enum Option//选项类型-->增加代码可读性
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

void save_stu(Contanct& contanct);
