#define _CRT_SECURE_NO_WARNINGS 1

//�����������ж�����λ��ͬ�ĸ���
//#include <stdio.h>
//int main()
//{
//    int num1 = 0;
//    int num2 = 0;
//    int temp = 0;
//    int count = 0;
//    scanf("%d %d", &num1, &num2);
//    temp = num1 ^ num2;
//    while (temp)
//    {
//        count++;
//        temp = temp & (temp - 1);
//    }
//    printf("�������벻ͬλ�ĸ���Ϊ��%d\n", count);
//    return 0;
//}

#include<iostream>
using namespace std;
//����һ�������͵Ķ�����λ���м���1
//
//int binary_1(int n)
//{
//	int count = 0;
//	int flag = 1;
//	while (flag)
//	{
//		if (n & flag)
//			count++;
//		flag <<= 1;
//	}
//	return count;
//}
//int main()
//{
//	int n = 0;
//	cin >> n;
//	int ret = binary_1(n);
//	cout << ret;
//	return 0;
//}

//��������ʱ������������������
//�����ɣ���ͬΪ0������Ϊ1�����㽻����
//void swap(int* a, int* b)
//{
//	*a = *a ^ *b;
//	//��ʵ*b = *a ^ *b ^ *b = *a
//	*b = *a ^ *b;
//	//*a = *a ^ *b ^ *a
//	*a = *a ^ *b;
//}
//
//int main()
//{
//	int a, b;
//	cin >> a >> b;
//	swap(&a, &b);
//	cout << a << " " << b;
//	return 0;
//}

void binary_odd_even(int m)
{
	int i = 31;
	while (i >= 0)
	{
		cout << ((m >> i) & 1);
		i--;
	}
	cout << endl << "����λ��" << endl;
	for (i = 30; i >= 0; i -= 2)
	{
		cout << ((m >> i) & 1);
	}
	cout << endl << " ż��λ��" << endl;
	for (i = 31; i >= 1; i -= 2)
	{
		cout << ((m >> i) & 1);
	}
}
int main()
{
	int n = 0;
	cin >> n;
	binary_odd_even(n);
	return 0;
}
