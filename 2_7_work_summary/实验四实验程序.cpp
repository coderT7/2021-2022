#define _CRT_SECURE_NO_WARNINGS 1

#include"experiment_4th.h"

/*
1.一个整数，它加上100后是一个完全平方数，再加上168又是一个完全平方数，请问该数是多少？
2.为使电文保密，往往按一定规律将其转换成密码，收报人再按约定的规律将其译回原文。
对应关系如下：
abcdefghijklmnopqrstuvwxyz
efghijklmnopqrstuvwxyzabcd
ABCDEFGHIJKLMNOPQRSTUVWXYZ
EFGHIJKLMNOPQRSTUVWXYZABCD
编写程序，实现以上保密转换，要求：非字母字符保持原状不变；输入一行字符，要求输出其相应的密码。
3.判断101-200之间有多少个素数，并输出所有素数。
要求：判断素数用函数实现。
*/

void solve_equ(int)
{
	int x = 0;
	cout << "满足题意的结果为：";
	for (int i = 0; i < 100; i++)
		if (pow((int)sqrt(i + 100), 2) == (i + 100) && pow((int)sqrt(i + 268), 2) == (i + 268))
			cout << i;
	cout << endl;
	return;
}

void simple_encrypt()
{
	cout << "请输入要加密的字符串：";
	char arr[100] = { 0 };
	scanf("%s", arr);
	int len = (int)strlen(arr);
	len -= 1;
	while (len >= 0)
	{
		if ((arr[len] >= 'a' && arr[len] <= 'v') || (arr[len] >= 'A' && arr[len] <= 'V'))
			arr[len] += 4;
		else if((arr[len] >= 'w' && arr[len] <= 'z') || (arr[len] >= 'W' && arr[len] <= 'Z'))
			arr[len] -= 22;
		len--;
	}
	cout << "加密后的字符串：" <<  arr << endl;
}

bool is_prime(int n)
{
		for (int j = 2; j <= (int)sqrt(n); j++)
			if (!(n % j)) return false;
		return true;
}
void m_prime()
{
	int count = 0;
	for (int i = 101; i <= 200; i++)
	{
		if (is_prime(i))
		{
			count++;
			cout << i << " ";
		}
	}
	cout << endl <<  "一共有" << count << "个素数" << endl;
}
void print_diamond()
{
	cout << "请输入要打印的菱形的行数（多大）：";
	int n = 0;
	cin >> n;
	if (!(n % 2))
	{
		cout << "请输入奇数！" << endl;
		return;
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
}
/*
5.求1+2!+3!+...+20!的和。要求：阶乘用函数实现。
6.设计一个程序，模拟抛硬币的测试，计算硬币头像向上及向下的次数和比例。
通过输入数值，模拟抛100次，1000次和10000次的情况。
*/
long long fac(int n)
{
	return !n ? 1 : n * fac(n - 1);
}
void fac()
{
	long long sum = 0;
	for (int i = 1; i <= 20; i++)
		sum += fac(i);
	cout << sum << endl;
}
void probability()
{
	srand((unsigned int)time(NULL));
	cout << "请输入抛硬币的次数：";
	int n = 0;
	cin >> n;
	int count = 0;
	for (int i = 0; i < n; i++)
		if (!(rand() % 2)) count++;
	cout << "硬币向上的次数为" << count << endl;
	cout << "硬币向下的次数为" << n - count << endl;
	cout << (count * 1.0 / n) * 100 << "%" << endl;
}
