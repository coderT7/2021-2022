/*
 * @lc app=leetcode.cn id=231 lang=cpp
 *
 * [231] 2 的幂
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkPower(int n){
        int index = 0;
        while(true){
            if(pow(2,index) > n){
                return false;
            }else if(pow(2,index) == n){
                return true;
            }else{
                index++;
            }
        }
    }
    bool isPowerOfTwo(int n) {
        return checkPower(n);
    }
};
// @lc code=end

