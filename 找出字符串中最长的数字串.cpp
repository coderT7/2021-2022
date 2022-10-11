#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int main()
{
    int count = 0;
    string tmp = "", ret = "";
    string str;
    getline(cin, str);
    bool flag = true;
    for (int i = 0; i < str.size(); i++)
    {
        if (isdigit(str[i]))
        {
            tmp += str[i];
        }
        else
        {
            if (tmp == "")
            {
                continue;
            }
            else
            {
                ret = ret.size() < tmp.size() ? tmp : ret;
                tmp = "";
            }
        }
    }
    ret = ret.size() < tmp.size() ? tmp : ret;
    cout << ret << endl;
    return 0;
}