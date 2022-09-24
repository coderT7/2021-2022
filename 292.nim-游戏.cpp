/*
 * @lc app=leetcode.cn id=292 lang=cpp
 *
 * [292] Nim 游戏
 */

// @lc code=start
class Solution {
public:
    bool canWinNim(int n) {
        //由于己方先手，所以说当剩余石子大于或等于四块的倍数时自己拿完后对方总能赢
        //相反，若剩余石子不是四块的倍数，则先手总能赢
        return n % 4 != 0;
    }
};
// @lc code=end

