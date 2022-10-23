#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int main()
{
    int n = 0;
    scanf("%d", &n);
    vector<long long> human;
    for (int i = 0; i < 3 * n; i++)
    {
        long long tmp = 0;
        scanf("%lld", &tmp);
        human.push_back(tmp);
    }
    sort(human.begin(), human.end());
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += human[human.size() - 2 * (i + 1)];
    }
    cout << sum << endl;
    return 0;
}