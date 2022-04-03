#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
using namespace std;

class Entity {
private:
	int m_size;
	char* m_str;
public:

	Entity() {
		m_size = 0;
		m_str = new char[0];
	}

	Entity(const Entity& e) 
		:m_size(e.m_size)
	{
		//创建一块新内存
		m_str = new char[m_size];
		//将要拷贝的内存的数据复制到新内存里
		memcpy(m_str, e.m_str, sizeof(m_size + 1));
	}

	~Entity() {
		delete[] m_str;
	}
};


int main()
{
	Entity e1;
	Entity e2(e1);
	return 0;
}