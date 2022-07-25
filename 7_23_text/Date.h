#pragma once
#include<iostream>
using namespace std;
class Date
{
	friend ostream& operator<<(ostream& out, const Date& date);
	friend istream& operator>>(istream& in, Date& date);
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
	bool checkDate() {
		if (_year >= 1
			&& _month > 0 && _month < 13
			&& _day > 0 && _day < GetMonthDay(_year, _month)) {
			return true;
		}
		return false;
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
	Date operator+(int day) const;
	// 日期-天数
	Date operator-(int day) const;
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
	bool operator>(const Date& d) const;
	// ==运算符重载
	bool operator==(const Date& d) const;
	// >=运算符重载
	bool operator >= (const Date& d) const;
	// <运算符重载
	bool operator < (const Date& d) const;
	// <=运算符重载
	bool operator <= (const Date& d) const;
	// !=运算符重载
	bool operator != (const Date& d) const;
	// 日期-日期 返回天数
	int operator-(const Date& d) const;

private:
	int _year;
	int _month;
	int _day;
};


inline ostream& operator<<(ostream& out, const Date& date) {
	out << date._year << " 年 " << date._month << " 月 " << date._day << " 日 " << endl;
	return out;
}

inline istream& operator>>(istream& in, Date& date) {
	in >> date._year >> date._month >> date._day;
	if (!date.checkDate()) {
		cout << "输入日期非法" << endl;
	}
	return in;
}

