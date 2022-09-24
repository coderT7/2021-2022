/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string str = "aAeEiIoOuU";
    string reverseVowels(string s){
        int left = 0;
        int right = s.size() - 1;
        while(left < right){
            while(left < right && str.find(s[left]) == -1){
                left++;
            }
            while(left < right && str.find(s[right]) == -1){
                right--;
            }
            swap(s[left++], s[right--]);
        }
        return s;
    }
};
// @lc code=end

