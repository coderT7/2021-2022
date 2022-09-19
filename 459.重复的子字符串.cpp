// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem459.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        return (s + s).find(s, 1) != s.size();
    }
};
                                   // @lc code=end
