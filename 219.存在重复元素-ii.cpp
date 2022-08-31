// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem219.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> dictionary;
        int length = nums.size();
        for (int i = 0; i < length; i++) {
            int num = nums[i];
            if (dictionary.count(num) && i - dictionary[num] <= k) {
                return true;
            }
            dictionary[num] = i;
        }
        return false;
    }
};
// @lc code=end

