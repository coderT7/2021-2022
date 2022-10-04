#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minNumberInRotateArray(vector<int> rotateArray)
    {
        if (rotateArray.size() == 0)
        {
            return 0;
        }
        int left = 0;
        int right = rotateArray.size() - 1;
        int mid = 0;
        while (left < right)
        {
            if (right - left == 1)
            {
                mid = right;
                break;
            }
            mid = (left + right) >> 1;
            if (rotateArray[left] == rotateArray[mid] &&
                rotateArray[mid] == rotateArray[right])
            {
                int result = rotateArray[left];
                for (auto val : rotateArray)
                {
                    if (val < result)
                    {
                        result = val;
                    }
                }
                return result;
            }
            if (rotateArray[mid] >= rotateArray[left])
            {
                left = mid;
            }
            else
            {
                right = mid;
            }
        }
        return rotateArray[mid];
    }
};