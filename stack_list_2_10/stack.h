#define _CRT_SECURE_NO_WARNINGS 1
#pragma once

#include<cstdlib>
#include<iostream>

using namespace std;

typedef int SDataType;

typedef struct Stack
{
	SDataType val;
	int count;
	struct Stack* next;
}Stack;

void initStack(Stack& St);
int top(Stack& St);

void push(Stack& St, SDataType val);
void pop(Stack& St);
bool empty(Stack St);
int size(Stack St);