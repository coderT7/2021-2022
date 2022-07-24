#pragma once
#include<iostream>
using namespace std;

class Date
{
	friend ostream& operator<<(ostream& out, Date date);
public:
	// 获取某年某月的天数
	//放在类内实现作为inline
	int GetMonthDay(int year, int month) {
		static int day[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		if (month == 2 && year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
			return 29;
		}
		else {
			return day[month];
		}
	}
	int GetYearDay(int year) {
		static int day[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		int days = 0;
		while (year--) {
			for (int i = 1; i < 13; i++) {
				days += day[i];
			}
			if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
				days += 1;
			}
		}
		return days;
	}
	int _GetMonthDay(int year,int month) {
		static int day[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		int days = 0;
		while (month) {
			if (month == 2 && year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
				days += 29;
				month--;
				continue;
			}
			days += day[month--];
		}
		return days;
	}
	// 全缺省的构造函数
	Date(int year = 1900, int month = 1, int day = 1);
	// 拷贝构造函数
	// d2(d1)
	Date(const Date& d);
	// 赋值运算符重载
    // d2 = d3 -> d2.operator=(&d2, d3)
	Date& operator=(const Date& d);
	// 析构函数
	~Date();
	// 日期+=天数
	Date& operator+=(int day);
	// 日期+天数
	Date operator+(int day);
	// 日期-天数
	Date operator-(int day);
	// 日期-=天数
	Date& operator-=(int day);
	// 前置++
	Date& operator++();
	// 后置++
	Date operator++(int);
	// 后置--
	Date operator--(int);
	// 前置--
	Date& operator--();
	// >运算符重载
	bool operator>(const Date& d);
	// ==运算符重载
	bool operator==(const Date& d);
	// >=运算符重载
	bool operator >= (const Date& d);
	// <运算符重载
	bool operator < (const Date& d);
	// <=运算符重载
	bool operator <= (const Date& d);
	// !=运算符重载
	bool operator != (const Date& d);
	// 日期-日期 返回天数
	int operator-(const Date& d);

private:
	int _year;
	int _month;
	int _day;
};


