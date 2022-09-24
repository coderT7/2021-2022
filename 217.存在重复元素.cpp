// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem217.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */

// @lc code=start
#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>record;
        for(int val : nums){
            record[val]++;
        }
        for(auto& val : record){
            if(val.second > 1){
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

