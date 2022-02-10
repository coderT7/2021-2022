#define _CRT_SECURE_NO_WARNINGS 1
#include"stack.h"

void initStack(Stack& St)
{
	St.count = 0;
	St.next = NULL;
	St.val = 0;
}
int top(Stack& St)
{
	if (!empty(St))
	{
		cout << "栈中无数据" << endl;
		return 0;
	}
	else
		return St.next->val;
}
static Stack* buyNewNode(SDataType val)
{
	Stack* newnode = new Stack;
	newnode->next = NULL;
	newnode->count = 0;
	newnode->val = val;
	return newnode;
}
void push(Stack& St, SDataType val)
{
	Stack * newnode = buyNewNode(val);
	Stack* tmp = St.next;
	St.next = newnode;
	newnode->next = tmp;
	St.count++;
	cout << "插入" << val << "成功" << endl;
}
void pop(Stack& St)
{
	if (empty(St))
	{
		Stack* tmp = new Stack;
		tmp = St.next;
		St.next = St.next->next;
		cout << "出栈成功，出栈的数据为：" << tmp->val << endl;
		St.count--;
		free(tmp);
	}
	else
	{
		cout << "当前栈为空" << endl;
		return;
	}
}
bool empty(Stack St)
{
	return St.count;
}
int size(Stack St)
{
	return St.count;
}