/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>record;
        for(int i = 0; i < s.size(); i++){
            if(record.find(s[i]) == record.end()){
                for(auto& val : record){
                    if(val.second == t[i]){
                        return false;
                    }
                }
                record[s[i]] = t[i];

            }
        }
        string test;
        for(int i = 0; i < s.size(); i++){
            test += record.at(s[i]);
        }
        return test == t;
    }
};
// @lc code=end

