#pragma once
#include <iostream>
namespace m_std
{
    template <typename T>
    struct list_node
    {
        T _data;
        list_node<T> *_prev;
        list_node<T> *_next;

        list_node(const T &x = T())
            : _data(x), _prev(nullptr), _next(nullptr)
        {
        }
    };

    template <typename T>
    struct __list_iterator
    {
        typedef list_node<T> Node;
        typedef __list_iterator<T> iterator;

        __list_iterator(Node *node)
            : _node(node)
        {
        }
        bool operator!=(const iterator &it) const
        {
            return _node != it._node;
        }
        //重载解引用
        T &operator*()
        {
            return _node->_data;
        }
        //重载前置++
        iterator &
        operator++()
        {
            _node = _node->_next;
            return *this;
        }

    private:
        Node *_node;
    };

    template <typename T>
    class list
    {
    private:
        typedef list_node<T> Node;

    public:
        typedef __list_iterator<T> iterator;
        iterator begin()
        {
            return head->_next;
        }
        iterator end()
        {
            return head;
        }
        list()
        {
            head = new Node();
            head->_next = head;
            head->_prev = head;
        }
        void push_back(const T &x)
        {
            Node *newNode = new Node(x);
            Node *tail = head->_prev;
            tail->_next = newNode;
            newNode->_prev = tail;
            newNode->_next = head;
            head->_prev = newNode;
        }

    private:
        Node *head;
    };

    void text01()
    {
        list<int> lt;
        lt.push_back(1);
        lt.push_back(2);
        lt.push_back(3);
        lt.push_back(4);

        list<int>::iterator it = lt.begin();
        while (it != lt.end())
        {
            std::cout << *it << std::endl;
            ++it;
        }
    }
} // namespace m_std
