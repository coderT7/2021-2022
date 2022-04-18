#define _CRT_SECURE_NO_WARNINGS 1


#include<cmath>

using namespace std;

class Solution {
public:
    int climbStairs_1(int n) {
        double sqrt5 = sqrt(5);
        double fibn = pow((1 + sqrt5) / 2, n + 1) - pow((1 - sqrt5) / 2, n + 1);
        return (int)round(fibn / sqrt5);
    }

    int climbStairs_2(int n) {
        int first = 0;
        int second = 0;
        int third = 1;
        for (int i = 1; i <= n; i++) {
            first = second;
            second = third;
            third = first + second;
        }
        return third;
    }
    int climbStairs_3(int n) {
        int* step = new int[n + 1];
        return _climbStairs(n, step);
    }
    int _climbStairs(int n, int step[]) {
        if (step[n] > 0) return step[n];
        if (n == 1) step[n] = 1;
        else if (n == 2) step[n] = 2;
        else  step[n] = _climbStairs(n - 1, step) + _climbStairs(n - 2, step);
        return step[n];
    }
};