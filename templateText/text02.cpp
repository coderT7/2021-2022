#include <bits/stdc++.h>
using namespace std;

template <class T1, class T2>
class Date
{
private:
    /* data */
public:
    Date() { cout << "Date<T1,T2>" << endl; }
};

template <class T1, class T2>
class Date<T1 *, T2 *>
{
private:
    /* data */
public:
    Date() { cout << "Date<T1*,T2*>" << endl; }
};
template <class T1>
class Data
{
public:
    Data() { cout << "Date<T1>" << endl; }
};
template <class T1>
class Data<T1 *>
{
private:
    /* data */
public:
    Data() { cout << "Date<T1*,T1*>" << endl; }
};
int main()
{
    Date<int, int> d1;
    Date<int *, int *> d2;
    return 0;
}
