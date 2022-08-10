#define _CRT_SECURE_NO_WARNINGS 1
#include<string.h>
#include<assert.h>
#include<iostream>
namespace m_std {
	class string {
		friend std::ostream& operator<<(std::ostream& out, m_std::string& str);
	public:
		typedef char* iterator;
		iterator begin() {
			return _str;
		}
		iterator end() {
			return _str + _size;
		}
	private:
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

