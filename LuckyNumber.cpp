#define _CRT_SECURE_NO_WARNINGS 1
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int findLucky(vector<int>& arr) {
        int max = arr[0];
        for (int val : arr) {
            if (val > max)
                max = val;
        }
        int* array = (int*)calloc(max + 1, sizeof(int));
        for (int val : arr) {
            array[val]++;
        }
        vector<int>ret;
        for (int i = 1; i <= max; i++) {
            if (i == array[i])
                ret.push_back(i);
        }
        int maxVal = ret[0];
        for (int val : ret) {
            if (val > maxVal)
                maxVal = val;
        }
        return maxVal;
    }
};
int main()
{
    Solution s1;
    vector<int>arr({ 2, 2, 3, 3, 3, 4 });
    int ret = s1.findLucky(arr);
    cout << ret << endl;
    return 0;
}