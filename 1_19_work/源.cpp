#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"


//int sum(int a, int b)
//{
//	return a + b;
//}
//
//
//int main()
//{
//	int a = 0, b = 0;
//	cin >> a >> b;
//	int ret = sum(a, b);
//	cout << ret << endl;
//	return 0;
//}
//
//void print(int x)
//{
//	cout << x << " ";
//}
//
//class my_compare
//{
//public:
//	bool operator()(int a, int b)
//	{
//		return a > b;
//	}
//};
//int main()
//{
//	int a, b, c;
//	cin >> a >> b >> c;
//	vector<int> v1;
//	v1.push_back(a);
//	v1.push_back(b);
//	v1.push_back(c);
//	sort(v1.begin(), v1.end(),my_compare());
//	for_each(v1.begin(), v1.end(), print);
//	return 0;
//}

//void m_print()
//{
//	int n = 1;
//	while (n++ <= 100)
//		if (!(n % 3))
//			cout << n << " ";
//}
//
//int main()
//{
//	m_print();
//	return 0;
//}

//int m_div(int a, int b)
//{
//	if (a < b) swap(a, b);
//	int tmp = b;
//	while (tmp)
//	{
//		if (!(a % tmp) && !(b % tmp)) return tmp;
//		tmp--;
//	}
//	return 1;
//}
//
//int main()
//{
//	int a, b;
//	cin >> a >> b;
//	int ret = m_div(a, b);
//	cout << ret << endl;
//	return 0;
//}


//void leap_year()
//{
//	for (int i = 1000; i <= 2000; i++)
//	{
//		if ((!(i % 400)) || (!(i % 4) && (i % 100)))
//			cout << i << " ";
//	}
//}
//
//int main()
//{
//	leap_year();
//	return 0;
//}


//void prime_print()
//{
//	for (int i = 100; i <= 200; i++)
//	{
//		int flag = 0;
//		for (int j = 2; j <= sqrt(i); j++)
//			if (!(i % j))
//			{
//				flag = 1;
//				break;
//			}
//		if (!flag) cout << i << " ";
//			
//	}
//}
//
//int main()
//{
//	prime_print();
//	return 0;
//}

//int num_9()
//{
//	int count = 0;
//	for (int i = 1; i <= 100; i++)
//	{
//		if (i % 10 == 9) count++;
//		if (i / 10 == 9) count++;
//	}
//	return count;
//}
//
//int main()
//{
//	int ret = num_9();
//	cout << ret;
//	return 0;
//}

//float fra_sum()
//{
//	int flag = 1;
//	float sum = 0.0;
//	for (int i = 1; i <= 100; i++)
//	{
//		sum += flag * 1.0f / i;
//		flag = -flag;
//	}
//	return sum;
//}
//
//int main()
//{
//	float ret = fra_sum();
//	cout << ret << endl;
//	return 0;
//}
//
//void max_10(vector<int> &v)
//{
//	int MAX = v[0];
//	for (int i = 0; i < 10; i++)
//		if (v[i] > MAX) MAX = v[i];
//	cout << MAX;
//}
//
//int main()
//{
//	vector<int> v;
//	for (int i = 0; i < 10; i++)
//	{
//		int tmp = 0;
//		cin >> tmp;
//		v.push_back(tmp);
//	}
//	max_10(v);
//	return 0;
//}

//void mul_table()
//{
//	for (int i = 1; i < 10; i++)
//	{
//		for (int j = 1; j <= i; j++)
//			printf("%-2d* %-2d= %-4d", i, j, i * j);
//		cout << endl;
//	}
//}
//
//int main()
//{
//	mul_table();
//	return 0;
//}
//int main()
//{
//	int a = 0, b = 0;
//	for (a = 1, b = 1; a <= 100; a++)
//	{
//		if (b >= 20) break;
//		if (b % 3 == 1)
//		{
//			b = b + 3;
//			continue;
//		}
//		b = b - 5;
//	}
//	printf("%d\n", a);
//	return 0;
//}
//
//int bin_search(int* arr, int val, int len)
//{
//	int left = 0, right = len - 1;
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] == val) return mid;
//		else if (arr[mid] < val) left = mid + 1;
//		else right = mid - 1;
//	}
//	if (left > right)
//	{
//		printf("未找到该数值\n");
//		return 0;
//	}
//}
//
//int main()
//{
//	int arr[10] = { 0 };
//	for (int i = 0; i < 10; i++)
//		scanf("%d", &arr[i]);
//	int len = sizeof(arr) / sizeof(int);
//	int val = 0;
//	scanf("%d", &val);
//	int ret = bin_search(arr, val, len);
//	if (ret) printf("找到了，下标为：%d\n", ret);
//	return 0;
//}

//int main()
//{
//	srand((unsigned int)time(NULL));
//	game();
//	return 0;
//}
//int Fun(int n)
//{
//    if (n == 5)
//        return 2;
//    else
//        return 2 * Fun(n + 1);
//}
//int main()
//{
//    cout << Fun(2);
//    return 0;
//}
//
//void print(int n)
//{
//	if (n > 9)
//		print(n / 10);
//	printf("%d ", n % 10);
//}
//
//int main()
//{
//	int n = 1234;
//	print(n);
//	return 0;
//}

////递归
//int Fac1(int n)
//{
//	if (!n)
//		return 1;
//	return n * Fac1(n - 1);
//}
////非递归
//int Fac2(int n)
//{
//	int ret = 1;
//	for (int i = 1; i <= n; i++)
//		ret *= i;
//	return ret;
//}
//int main()
//{
//	int n = 0;
//	cin >> n;
//	int ret1 = Fac1(n);
//	cout << ret1 << endl;
//	int ret2 = Fac2(n);
//	cout << ret2 << endl;
//	return 0;
//}

////非递归
//int m_strlen1(const char *str)
//{
//	int count = 0;
//	while(*str)
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
////递归
//int m_strlen2(const char* str)
//{
//	if (!*str)
//		return 0;
//	return 1 + m_strlen2(str + 1);
//}
//int main()
//{
//	const char *str = "abcdef";
//	int ret1 = m_strlen1(str);
//	cout << ret1 << endl;
//	int ret2 = m_strlen1(str);
//	cout << ret2 << endl;
//	return 0;
//}

//
//int my_strlen(char* arr)
//{
//	if (!*arr)
//		return 0;
//	return 1 + my_strlen(arr + 1);
//}
//void reverse_string(char* m_string)
//{
//	if (*m_string)
//	{
//		int len = my_strlen(m_string);
//		char* begin = m_string;
//		char* end = m_string + len - 1;
//		char tmp = *begin;
//		*begin = *end;
//		*end = '\0';
//		reverse_string(m_string + 1);
//		*end = tmp;
//	}
//}
//int main()
//{
//	char arr[8] = "abcdefg";
//	cout << arr << endl;
//	reverse_string(arr);
//	cout << arr << endl;
//	return 0;
//}

//int sum = 0;
//int DigitSum(int n)
//{
//	if (n > 9)
//		DigitSum(n / 10);
//	return sum += n % 10;
//}
//
//int main()
//{
//	int n = 0;
//	cin >> n;
//	int ret = DigitSum(n);
//	cout << ret;
//	return 0;
//}

//递归实现n的k次方
//int Pow(int n, int k)
//{
//	if (!k)
//		return 1;
//	return n * Pow(n, k - 1);
//}
//
//int main()
//{
//	int n = 0, k = 0;
//	cin >> n >> k;
//	int ret = Pow(n, k);
//	cout << ret;
//	return 0;
//}

//非递归实现斐波那契数列
//int Fibonacci(int n)
//{
//	int a = 1, b = 1, c = 2;
//	if (n == 1 || n == 2) return 1;
//	while (n-- > 2)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//	}
//	return c;
//}
////递归实现斐波那契数列
//int Rec_Fibonacci(int n)
//{
//	if (n <= 2) return 1;
//	return Rec_Fibonacci(n - 1) + Rec_Fibonacci(n - 2);
//}
//int main()
//{
//	int n = 0;
//	cin >> n;
//	int ret = Fibonacci(n);
//	cout << ret << endl;;
//	int ret1 = Rec_Fibonacci(n);
//	cout << ret1 << endl;
//	return 0;
//}


//bool is_prime(int n)
//{
//	if (n == 1) return false;
//	for (int i = 2; i <= (int)sqrt(n); i++)
//		if (!(n % i)) return false;
//	return true;
//}
//int main()
//{
//	for (int i = 100; i <= 200; i++)
//		if (is_prime(i)) cout << i << " ";
//	return 0;
//}

//bool is_leap_year(int n)
//{
//	if (((n % 4 == 0) && (n % 100 != 0)) || (n % 400) == 0)
//		return true;
//	return false;
//}
//int main()
//{
//	int n = 0;
//	cin >> n;
//	if (is_leap_year(n))
//		cout << n << "年是闰年" << endl;
//	else
//		cout << n << "年不是闰年" << endl;
//	return 0;
//}

//void swap(int* a, int* b)
//{
//	int tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
//int main()
//{
//	int a, b;
//	cin >> a >> b;
//	cout << a << " " << b << endl;
//	swap(a, b);
//	cout << a << " " << b << endl;
//	return 0;
//}

void mul_table(int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
			printf("%-2d * %-2d = %-5d", i, j, i * j);
		printf("\n");
	}
}

int main()
{
	int n;
	cin >> n;
	mul_table(n);
	return 0;
}