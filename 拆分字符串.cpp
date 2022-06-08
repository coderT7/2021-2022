#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> v;
        int len = s.size();
        for (int i = 0; i < len;) {
            string str = "";
            int count = k;
            while (count--) {
                if (i < len)
                    str += s[i];
                else
                    str += fill;
                i++;
            }
            v.push_back(str);
        }
        return v;
    }
};

int main()
{
    Solution s1;
    string s = "abcdefghi";
    
    for (auto val : s1.divideString(s, 3, 'x')) {
        cout << val << endl;
    }
    return 0;
}