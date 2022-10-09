/*
 * @lc app=leetcode.cn id=709 lang=cpp
 *
 * [709] 转换成小写字母
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string toLowerCase(string s) {
        string ret;
        for(char val : s){
            ret.push_back(tolower(val));
        }
        return ret;
    }
};
// @lc code=end

