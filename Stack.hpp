#define _CRT_SECURE_NO_WARNINGS 1

#include<assert.h>
#include<string.h>
template<typename T>
class Stack
{
private:
	size_t _top;
	size_t _capacity;
	T* _ptr;
private:
	void check_capacity() {
		if (_top == _capacity) {
			size_t newCapacity = _capacity == 0 ? 4 : 2 * _capacity;
			T* tmp = new T[newCapacity];
			if (_ptr) {
				memcpy(tmp, _ptr, sizeof(T) * _capacity);
			}
			_ptr = tmp;
			_capacity = newCapacity;
		}
	}
public:
	Stack(size_t capacity = 4)
		:_top(0),_capacity(capacity),_ptr(nullptr)
	{
		if (capacity > 0) {
			_ptr = new T[_capacity];
		}
	}
	~Stack() {
		delete[] _ptr;
		_top = 0;
		_capacity = 0;
	}
	void push(const T& value) {
		check_capacity();
		_ptr[_top++] = value;
	}
	const T& top() {
		assert(_top != 0);
		return _ptr[_top - 1];
	}
	void pop() {
		assert(_top != 0);
		_top--;
	}
	bool empty() {
		return _top == 0;
	}
};