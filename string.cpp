#define _CRT_SECURE_NO_WARNINGS 1
#include<string.h>
#include<assert.h>
#include<iostream>
#include<algorithm>
namespace m_std {
	class string {
		friend std::ostream& operator<<(std::ostream& out, const m_std::string& str);
		friend std::istream& operator>>(std::ifstream& in, m_std::string& str);
	public:
		typedef char* iterator;
		typedef const char* const_iterator;
		iterator begin() {
			return _str;
		}
		iterator end() {
			return _str + _size;
		}
		const_iterator begin() const{
			return _str;
		}
		const_iterator end() const{
			return _str + _size;
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	public:
		const static unsigned npos = -1;
	public:
		string(const char* str = ""){
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity+1];
			strcpy(_str, str);
		}
		//深拷贝(传统写法）
		//string(const string& s) 
		//	: _str(new char[s._capacity]),
		//	_size(s._size),
		//	_capacity(s._capacity)
		//{
		//	strcpy(_str, s._str);
		//}

		void swap(string& tmp) {
			std::swap(_str, tmp._str);
			std::swap(_size, tmp._size);
			std::swap(_capacity, tmp._capacity);
		}
		
		//拷贝构造现代写法（更简洁）->资本主义写法
		string(const string& s)
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			string tmp(s._str);//利用tmp的有参构造进行对象构造
			swap(tmp);
		}
		//string& operator=(const string& s) {
		//	if (this != &s) {
		//		_size = s._size;
		//		_capacity = s._capacity;
		//		char* tmp = new char[s._capacity + 1];
		//		delete[] _str;
		//		_str = tmp;
		//		strcpy(_str, s._str);
		//	}
		//	return *this;
		//}

		//现代写法
		//string& operator=(const string& s) {
		//	if (this == &s) {
		//		return *this;
		//	}
		//	string tmp(s);//利用tmp对象进行构造获得与s相同的内容，再与自身交换
		//	//tips：自定义类型调用std::swap(*this,s)时会涉及到（深）拷贝构造及赋值，会造成死循环或者极大的消耗
		//	swap(tmp);
		//	//tmp对象出了局部作用域后会自动调用delete[]释放原对象的空间
		//}

		//赋值运算更简洁的写法
		string& operator=(string s) {
			swap(s);
			return *this;
		}
		~string() {
			delete[] _str;
			_size = _capacity = 0;
		}
		size_t size()const {
			return _size;
		}
		const char& operator[](size_t pos) const {
			assert(pos < _size);
			return _str[pos];
		}
		char& operator[](size_t pos) {
			assert(pos < _size);
			return _str[pos];
		}
		const char* c_str() const{
			return _str;
		}

		void reserve(size_t n) {
			char* tmp = new char[n + 1];
			strcpy(tmp, _str);
			delete[] _str;
			_str = tmp;
			_capacity = n;
		}
		size_t size()const {
			return _size;
		};

		size_t capacity()const {
			return _capacity;
		}

		bool empty()const {
			return _size == 0;
		};

		void resize(size_t n, char c = '\0') {
			_size = n;
			for (size_t i = 0; i < _size; i++) {
				_str[i] = c;
			}
		}
		void push_back(const char& ch) {
			if (_size == _capacity) {
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}
			_str[_size] = ch;
			_str[++_size] = '\0';
		}
		void append(const char& ch) {
			if (_size == _capacity) {
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}
			push_back(ch);
		}
		void append(const char* s) {
			size_t len = strlen(s);
			if (_size + len > _capacity) {
				reserve(_size + len);
			}
			strcpy(_str + _size, s);
			_size += len;
		}
		string& operator+=(const char& ch) {
			push_back(ch);
			return *this;
		}
		string& operator+=(const char* s) {
			append(s);
			return *this;
		}
		void insert(size_t pos, const char& ch) {
			assert(pos <= _size);
			if (_size == _capacity) {
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}
			size_t end = _size + 1;
			while (pos < end) {
				_str[end] = _str[end - 1];
				end--;
			}
			_str[pos] = ch;
			_size++;
		}
		void insert(size_t pos, const char* s) {
			assert(pos <= _size);
			size_t len = strlen(s);
			if (_size + len > _capacity) {
				reserve(_size + len);
			}
			size_t end = _size + len;
			while (pos + len <= end) {
				_str[end] = _str[end - len];
				end--;
			}
			strncpy(_str + pos, s, len);
			_size += len;
		}
		void erase(size_t pos, size_t n = npos) {
			assert(pos < _size);
			if (n == npos || pos + n > _size) {
				_str[pos] = '\0';
				_size = pos;
				return;
			}
			size_t end = pos + n;
			strcpy(_str + pos, _str + end);
			_size -= n;
		}
		void clear() {
			_str[0] = '\0';
			_size = 0;
		}
		string substr(size_t pos = 0, size_t len = npos) {
			assert(pos < _size);
			if (len == npos || pos + len > _size) {
				string tmp;
				tmp.reserve(_capacity);
				strcpy(tmp._str, _str + pos);
				return tmp;
			}
			string tmp;
			for (size_t i = pos; i < pos + len; i++) {
				tmp += _str[i];
			}
			return tmp;
		}
		size_t find(const char& ch, size_t pos = 0)const {
			assert(pos < _size);
			for (size_t i = pos; i < _size; i++) {
				if (ch == _str[i]) {
					return i;
				}
			}
			return npos;
		}
		size_t find(const char* sub, size_t pos = 0)const {
			assert(sub);
			assert(pos < _size);
			const char* tmp = strstr(_str, sub);
			if (tmp == nullptr) {
				return npos;
			}
			return tmp - _str;
		}
		bool operator>(const string& s)const {
			return strcmp(_str,s._str) > 0;
		}
		bool operator>=(const string& s)const {
			return *this > s && *this == s;
		}
		bool operator<(const string& s)const {
			return !(*this >= s);
		}
		bool operator<=(const string& s)const {
			return !(*this > s);
		}
		bool operator==(const string& s)const {
			return !strcmp(_str, s._str);
		}
		bool operator!=(const string& s)const {
			return !(*this == s);
		}

	};
	std::ostream& operator<<(std::ostream& out, const m_std::string& str) {
		for (auto& ch : str) {
			out << ch;
		}
		return out;
	}
	
	std::istream& operator>>(std::istream& in, m_std::string& str) {
		str.clear();
		char ch;
		ch = in.get();
		const size_t N = 64;
		char buff[N];//类似于缓冲区，避免string空间开的过大导致浪费
		size_t i = 0;
		while (ch != ' ' && ch != '\n') {
			buff[i++] = ch;
			if (i == N - 1) {
				buff[i] = '\0';
				str += buff;
				i = 0;
			}
			ch = in.get();
		}
		buff[i] = '\0';
		str += buff;
		return in;
	}
	void text1(){
		string str("hello world");
		string::iterator it = str.begin();
		while (it != str.end()) {
			std::cout << *it;
			it++;
		}
		std::cout << std::endl;
	}
	void text2(){
		string str = "hello world";
		for (auto ch : str) {
			std::cout << ch;
		}
		std::cout << std::endl;
	}
	void text3() {
		string str = "hello world";
		for (int i = 0; i < str.size(); i++) {
			std::cout << str[i];
		}
	}
	void text4() {
		string str = "hell";
		str.append("ooo");
		std::cout << str << std::endl;
	}
	void text5() {
		string str = "hello ";
		str.insert(1, ' ');
		std::cout << str << std::endl;
	}
	void text6() {
		string str = "hello world";

		std::cout << str.find("world") << std::endl;
		std::cout << str.find('r') << std::endl;
		str.erase(6);
		std::cout << str << std::endl;
	}
	void text7() {
		string str = "hello world";
		std::cout << str.substr(6) << std::endl;
	}
	void text8() {
		string str1 = "hello world";
		string str2 = "hello world";
		std::cout << (str1 == str2) << std::endl;
		string str3 = "abcd";
		string str4 = "abc";
		
		std::cout << (str3 > str4) << std::endl;
		std::cout << (str4 < str2) << std::endl;
	}
}
int main()
{
	m_std::text8();
	return 0;
}

