#define _CRT_SECURE_NO_WARNINGS 1
#include<vector>
#include<iostream>
using namespace std;


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans(numRows);
        for (int i = 0; i < numRows; i++) {
            ans[i].resize(i + 1, 0);
            ans[i].front() = ans[i].back() = 1;
        }
        for (int i = 2; i < ans.size(); i++) {
            for (int j = 1; j < ans[i].size() - 1; j++) {
                if (ans[i][j] == 0) {
                    ans[i][j] = ans[i - 1][j] + ans[i - 1][j - 1];
                }
            }
        }
        return ans;
    }
};
