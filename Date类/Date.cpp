#include "Date.h"
#include<math.h>
int Date::GetMonthDay(int year, int month)
{
    int day[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    if (month == 2 && year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
        return 29;
    }
    else {
        return day[month];
    }
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
    // TODO: 在此处插入 return 语句
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
    // TODO: 在此处插入 return 语句
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
    int newDay = res._day + day;
    while (newDay > GetMonthDay(res._year, res._month)) {
        newDay -= GetMonthDay(res._year, res._month);
        res._month++;
        if (res._month == 13) {
            res._month = 1;
            res._year++;
        }
    }
    res._day = newDay;
    return res;
}

Date Date::operator-(int day)
{
    Date res(*this);
    int newDay = res._day - day;
    while (newDay < GetMonthDay(res._year, res._month)) {
        res._month--;
        if (res._month == 1) {
            res._month = 12;
            res._year--;
        }
        newDay += GetMonthDay(res._year, res._month);
    }
    res._day = newDay;
    return res;
}

Date& Date::operator-=(int day)
{
    // TODO: 在此处插入 return 语句
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
//前置++
Date& Date::operator++()
{
    // TODO: 在此处插入 return 语句
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
//后置++
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
//后置--
Date Date::operator--(int)
{
    Date ret(*this);
    *this -= 1;
    return ret;
}
//前置--
Date& Date::operator--()
{
    // TODO: 在此处插入 return 语句
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
    return *this == d || !(*this < d);
}

bool Date::operator<(const Date& d)
{
    return !(*this == d) && !(*this > d);
}

bool Date::operator<=(const Date& d)
{
    return *this == d || !(*this > d);
}

bool Date::operator!=(const Date& d)
{
    return !(*this == d);
}

int Date::operator-(const Date& d)
{
    return abs(this->_day - d._day);
}


