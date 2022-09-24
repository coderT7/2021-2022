/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int, int> hashMap1, hashMap2;
        for (int val : nums1){
            hashMap1[val]++;
        }
        for(int val : nums2){
            hashMap2[val]++;
        }
        for(auto& val : hashMap1){
            if(hashMap2.count(val.first)){
                int count = min(hashMap2[val.first], val.second);
                while(count--){
                    ans.push_back(val.first);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

