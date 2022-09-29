#pragma once
#include <vector>
#include <deque>
using namespace std;
namespace m_std
{
    template <typename T, typename Container = deque<T>>
    class queue
    {
    public:
        void push(const T &x)
        {
            _con.push_back(x);
        }
        void pop()
        {
            _con.pop_front();
        }
        const T &back() const
        {
            return _con.back();
        }
        T &back()
        {
            return _con.back();
        }
        const T &front() const
        {
            return _con.front();
        }
        T &front()
        {
            return _con.front();
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
