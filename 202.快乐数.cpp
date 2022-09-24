/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int happy_num(int num){
        int ret = 0;
        while(num){
            ret += pow(num % 10,2);
            num /= 10;
        }
        return ret;
    }

    bool isHappy(int n) {
        unordered_set<int>record;
        while(n != 1 && record.find(n) == record.end()){
            record.insert(n);
            n = happy_num(n);
        }
        return n == 1;
    }
};
// @lc code=end

