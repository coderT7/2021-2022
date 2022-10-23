#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int cnt = 0;
int fib(int n)
{

    cnt++;

    if (n == 0)
        return 1;
    else if (n == 1)
        return 2;
    else
        return fib(n - 1) + fib(n - 2);
}
void func(char **m)
{
    ++m;
    cout << *m << endl;
}
int fun1(int n)
{
    if (n == 5)
        return 2;
    else
        return 2 * fun1(n + 1);
}
int fun2(int x)
{
    int count = 0;
    while (x)
    {
        count++;
        x = x & (x - 1); //与运算
    }
    return count;
}

int main()
{

    static char *a[] = {"morning", "afternoon", "evening"};
    char **p = a;
    func(p);
    cout << fun1(2) << endl;
    cout << fun2(9999) << endl;
    fib(8);
    cout << cnt << endl;
    int m = 0123, n = 123;
    printf("%o,%o\n", m, n);
    return 0;
}