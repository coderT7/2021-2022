#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<Windows.h>
#include<cstring>
#include<ctime>
#include<cstdio>
#include<vector>
#include<string>
using namespace std;
//// ����Fibonacci�Ŀռ临�Ӷȣ�
//long long* Fibonacci(size_t n) {
//	if (n == 0)
//		return NULL;
//	long long* fibArray = (long long*)malloc((n + 1) * sizeof(long long));
//
//	fibArray[1] = 1;
//	for (int i = 2; i <= n; ++i)
//	{
//		fibArray[i] = fibArray[i - 1] + fibArray[i - 2];
//	}
//	return fibArray;
//}
//struct Test
//{
//	int num;//4
//	char* pcName;//4
//	short sDate;//2
//	char cha[2];//2
//	short sBa[4];//8
//}*p;
////����������֪�������pĬ��ָ����ǿ�ָ��0x000000��λ��
//int main()
//{
//	printf("%p\n", p + 0x1);//+0x1��+1��������һ���ṹ���С����+20��16���Ƽ�Ϊ14��
//	printf("%p\n", (unsigned long)p + 0x1);//ǿת����һ���޷��ų�����+1������ֵ�ϵļ�һ
//	printf("%p\n", (unsigned int*)p + 0x1);//ǿת���޷������͵�ָ�룬��һ������4���ֽ�
//	return 0;
//}

//int main()
//{
//    int arr[] = { 1,2,3,4,5 };
//    short* p = (short*)arr;
//    int i = 0;
//    for (i = 0; i < 4; i++)
//        *(p + i) = 0;
//
//    for (i = 0; i < 5; i++)
//        printf("%d ", arr[i]);
//    return 0;
//}

void reverse(string& str, int start, int end) 
{
    while (start < end) {
        swap(str[start], str[end]);
        start += 1;
        end -= 1;
    }
}
int main()
{
    string str;
    cin >> str;
    int k = 0;
    cin >> k;
    k %= str.size();
    reverse(str, 0, str.size() - 1);
    reverse(str, 0, str.size() - k - 1);
    reverse(str, str.size() - k, str.size() - 1);
    cout << str;
    return 0;
}