/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i = digits.size()-1; i >= 0; i--){
            digits[i] = (digits[i]+1) % 10;
            if(digits[i] != 0){
                return digits;
            }
        }
        digits.resize(digits.size()+1,0);
        digits[0] = 1;
        return digits;
    }
};

// @lc code=end

