#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<cmath>
#include<cstdlib>
using namespace std;

//int main()
//{
//	int arr[10] = { 0 };
//	for (int i = 0; i < 10; i++)
//		arr[i] = i;
//	int* p = arr;
//	for (int i = 0; i < 10; i++)
//		cout << *(p + i) << " ";
//	return 0;
//}

//void m_reverse(string& m_string)
//{
//	int begin = 0;
//	int end = m_string.size() - 1;
//	while (begin < end)
//	{
//		char tmp = m_string[begin];
//		m_string[begin] = m_string[end];
//		m_string[end] = tmp;
//		begin++;
//		end--;
//	}
//}
//
//int main()
//{
//	string m_string;
//	getline(cin, m_string);
//	m_reverse(m_string);
//	cout << m_string << endl;
//	return 0;
//}

//int m_sum(int a, int* i)
//{
//	if (!(*i))
//		return 0;
//	(* i)--;
//	return a + m_sum((a * 10) + a % 10, i);
//}
//
//int main()
//{
//	int a = 0, i = 0;
//	cin >> a >> i;
//	int ret = m_sum(a, &i);
//	cout << ret << endl;
//	return 0;
//}

//void narc_num(int* arr)
//{
//	int k = 0;
//	for (int i = 100; i < 1000; i++)
//	{
//		int sum = 0;
//		int tmp = i;
//		while (tmp)
//		{
//			sum += (int)pow(tmp % 10, 3);
//			tmp /= 10;
//		}
//		if (sum == i)
//			arr[k++] = i;
//	}
//}
//int main()
//{
//	int arr[10] = { 0 };
//	narc_num(arr);
//	for (int i = 0; i < 10; i++)
//		if (arr[i]) cout << arr[i] << " ";
//	return 0;
//}

int main()
{
	int n = 0;
	cin >> n;
	if (!(n % 2))
	{
		cout << "ÇëÊäÈëÆæÊý" << endl;
		exit(-1);
	}
	for (int i = 0; i < (n / 2) + 1; i++)
	{
		for (int j = 0; j < (n / 2) - i; j++)
			cout << " ";
		for (int k = 0; k < i * 2 + 1; k++)
			cout << "*";
		for (int j = 0; j < (n / 2) - i; j++)
			cout << " ";
		cout << endl;
	}
	for (int i = 0; i < (n / 2); i++)
	{
		for (int j = 0; j <= i; j++)
			cout << " ";
		for (int k = 0; k < n - i * 2 - 2; k++)
			cout << "*";
		for (int j = 0; j <= i; j++)
			cout << " ";
		cout << endl;
	}
	return 0;
}