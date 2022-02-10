#define _CRT_SECURE_NO_WARNINGS 1

#include"stack.h"

int main()
{
	Stack St;
	initStack(St);
	push(St, 10);
	push(St, 20);
	push(St, 30);
	cout << top(St) << endl;
	pop(St);
	cout << top(St) << endl;
	pop(St);
	cout << top(St) << endl;
	pop(St);
	cout << top(St) << endl;
	pop(St);
	return 0;
}