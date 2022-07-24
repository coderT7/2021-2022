#pragma once
#include<iostream>
using namespace std;

class Date
{
	friend ostream& operator<<(ostream& out, Date date);
public:
	// ��ȡĳ��ĳ�µ�����
	//��������ʵ����Ϊinline
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
	// ȫȱʡ�Ĺ��캯��
	Date(int year = 1900, int month = 1, int day = 1);
	// �������캯��
	// d2(d1)
	Date(const Date& d);
	// ��ֵ���������
    // d2 = d3 -> d2.operator=(&d2, d3)
	Date& operator=(const Date& d);
	// ��������
	~Date();
	// ����+=����
	Date& operator+=(int day);
	// ����+����
	Date operator+(int day);
	// ����-����
	Date operator-(int day);
	// ����-=����
	Date& operator-=(int day);
	// ǰ��++
	Date& operator++();
	// ����++
	Date operator++(int);
	// ����--
	Date operator--(int);
	// ǰ��--
	Date& operator--();
	// >���������
	bool operator>(const Date& d);
	// ==���������
	bool operator==(const Date& d);
	// >=���������
	bool operator >= (const Date& d);
	// <���������
	bool operator < (const Date& d);
	// <=���������
	bool operator <= (const Date& d);
	// !=���������
	bool operator != (const Date& d);
	// ����-���� ��������
	int operator-(const Date& d);

private:
	int _year;
	int _month;
	int _day;
};


