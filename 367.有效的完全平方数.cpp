/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
class Solution {
public:
    bool isPerfectSquare(int num) {
        for (long long i = 1; i <= num; i++){
            if(i*i == num){
                return true;
            }else if(i * i > num){
                return false;
            }
        }
        return false;
    }
};
// @lc code=end

