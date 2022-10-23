#include <bits/stdc++.h>

using namespace std;
string transNum(int m, int n, bool flag)
{
    string numStr;
    while (m)
    {
        int modNum = ((m % n) + abs(n)) % abs(n);
        if (modNum >= 10)
        {
            numStr += (modNum - 10 + 'A');
        }
        else
        {
            numStr += modNum + '0';
        }
        m -= modNum;
        m /= n;
    }
    reverse(numStr.begin(), numStr.end());
    return numStr;
}

int main()
{
    int M, N;
    cin >> M >> N;
    bool flag = false;
    if (M < 0)
    {
        M = -M;
        flag = true;
    }
    if (M < N)
        cout << M << endl;
    else
        cout << transNum(M, N, flag) << endl;
    return 0;
}