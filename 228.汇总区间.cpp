/*
 * @lc app=leetcode.cn id=228 lang=cpp
 *
 * [228] 汇总区间
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>ans;
        int left = 0, right = 0;
        int index = 0;
        while(index != nums.size()){
            string tmp = "";
            left = index;
            while(index < nums.size()-1 && nums[index]+1 == nums[index+1]){
                index++;
            }
            right = index;
            if(left == right){
                tmp += to_string(nums[left]);
                ans.push_back(tmp);
            }else{
                tmp += to_string(nums[left])+"->"+to_string(nums[right]);
                ans.push_back(tmp);
            }
            index++;
        }
        return ans;
    }
};
// @lc code=end

