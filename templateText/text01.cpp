#include <bits/stdc++.h>
using namespace std;
#include "Date.h"
#include "date.cpp"
namespace m_std
{
    template <class T>
    struct less
    {
        bool operator()(T l, T r)
        {
            return l < r;
        }
    };
    template<>
    struct less<Date*>
    {
        /* data */
        bool operator()(Date* l, Date* r)
        {
            return *l < *r;
        }
    };
    
}

int main()
{
    Date date1(2022, 7);
    Date date2(2022, 8);
    m_std::less<Date> min;
    cout << min(date1, date2) << endl;
    m_std::less<Date *> min2;
    cout << min2(&date1, &date2) << endl;
    return 0;
}