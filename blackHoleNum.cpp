#include <bits/stdc++.h>
using namespace std;

static int min[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
static int max[] = {9, 99, 999, 9999, 99999, 999999, 9999999, 99999999, 999999999};
bool isBlackHoleNum(int num)
{
    string max = to_string(num);
    string min = max;
    sort(max.begin(), max.end(), greater<char>());
    sort(min.begin(), min.end(), less<char>());
    int minNum = stoi(min);
    int maxNum = stoi(max);
    return (maxNum - minNum) == num;
}
int main()
{
    int n = 0;
    cout << "请输入要输出的黑洞数是几位数：";
    cin >> n;
    if (n < 0 || n > 9)
    {
        exit(-1);
    }
    bool flag = false;
    //输入2，从10-99的范围；输入3，从100-999的范围...以此类推
    for (int i = ::min[n-1]; i <= ::max[n-1]; i++)
    {
        if (isBlackHoleNum(i))
        {
            cout << i << " ";
            flag = true;
        }
    }
    if(!flag){
        cout << "无对应位数的黑洞数" << endl;
    }
    return 0;
}