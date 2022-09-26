/*
 * @lc app=leetcode.cn id=485 lang=cpp
 *
 * [485] 最大连续 1 的个数
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int count = 0, ret = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                count++;
            }
            else
            {
                ret = max(count, ret);
                count = 0;
            }
        }
        ret = max(count, ret);
        return ret;
    }
};
// @lc code=end
