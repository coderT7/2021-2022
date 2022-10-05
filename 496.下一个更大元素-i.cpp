// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem496.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        int index1 = 0, index2 = 0;
        vector<int> ans;
        unordered_map<int, int> check;
        for (int i = 0; i < nums2.size(); i++)
        {
            check[nums2[i]] = i;
        }
        bool flag = false;
        while (index1 < nums1.size())
        {
            flag = false;
            int num = nums1[index1++];
            int i = check[num];
            while (i < nums2.size())
            {
                if (nums2[i] > num)
                {
                    flag = true;
                    ans.push_back(nums2[i]);
                    break;
                }
                ++i;
            }
            if(!flag){
                ans.push_back(-1);
            }
        }
        return ans;
    }
};
// @lc code=end
