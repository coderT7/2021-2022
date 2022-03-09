#define _CRT_SECURE_NO_WARNINGS 1

#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

class myGreater
{
public:
	bool operator()(int a, int b)
	{
		return a < b;
	}
};

int main()
{
	srand((unsigned int)time(NULL));
	vector<int> num;
	for (int i = 0; i < 10; i++)
		num.push_back(rand() % 10);
	make_heap(num.begin(), num.end(), myGreater());
	for (int i = 0; i < 10; i++)
		cout << num[i] << " ";
	
	return 0;
}