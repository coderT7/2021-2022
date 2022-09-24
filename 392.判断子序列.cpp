/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s == "" && t == ""){
            return true;
        }
        int indexS = 0, indexT = 0;
        while(indexT < t.size()){
            if(s[indexS] == t[indexT]){
                indexT++;
                indexS++;
            }else{
                indexT++;
            }
            if(indexS == s.size()){
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

