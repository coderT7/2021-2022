// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem455.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int numOfChildren = g.size(), numOfCookies = s.size();
        int count = 0;
        for (int i = 0, j = 0; i < numOfChildren && j < numOfCookies; i++, j++)
        {
            while (j < numOfCookies && g[i] > s[j])
            {
                j++;
            }
            if (j < numOfCookies)
            {
                count++;
            }
        }
        return count;
    }
};

                                   // @lc code=end
