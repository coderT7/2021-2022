#define _CRT_SECURE_NO_WARNINGS 1
#include<vector>

using namespace std;
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int cnt = 0;
        for (auto& x : arr1) {
            bool ok = true;
            for (auto& y : arr2) {
                ok &= (abs(x - y) > d);
            }
            cnt += ok;
        }
        return cnt;
    }
};

