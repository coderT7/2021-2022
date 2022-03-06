#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<Windows.h>
#include<cstring>
#include<ctime>
#include<cstdio>
#include<vector>
#include<string>
using namespace std;
//// 计算Fibonacci的空间复杂度？
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
////由输出结果可知，这里的p默认指向的是空指针0x000000的位置
//int main()
//{
//	printf("%p\n", p + 0x1);//+0x1即+1，跳过了一个结构体大小，即+20（16进制即为14）
//	printf("%p\n", (unsigned long)p + 0x1);//强转成了一个无符号长整型+1即是数值上的加一
//	printf("%p\n", (unsigned int*)p + 0x1);//强转成无符号整型的指针，加一即跳过4个字节
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