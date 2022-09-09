/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_set<int> s1, s2;
        for(int val : nums1){
            s1.insert(val);
        }
        for(int val : nums2){
            s2.insert(val);
        }
        for(int val : s1){
            if(s2.count(val)){
                ans.push_back(val);
            }
        }
        return ans;
    }
};
// @lc code=end

