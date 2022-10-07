/*
 * @lc app=leetcode.cn id=521 lang=cpp
 *
 * [521] 最长特殊序列 Ⅰ
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findLUSlength(string a, string b) {
        if(a == b){
            return -1;
        }
        else
            return a.length() > b.length() ? a.length() : b.length();
    }
};
// @lc code=end

