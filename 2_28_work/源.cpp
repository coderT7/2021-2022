#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
using namespace std;

//int main()
//{
//	vector<int> v;
//	for(int i1 = 1; i1 <= 9; i1++)
//	for(int i2 = 1; i2 <= 9; i2++)
//	for(int i3 = 1; i3 <= 9; i3++)
//	for (int i4 = 1; i4 <= 9; i4++)
//	for (int i5 = 1; i5 <= 9; i5++)
//	for (int i6 = 1; i6 <= 9; i6++)
//	for (int i7 = 1; i7 <= 9; i7++)
//	for (int i8 = 1; i8 <= 9; i8++)
//		for (int i9 = 1; i9 <= 9; i9++)
//		{
//			int n1 = 0, n2 = 0, n3 = 0;
//			if (i1 != i2 && i2 != i3 && i1 != i3
//				&& i4 != i5 && i5 != i6 && i4 != i6
//				&& i7 != i8 && i8 != i9 && i7 != i9
//				&& i1 != i4 && i1 != i5 && i1 != i6
//				&& i2 != i4 && i2 != i5 && i2 != i6
//				&& i3 != i4 && i3 != i5 && i3 != i6
//				&& i1 != i7 && i1 != i8 && i1 != i9
//				&& i2 != i7 && i2 != i8 && i2 != i9
//				&& i3 != i7 && i3 != i8 && i3 != i9
//				&& i4 != i7 && i4 != i8 && i4 != i9
//				&& i5 != i7 && i5 != i8 && i5 != i9
//				&& i6 != i7 && i6 != i8 && i6 != i9)
//			{
//				n1 = i1 * 100 + i2 * 10 + i3;
//				n2 = i4 * 100 + i5 * 10 + i6;
//				n3 = i7 * 100 + i8 * 10 + i9;
//				if (n2 == 2 * n1 && n3 == 3 * n1)
//				{
//					cout << n1 << " " << n2 << " " << n3;
//					cout << endl;
//				}
//			}
//				
//		}
//	return 0;
//}

//int main()
//{
//	int a[9] = { 0 };
//	for (int i = 0; i < 9; i++)
//	{
//		for (int k = 1; k < 10; k++)
//		{
//			a[i] = k;
//			int b = i;//判断是否重复
//			while (b >= 0)
//			{
//				if (a[i] != a[b])
//					b--;
//				else
//				{
//					a[i]++;
//					b = i;
//				}
//			}
//		}
//		int m = a[0] * 100 + a[1] * 10 + a[2];
//		int n = a[3] * 100 + a[4] * 10 + a[5];
//		int l = a[6] * 100 + a[7] * 10 + a[8];
//		if (n == 2 * m && l == 3 * m)
//		{
//			for (int t = 0; t < 9; t++)
//			{
//				cout << a[t] << " ";
//				if ((t + 1) % 3 == 0)
//					cout << endl;
//			}
//		}
//	}
//	return 0;
//}

//int main()
//{
//	for(int i1 = 1; i1 <= 9; i1++)//s
//	for(int i2 = 0; i2 <= 9; i2++)//e
//	for(int i3 = 0; i3 <= 9; i3++)//n
//	for (int i4 = 0; i4 <= 9; i4++)//d
//	for (int i5 = 1; i5 <= 9; i5++)//m
//	for (int i6 = 0; i6 <= 9; i6++)//o
//	for (int i7 = 0; i7 <= 9; i7++)//r
//		for (int i8 = 0; i8 <= 9; i8++)//y
//		{
//			if(i1 != i2 && i2 != i3 && i3 != i4 && i1 != i4 && i1 != i3 && i2 != i4
//				&& i5 != i6 && i6 != i7  && i7 != i8 && i5 != i8 && i5 != i7 && i6 != i2
//				&& i1 != i7 && i3 != i7 && i4 != i7 && i6 != i8)
//			if ((i1 * 1000 + i2 * 100 + i3 * 10 + i4) + (i5 * 1000 + i6 * 100 + i7 * 10 + i2)
//				== i5 * 10000 + i6 * 1000 + i3 * 100 + i2 * 10 + i8)
//				cout << "send:" << i1 << " " << i2 << " " << i3 << " " << i4 << " "
//				<< "more:" << i5 << " " << i6 << " " << i7 << " " << i2 << endl << "money:" 
//				<< i5 * 10000 + i6 * 1000 + i3 * 100 + i2 * 10 + i8 << endl;
//		}
//	return 0;
//}

int main()
{
	int a = 1;//内存中存入一个整型1
	char* p = (char*) & a;//进行解引用访问，char类型指针只能访问一个字节
	cout << (int) * p;//由于访问是从低地址开始访问的，若为小端字节序，则值为1
	//若为大端字节序，由于低位数据存在高地址，所以解引用应该访问的是0
	return 0;
}