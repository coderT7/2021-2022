/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start
#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> record;
        for(char val : magazine){
            record[val]++;
        }
        for (char val : ransomNote){
            if(!record.count(val) || record[val] == 0){
                return false;
            }else{
                record[val]--;
            }
        }
        return true;
    }
};
// @lc code=end

