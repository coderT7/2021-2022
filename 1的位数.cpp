#define _CRT_SECURE_NO_WARNINGS 1

class Solution {
public:
    int hammingWeight(int n) {
        int ret = 0;
        for (int i = 0; i < 32; i++) {
            if (n & (1 << i)) {
                ret++;
            }
        }
        return ret;
    }
};