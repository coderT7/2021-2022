#pragma once
#include<iostream>
using namespace std;
class Date
{
	friend ostream& operator<<(ostream& out, const Date& date);
	friend istream& operator>>(istream& in, Date& date);
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
	bool checkDate() {
		if (_year >= 1
			&& _month > 0 && _month < 13
			&& _day > 0 && _day < GetMonthDay(_year, _month)) {
			return true;
		}
		return false;
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
	Date operator+(int day) const;
	// ����-����
	Date operator-(int day) const;
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
	bool operator>(const Date& d) const;
	// ==���������
	bool operator==(const Date& d) const;
	// >=���������
	bool operator >= (const Date& d) const;
	// <���������
	bool operator < (const Date& d) const;
	// <=���������
	bool operator <= (const Date& d) const;
	// !=���������
	bool operator != (const Date& d) const;
	// ����-���� ��������
	int operator-(const Date& d) const;

private:
	int _year;
	int _month;
	int _day;
};


inline ostream& operator<<(ostream& out, const Date& date) {
	out << date._year << " �� " << date._month << " �� " << date._day << " �� " << endl;
	return out;
}

inline istream& operator>>(istream& in, Date& date) {
	in >> date._year >> date._month >> date._day;
	if (!date.checkDate()) {
		cout << "�������ڷǷ�" << endl;
	}
	return in;
}

