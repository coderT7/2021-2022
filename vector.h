#pragma once
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>

namespace m_std
{
    template <typename T>
    class vector
    {
    public:
        // Vector的迭代器是一个原生指针
        typedef T *iterator;
        typedef const T *const_iterator;

        iterator begin()
        {
            return _start;
        }
        iterator end()
        {
            return _finish;
        }
        const_iterator begin() const
        {
            return _start;
        }
        const_iterator end() const
        {
            return _finish;
        }
        // construct and destroy
        vector()
            : _start(nullptr), _finish(nullptr), _end_of_storage(nullptr)
        {
        }
        vector(size_t n, const T &value = T())
            : _start(nullptr), _finish(nullptr), _end_of_storage(nullptr)
        {
            reserve(n);
            for (size_t i = 0; i < n; i++)
            {
                this->push_back(value);
            }
        }
        vector(int n, const T &value = T())
            : _start(nullptr), _finish(nullptr), _end_of_storage(nullptr)
        {
            reserve(n);
            for (int i = 0; i < n; i++)
            {
                this->push_back(value);
            }
        }
        template <class InputIterator>
        vector(InputIterator first, InputIterator last)
            : _start(nullptr), _finish(nullptr), _end_of_storage(nullptr)
        {
            while (first != last)
            {
                push_back(*first);
                first++;
            }
        }
        void swap(vector<T> &v)
        {
            std::swap(v._start, _start);
            std::swap(v._finish, _finish);
            std::swap(v._end_of_storage, _end_of_storage);
        }
        vector(const vector<T> &v)
        {
            vector<T> tmp(v.begin(), v.end());
            swap(tmp);
        }
        // vector(const vector<T> &v)
        // {
        //     _start = new T(v.size());
        //     // memcpy(_start, v._start, sizeof(T) * v.size());
        //     for (size_t i = 0; i < v.size(); i++)
        //     {
        //         _start[i] = v._start[i];
        //     }
        //     _finish = _start + v.size();
        //     _end_of_storage = _start + v.size();
        // }
        vector<T> &operator=(vector<T> v)
        {
            swap(v);
            return *this;
        }
        ~vector()
        {
            delete[] _start;
            _start = _finish = _end_of_storage = nullptr;
        }
        // capacity
        size_t size() const
        {
            return _finish - _start;
        }
        size_t capacity() const
        {
            return _end_of_storage - _start;
        }
        bool empty()
        {
            return size() == 0;
        }
        void reserve(size_t n)
        {
            if (n > capacity())
            {
                size_t sz = size();
                T *tmp = new T[n];
                if (_start)
                {
                    // memcpy(tmp, _start, sizeof(T) *sz);
                    for (size_t i = 0; i < sz; i++)
                    {
                        tmp[i] = _start[i];
                    }
                }
                _start = tmp;
                _finish = _start + sz;
                _end_of_storage = _start + n;
            }
        }
        void resize(size_t n, const T &value = T())
        {
            if (n > capacity())
            {
                reserve(n);
            }
            if (n > size())
            {
                while (_finish < _start + n)
                {
                    *_finish = value;
                    _finish++;
                }
            }
            else
            {
                _finish = _start + n;
            }
        }
        ///////////////access///////////////////////////////
        T &operator[](size_t pos)
        {
            assert(pos <= size());
            assert(pos >= 0);
            return *(_start + pos);
        }
        const T &operator[](size_t pos) const
        {
            assert(pos <= size());
            assert(pos >= 0);
            return *(_start + pos);
        }
        ///////////////modify/////////////////////////////
        void push_back(const T &x)
        {
            if (capacity() == size())
            {
                reserve(capacity() == 0 ? 4 : capacity() * 2);
            }
            *_finish = x;
            _finish++;
        }
        void pop_back()
        {
            assert(size() > 0);
            _finish--;
        }

        iterator insert(iterator pos, const T &x)
        {
            assert(pos >= _start);
            assert(pos <= _finish);
            if (size() == capacity())
            {
                reserve(capacity() == 0 ? 4 : capacity() * 2);
            }
            iterator end = _finish - 1;
            while (end >= pos)
            {
                *(end + 1) = *end;
                end--;
            }
            *pos = x;
            _finish++;
            return pos;
        }
        iterator erase(iterator pos)
        {
            assert(pos >= _start);
            assert(pos <= _finish);

            iterator left = pos;
            iterator right = pos + 1;
            while (right != _finish)
            {
                *left = *right;
                right++;
                left++;
            }
            _finish--;
            return pos;
        }
        T &front()
        {
            assert(size() > 0);
            return *_start;
        }
        T &back()
        {
            assert(size() > 0);
            return *(_finish - 1);
        }
        ///////////////other/////////////////////////////

    private:
        iterator _start;          // 指向数据块的开始
        iterator _finish;         // 指向有效数据的尾
        iterator _end_of_storage; // 指向存储容量的尾
    };
    //构造函数、[]重载、pop_back()、empty()、reserve、push_back()
    void text01()
    {
        vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.push_back(4);
        v.push_back(5);
        for (auto val : v)
        {
            std::cout << val << " ";
        }
        std::cout << std::endl;
        for (int i = 0; i < v.size(); i++)
        {
            std::cout << v[i] << std::endl;
        }
        while (!v.empty())
        {
            v.pop_back();
        }
        std::cout << std::endl;
        std::cout << v.empty() << " " << v.capacity() << std::endl;
    }
    // insert、erase
    void text02()
    {
        vector<int> v;
        for (int i = 0; i < 10; i++)
        {
            v.push_back(i);
        }
        vector<int>::iterator it1 = std::find(v.begin(), v.end(), 3);
        v.insert(it1, 30);
        vector<int>::iterator it2 = std::find(v.begin(), v.end(), 7);
        v.erase(it2);
        for (auto val : v)
        {
            std::cout << val << " ";
        }
        /*vector<int>::iterator it = v.begin();
        while (it != v.end()) {
            if (*it % 2 == 0) {
                it = v.erase(it);
            }
            else {
                it++;
            }
        }
        for (auto val : v) {
            cout << val << " ";
        }*/
        std::cout << std::endl;
    }
}
