#define _CRT_SECURE_NO_WARNINGS 1

#include"Date.h"

int main()
{
	Date date1(2010, 3, 11);
	Date date2(2023, 7, 24);
	//cout << (date1+4) << endl;
	//cout << (date1 + 40) << endl;
	//cout << (date1 + 400) << endl;
	//cout << (date1 + 4000) << endl;
	//date1 = date2 + 1;
	
	cout << date2 - date1;
	return 0;
}