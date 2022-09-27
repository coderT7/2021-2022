#pragma once
#include <iostream>
#include <assert.h>
namespace m_std
{
    template <typename T>
    struct list_node
    {
        T _data;
        list_node<T> *_prev;
        list_node<T> *_next;

        list_node(const T &x = T()) : _data(x),
                                      _prev(nullptr),
                                      _next(nullptr)
        {
        }
    };

    template <typename T, typename Ref, typename Ptr>
    struct __list_iterator
    {
        typedef list_node<T> Node;
        typedef __list_iterator<T, Ref, Ptr> iterator;

        __list_iterator(Node *node)
            : _node(node)
        {
        }
        bool operator!=(const iterator &it) const
        {
            return _node != it._node;
        }
        bool operator==(const iterator &it) const
        {
            return _node == it._node;
        }
        //重载解引用
        Ref operator*()
        {
            return _node->_data;
        }
        //重载->（自定义类型解引用）
        Ptr operator->()
        {
            //显式调用operator*()返回了_node->_data
            return &(operator*());
            //返回了迭代器包含的结点内 数据的地址
        }
        //重载前置,后置++以及--
        iterator &
        operator++()
        {
            _node = _node->_next;
            return *this;
        }
        iterator
        operator++(int)
        {
            iterator tmp = *this;
            _node = _node->_next;
            return tmp;
        }
        iterator &
        operator--()
        {
            _node = _node->_prev;
            return *this;
        }
        iterator &
        operator--(int)
        {
            iterator tmp = *this;
            _node = _node->_prev;
            return tmp;
        }

        Node *_node;
    };

    template <typename T>
    class list
    {
    private:
        typedef list_node<T> Node;

    public:
        typedef __list_iterator<T, T &, T *> iterator;
        typedef __list_iterator<T, const T &, const T *> const_iterator;
        const_iterator begin() const
        {
            return const_iterator(_head->_next);
        }
        const_iterator end() const
        {
            return const_iterator(_head);
        }

        iterator begin()
        {
            return iterator(_head->_next);
        }
        iterator end()
        {
            return iterator(_head);
        }
        void init_empty(){
            _head = new Node;
            _head->_next = _head;
            _head->_prev = _head;
        }
        list()
        {
            init_empty();
        }
        template <typename InputIterator>
        list(InputIterator first, InputIterator last)
        {
            init_empty();
            while (first != last)
            {
                push_back(*first);
                first++;
            }
        }
        list(const list<T>& x){
            init_empty();
            list<T> tmp(x.begin(), x.end());
            swap(tmp);
        }
        void swap(list<T>& x){
            std::swap(_head, x._head);
        }
        list<T> &operator=(list<T> x)
        {
            swap(x);
            return *this;
        }
        ~list()
        {
            clear();
            delete (_head);
        }

        void clear()
        {
            iterator it = begin();
            while (it != end())
            {
                it = erase(it);
            }
        }
        void push_back(const T &x)
        {
            // Node *newNode = new Node(x);
            // Node *tail = _head->_prev;
            // tail->_next = newNode;
            // newNode->_prev = tail;
            // newNode->_next = _head;
            // _head->_prev = newNode;
            insert(end(), x);
        }
        void push_front(const T &x)
        {
            insert(begin(), x);
        }
        iterator insert(iterator pos, const T &x)
        {
            // assert(pos != end());

            Node *cur = pos._node;
            Node *prev = cur->_prev;
            Node *newNode = new Node(x);

            prev->_next = newNode;
            newNode->_prev = prev;
            newNode->_next = cur;
            cur->_prev = newNode;

            return iterator(newNode);
        }
        iterator erase(iterator pos)
        {
            Node *cur = pos._node;
            Node *prev = cur->_prev;
            Node *next = cur->_next;

            prev->_next = next;
            next->_prev = prev;
            delete (cur);

            return iterator(next);
        }

    private:
        Node *_head;
    };
    void Func(const list<int>& l)
    {
        list<int>::const_iterator it = l.begin();
        while(it != l.end()){
            std::cout << *it << std::endl;
            // *it = 10; //无法修改，只读
            it++;
        }
    }
    void text03()
    {
        list<int> lt;
        lt.push_back(1);
        lt.push_back(2);
        lt.push_back(3);
        lt.push_back(4);
        lt.push_back(5);
        list<int> lt1(lt);
        for(auto val : lt1){
            std::cout << val << " ";
        }
        list<int> lt2;
        lt2 = lt1;
        for(auto val : lt2){
            std::cout << val << " ";
        }
    }
    void text02()
    {
        list<int> lt;
        lt.push_back(1);
        lt.push_back(2);
        lt.push_back(3);
        lt.push_back(4);
        lt.push_back(5);
        Func(lt);
    }
    void text01()
    {
        list<int> lt;
        lt.push_back(1);
        lt.push_back(2);
        lt.push_back(3);
        lt.push_back(4);
        lt.push_back(5);
        //本质是调用iterator的默认拷贝构造（浅拷贝）
        list<int>::iterator it = lt.begin();
        while (it != lt.end())
        {
            std::cout << *it << std::endl;
            *it *= 2;
            ++it;
        }
        lt.push_front(10);
        lt.push_front(11);
        lt.push_front(12);
        lt.push_front(13);
        lt.erase(lt.begin());
        for (auto val : lt)
        {
            std::cout << val << std::endl;
        }
    }
} // namespace m_std
