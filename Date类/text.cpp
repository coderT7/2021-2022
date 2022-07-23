#define _CRT_SECURE_NO_WARNINGS 1

#include"Date.h"

int main()
{
	Date date1(2023, 7, 24);
	Date date2(2022, 9, 23);
	cout << (date1 > date2) << endl;

	return 0;
}