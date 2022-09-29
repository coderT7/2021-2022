#pragma once

namespace m_std
{
    template <class Iterator, class Ref, class Ptr>
    struct __reverse_iterator
    {
        Iterator _cur;
        typedef __reverse_iterator<Iterator, Ref, Ptr> reverse_iterator;

        __reverse_iterator(Iterator it)
            : _cur(it)
        {
        }
        bool operator!=(const reverse_iterator &it) const
        {
            return it._cur != _cur;
        }
        bool operator==(const reverse_iterator &it) const
        {
            return it._cur == _cur;
        }
        Ref operator*()
        {
            Iterator tmp = _cur;
            --tmp;
            return *tmp;
        }
        Ptr operator->()
        {
            return &(operator*());
        }
        reverse_iterator operator++()
        {
            --_cur;
            return *this;
        }

        reverse_iterator operator++(int)
        {
            Iterator tmp = _cur;
            --_cur;
            return reverse_iterator(tmp);
        }
        reverse_iterator operator--()
        {
            ++_cur;
            return *this;
        }
        reverse_iterator operator--(int)
        {
            Iterator tmp = _cur;
            ++_cur;
            return reverse_iterator(tmp);
        }
    };
}