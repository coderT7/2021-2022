// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem263.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=263 lang=cpp
 *
 * [263] 丑数
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isUgly(int n) {
        if(n <= 0){
            return false;
        }
        vector<int> factors = {2, 3, 5};
        for (int factor : factors) {
            while (n % factor == 0) {
                n /= factor;
            }
        }
        return n == 1;
    }
};
// @lc code=end

