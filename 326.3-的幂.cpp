// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem326.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=326 lang=cpp
 *
 * [326] 3 的幂
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfThree(int n) {
        while (n && n % 3 == 0) {
            n /= 3;
        }
        return n == 1;
    }
};
// @lc code=end

