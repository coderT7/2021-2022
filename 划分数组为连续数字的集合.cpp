#define _CRT_SECURE_NO_WARNINGS 1
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;
class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if (nums.empty()) {
            return false;
        }
        if (nums.size() % k != 0) {
            return false;
        }
        //将数组进行排序，以便于每次都找到最小的那个数
        sort(nums.begin(), nums.end());
        //将数组中的数在哈希表中记录个数
        unordered_map<int, int> record;
        for (auto& num : nums) {
            record[num]++;
        }
        //遍历整个数组
        for (auto& x : nums) {
            //如果当前元素在哈希表中不存在了，则说明可能在上一组中已经用过了且减为0了，则跳过这个数即可
            if (!record.count(x)) {
                continue;
            }
            //看从当前这个最小的数开始，能否组成一个k个数的序列
            for (int i = 0; i < k; i++) {
                int tmp = x + i;
                //如果tmp在哈希表中不存在，说明该数在数组中不存在
                if (!record.count(tmp)) {
                    return false;
                }
                //如果存在，则对应记录减一
                record[tmp]--;
                //如果减一后记录为0，则该数可以移除哈希表
                if (record[tmp] == 0) {
                    record.erase(tmp);
                }
            }
        }
        return true;
    }
};