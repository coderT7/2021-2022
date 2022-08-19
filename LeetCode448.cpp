#include<vector>
using namespace std;
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        vector<int>tmp(nums.size()+1);
        for(int val : nums){
            if(val >= 1 && val <= nums.size()){
                if(tmp[val] == 0){
                    tmp[val]++;
                }
            }else{
                continue;
            }
        }
        for(int i = 1; i < nums.size()+1; i++){
            if(tmp[i] == 0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
class Solution2 {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] == i + 1) {
                i++;
                continue;
            }
            int idealIdx = nums[i] - 1;
            if (nums[i] == nums[idealIdx]) {
                i++;
                continue;
            }
            swap(nums[i],nums[nums[i]-1]);
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i+1) {
                res.push_back(i+1);
            }
        }
        return res;
    }
};

int main()
{
    vector<int>v({4,3,2,7,8,2,3,1});
    Solution().findDisappearedNumbers(v);
    return 0;
}