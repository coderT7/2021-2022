// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem67.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        int end1 = a.size() - 1;
        int end2 = b.size() - 1;
        string ans;
        int carry = 0;
        while(end1 >= 0 && end2 >= 0){
            int num = (a[end1]-'0' + b[end2]-'0' + carry);
            carry = num / 2;
            ans += to_string(num % 2);
            end1--;
            end2--;
        }
        while(end1 >= 0){
            int num = (a[end1] - '0' + carry);
            carry = num / 2;
            ans += to_string(num%2);
            end1--;
        }
        while(end2 >= 0){
            int num = (b[end2] - '0' + carry);
            carry = num / 2;
            ans += to_string(num%2);
            end2--;
        }
        if(carry != 0){
            ans += to_string(carry);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
// @lc code=end

