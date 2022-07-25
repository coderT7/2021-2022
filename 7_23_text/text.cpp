#define _CRT_SECURE_NO_WARNINGS 1

#include"Date.h"

int main()
{
	Date date1(2022, 7, 25);
	Date date2(2022, 1, 25);
	//cout << (date1+4) << endl;
	//cout << (date1 + 40) << endl;
	cout << (date1 + -100) << endl;
	//cout << (date1 + 4000) << endl;
	//date1 = date2 + 1;
	date1 = date2+4;
	cout << date1 << endl << date2 << endl;
	//cout << date1 - 400 << endl;
	return 0;
}