#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<list>
#include<vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return -1;
        }
        int n = nums.size() - 1;
        if (n == 0) {
            return nums[0] == target ? 0 : -1;
        }
        int l = 0, r = n;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[0] <= nums[mid]) {
                // ��������
                if (nums[0] <= target && target <= nums[mid]) {
                    // target��ֵ������
                    r = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }
            else {
                b
                    // �Ұ������
                    if (nums[mid] <= target && target <= nums[n]) {
                        // target��ֵ���Ұ��
                        l = mid + 1;
                    }
                    else {
                        r = mid - 1;
                    }
            }
        }
        return -1;
    }
};
