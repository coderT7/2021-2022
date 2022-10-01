#pragma once
#include <vector>
#include<deque>
using namespace std;
namespace m_std
{
    template <typename T, typename Container = deque<T>>
    class stack
    {
    public:
        void push(const T &x)
        {
            _con.push_back(x);
        }
        void pop()
        {
            _con.pop_back();
        }
        const T &top() const
        {
            return _con.front();
        }
        T &top()
        {
            return _con.back();
        }
        size_t size() const
        {
            return _con.size();
        }
        bool empty() const
        {
            return _con.empty();
        }

    private:
        // vector<T> _con;
        Container _con;
    };
} // namespace m_std
