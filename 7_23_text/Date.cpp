#include "Date.h"
#include<math.h>


ostream& operator<<(ostream& out, Date date) {
	out << date._year << " �� " << date._month << " �� " << date._day << " �� " << endl;
	return out;
}

Date::Date(int year, int month, int day)
{
    this->_year = year;
    this->_month = month;
    this->_day = day;
}

Date::Date(const Date& d)
{
    _year = d._year;
    _month = d._month;
    _day = d._day;
}

Date& Date::operator=(const Date& d)
{
    // TODO: �ڴ˴����� return ���
    _year = d._year;
    _month = d._month;
    _day = d._day;
    return *this;
}

Date::~Date()
{
    //...
}

Date& Date::operator+=(int day)
{
    // TODO: �ڴ˴����� return ���
    int newDay = _day + day;
    while (newDay > GetMonthDay(_year, _month)) {
        newDay -= GetMonthDay(_year, _month);
        _month++;
        if (_month == 13) {
            _month = 1;
            _year++;
        }
    }
    _day = newDay;
    return *this;
}

Date Date::operator+(int day)
{
    Date res(*this);
    res += day;
    return res;
}

Date Date::operator-(int day)
{
    Date res(*this);
    res -= day;
    return res;
}

Date& Date::operator-=(int day)
{
    // TODO: �ڴ˴����� return ���
    int newDay = _day - day;
    while (newDay < GetMonthDay(_year, _month)) {
        _month--;
        if (_month == 1) {
            _month = 12;
            _year--;
        }
        newDay += GetMonthDay(_year, _month);
    }
    _day = newDay;
    return *this;
}
//ǰ��++
Date& Date::operator++()
{
    // TODO: �ڴ˴����� return ���
    /*int newDay = _day + 1;
    if (newDay > GetMonthDay(_year, _month)) {
        newDay -= GetMonthDay(_year, _month);
        _month++;
        if (_month == 13) {
            _month = 1;
            _year++;
        }
    }
    _day = newDay;*/
    * this += 1;
    return *this;
}
//����++
Date Date::operator++(int)
{
    //int newDay = _day + 1;
    //if (newDay > GetMonthDay(_year, _month)) {
    //    newDay -= GetMonthDay(_year, _month);
    //    _month++;
    //    if (_month == 13) {
    //        _month = 1;
    //        _year++;
    //    }
    //}
    //_day = newDay;

    Date ret(*this);
    *this += 1;
    return ret;
}
//����--
Date Date::operator--(int)
{
    Date ret(*this);
    *this -= 1;
    return ret;
}
//ǰ��--
Date& Date::operator--()
{
    // TODO: �ڴ˴����� return ���
    *this -= 1;
    return *this;
}

bool Date::operator>(const Date& d)
{
    return _year > d._year ? true : _year < d._year ? false : 
        _month > d._month ? true : _month < d._month ? false : 
        _day > d._day ? true : false;
}

bool Date::operator==(const Date& d)
{
    return _year == d._year && _month == d._month && _day == d._day;
}

bool Date::operator>=(const Date& d)
{
    return *this == d || *this > d;
}

bool Date::operator<(const Date& d)
{
    return !(*this >= d);
}

bool Date::operator<=(const Date& d)
{
    return !(*this > d);
}

bool Date::operator!=(const Date& d)
{
    return !(*this == d);
}

int Date::operator-(const Date& d)
{
    if (*this == d) {
        return 0;
    }
    int count = 0;
    int nowDays = this->_GetMonthDay(_year, _month) + this->GetYearDay(_year) + this->_day;
    int toDays = _GetMonthDay(d._year, d._month) + GetYearDay(d._year) + d._day;
    return abs(nowDays - toDays);
}


