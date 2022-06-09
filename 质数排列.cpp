#define _CRT_SECURE_NO_WARNINGS 1


class Solution {
public:
    int numPrimeArrangements(int n) {
        // 100以内的 质数
        int primes[25] = { 2,3,5,7,11, 13,17,19,23, 29,31,37,41,43, 47,53,59,61,67, 71,73,79,83,89,97 };
        // 计算n范围内的质数的数量
        int pn = 0;
        for (int i = 0; i < 25; ++i)
        {
            if (primes[i] <= n)
            {
                ++pn;
            }
            else
            {
                break;
            }
        }

        long base = 1000000007;

        // 全排列: n! * (n-pn)!
        long res = 1;
        for (int i = 1; i <= pn; ++i)
        {
            res = (res * i) % base;
        }
        for (int i = 1; i <= (n - pn); ++i)
        {
            res = (res * i) % base;
        }

        return res;
    }
};