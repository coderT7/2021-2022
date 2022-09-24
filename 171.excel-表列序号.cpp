/*
 * @lc app=leetcode.cn id=171 lang=cpp
 *
 * [171] Excel 表列序号
 */

// @lc code=start
#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int num = 0;
        int index = columnTitle.size()-1;
        for(int i = 0; i < columnTitle.size(); i++){
            num = num+(columnTitle[i]-'A'+1)*pow(26,index--);
        }
        return num;
    }
};
// @lc code=end

