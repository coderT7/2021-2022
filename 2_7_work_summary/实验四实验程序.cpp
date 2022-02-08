#define _CRT_SECURE_NO_WARNINGS 1

#include"experiment_4th.h"

/*
1.һ��������������100����һ����ȫƽ�������ټ���168����һ����ȫƽ���������ʸ����Ƕ��٣�
2.Ϊʹ���ı��ܣ�������һ�����ɽ���ת�������룬�ձ����ٰ�Լ���Ĺ��ɽ������ԭ�ġ�
��Ӧ��ϵ���£�
abcdefghijklmnopqrstuvwxyz
efghijklmnopqrstuvwxyzabcd
ABCDEFGHIJKLMNOPQRSTUVWXYZ
EFGHIJKLMNOPQRSTUVWXYZABCD
��д����ʵ�����ϱ���ת����Ҫ�󣺷���ĸ�ַ�����ԭ״���䣻����һ���ַ���Ҫ���������Ӧ�����롣
3.�ж�101-200֮���ж��ٸ����������������������
Ҫ���ж������ú���ʵ�֡�
*/

void solve_equ(int)
{
	int x = 0;
	cout << "��������Ľ��Ϊ��";
	for (int i = 0; i < 100; i++)
		if (pow((int)sqrt(i + 100), 2) == (i + 100) && pow((int)sqrt(i + 268), 2) == (i + 268))
			cout << i;
	cout << endl;
	return;
}

void simple_encrypt()
{
	cout << "������Ҫ���ܵ��ַ�����";
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
	cout << "���ܺ���ַ�����" <<  arr << endl;
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
	cout << endl <<  "һ����" << count << "������" << endl;
}
void print_diamond()
{
	cout << "������Ҫ��ӡ�����ε���������󣩣�";
	int n = 0;
	cin >> n;
	if (!(n % 2))
	{
		cout << "������������" << endl;
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
5.��1+2!+3!+...+20!�ĺ͡�Ҫ�󣺽׳��ú���ʵ�֡�
6.���һ������ģ����Ӳ�ҵĲ��ԣ�����Ӳ��ͷ�����ϼ����µĴ����ͱ�����
ͨ��������ֵ��ģ����100�Σ�1000�κ�10000�ε������
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
	cout << "��������Ӳ�ҵĴ�����";
	int n = 0;
	cin >> n;
	int count = 0;
	for (int i = 0; i < n; i++)
		if (!(rand() % 2)) count++;
	cout << "Ӳ�����ϵĴ���Ϊ" << count << endl;
	cout << "Ӳ�����µĴ���Ϊ" << n - count << endl;
	cout << (count * 1.0 / n) * 100 << "%" << endl;
}
