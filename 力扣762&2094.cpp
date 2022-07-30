#define _CRT_SECURE_NO_WARNINGS 1
#include<queue>
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void _findNum(vector<int>& v, int i, vector<int>& res, int num) {
        if (i == v.size()) {
            res.push_back(num);
            return;
        }
        int _num1 = num;
        _num1 = _num1 * 10 + v[i];
        _findNum(v, i + 1, res, _num1);
        int _num2 = num;
        _findNum(v, i + 1, res, _num2);
    }
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int>res;
        int i = 0, num = 0;
        _findNum(digits, i, res, num);
        for (auto it = res.begin(); it != res.end();) {
            if (*it / 100 == 0) {
                it = res.erase(it);
            }
            else if (*it % 2 != 0) {
                it = res.erase(it);
            }
            else {
                it++;
            }
        }
        return res;
    }
};
class Solution2{
public:
    bool isPrime(int n) {
        if (n == 1) return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for (int i = left; i <= right; i++) {
            if (isPrime(__builtin_popcount(i))) {
                ans++;
            }
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> v({ 2,1,3,0 });
    s.findEvenNumbers(v);
    return 0;
}