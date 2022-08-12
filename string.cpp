#define _CRT_SECURE_NO_WARNINGS 1
#include<string.h>
#include<assert.h>
#include<iostream>
namespace m_std {
	class string {
		friend std::ostream& operator<<(std::ostream& out, m_std::string& str);
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
	public:
		char* _str;
		size_t _size;
		size_t _capacity;
	public:
		string(const char* str = ""){
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity+1];
			strcpy(_str, str);
		}
		//Éî¿½±´
		string(const string& s) 
			: _str(new char[s._capacity]),
			_size(s._size),
			_capacity(s._capacity)
		{
			strcpy(_str, s._str);
		}
		string& operator=(const string& s) {
			if (this != nullptr) {
				this->_size = s._size;
				this->_capacity = s._capacity;
				this->_str = new char[s._capacity + 1];
				strcpy(_str, s._str);
				delete s._str;
			}
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


	};
	std::ostream& operator<<(std::ostream& out, m_std::string& str) {
		for (auto ch : str) {
			out << ch;
		}
		return out;
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
}
int main()
{
	m_std::text3();
	return 0;
}

