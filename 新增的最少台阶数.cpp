#define _CRT_SECURE_NO_WARNINGS 1

#include<vector>

class Solution {
public:
    int addRungs(std::vector<int>& rungs, int dist) {
        int res = 0;   // ��Ҫ�����������Ŀ
        int curr = 0;   // ��ǰ�߶�
        for (int h : rungs) {
            // �����������߶Ȳ�����������Ŀ�������µ�ǰ�߶�
            int d = h - curr;
            res += (d - 1) / dist;
            curr = h;
        }
        return res;
    }
};
