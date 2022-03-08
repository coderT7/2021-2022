#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n, m, tmp;
    cin >> n >> m;
    vector<int> v1, v2, v;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v1.push_back(tmp);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> tmp;
        v2.push_back(tmp);
    }
    int begin1 = 0, begin2 = 0;
    while (begin1 < v1.size() && begin2 < v2.size())
    {
        if (v1[begin1] < v2[begin2])
            v.push_back(v1[begin1++]);
        else
            v.push_back(v2[begin2++]);
    }
    while (begin1 < v1.size())
        v.push_back(v1[begin1++]);
    while (begin2 < v2.size())
        v.push_back(v2[begin2++]);
    for (int i = 0; i < m + n; i++)
        cout << v[i] << " ";
    return 0;
}