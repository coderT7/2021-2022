/*
 * @lc app=leetcode.cn id=389 lang=cpp
 *
 * [389] 找不同
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        int val = 0;
        for (int i = 0; i < s.size(); i++){
            val ^= s[i];
        }
        for (int i = 0; i < t.size(); i++){
            val ^= t[i];
        }
        return (char)val;
    }
};
// @lc code=end

