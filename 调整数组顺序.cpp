#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void reOrderArray(vector<int> &array)
    {
        int k = 0;
        for (int i = 0; i < array.size(); i++)
        {
            if ((array[i] & 1) == 1)
            {
                int tmp = array[i];
                int j = i;
                while (j > k)
                {
                    array[j] = array[j - 1];
                    j--;
                }
                array[k++] = tmp;
            }
        }
    }
};