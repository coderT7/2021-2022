// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem476.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=476 lang=cpp
 *
 * [476] 数字的补数
 */

// @lc code=start
class Solution
{
public:
    int findComplement(int num)
    {
        int s = -1;
        for (int i = 31; i >= 0; i--)
        {
            if (((num >> i) & 1) != 0)
            {
                s = i;
                break;
            }
        }
        int ans = 0;
        for (int i = 0; i < s; i++)
        {
            if (((num >> i) & 1) == 0)
                ans |= (1 << i);
        }
        return ans;
    }
};

                  // @lc code=end;
