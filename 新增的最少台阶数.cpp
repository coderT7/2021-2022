#define _CRT_SECURE_NO_WARNINGS 1

#include<vector>

class Solution {
public:
    int addRungs(std::vector<int>& rungs, int dist) {
        int res = 0;   // 需要增设的梯子数目
        int curr = 0;   // 当前高度
        for (int h : rungs) {
            // 遍历数组计算高度差和最少添加数目，并更新当前高度
            int d = h - curr;
            res += (d - 1) / dist;
            curr = h;
        }
        return res;
    }
};
