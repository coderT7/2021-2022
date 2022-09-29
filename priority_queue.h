#pragma once
#include <vector>
#include <functional>
namespace m_std
{
    template <typename T>
    class less
    {
    public:
        bool operator()(const T &l, const T &r) const
        {
            return l < r;
        }
    };
    template <typename T>
    class greater
    {
    public:
        bool operator()(const T &l, const T &r) const
        {
            return l > r;
        }
    };
    template <typename T, typename Container = std::vector<int>, typename Compare = std::less<T>>
    class priority_queue
    {
    public:
        priority_queue(){}
        
        template<typename InputIterator>
        priority_queue(InputIterator first, InputIterator last)
        {
            while(first != last){
                _con.push_back(*first);
                first++;
            }
            for (int i = (_con.size() - 2) / 2; i >= 0; i--)
            {
                adjust_down(i);
            }
        }
        void adjust_up(size_t pos)
        {
            // Compare cmp;
            size_t child = pos;
            size_t parent = (child - 1) / 2;
            while (child > 0)
            {
                if (Compare()(_con[parent], _con[child]))
                {
                    std::swap(_con[child], _con[parent]);
                    child = parent;
                    parent = (child - 1) / 2;
                }
                else
                {
                    break;
                }
            }
        }
        void push(const T &x)
        {
            _con.push_back(x);
            adjust_up(_con.size() - 1);
        }
        void adjust_down(size_t pos)
        {
            // Compare cmp;
            size_t parent = pos;
            size_t child = parent * 2 + 1;
            while (child < _con.size())
            {
                if (child + 1 < _con.size() && Compare()(_con[child], _con[child + 1]))
                {
                    child++;
                }
                if (Compare()(_con[parent], _con[child]))
                {
                    std::swap(_con[child], _con[parent]);
                    parent = child;
                    child = parent * 2 + 1;
                }
                else
                {
                    break;
                }
            }
        }
        void pop()
        {
            std::swap(_con.front(), _con.back());
            _con.pop_back();
            adjust_down(0);
        }
        const T &top()
        {
            return _con[0];
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
        Container _con;
    };
} // namespace m_std
