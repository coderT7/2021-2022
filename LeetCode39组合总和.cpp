#define _CRT_SECURE_NO_WARNINGS 1
#include<queue>
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    
};
class Solution {
public:
    void dfs(vector<int>& candidates, int target, int index, vector<int>& tmp, vector<vector<int>>& ans) {
        //没有数可选了直接返回
        if (index == candidates.size()) {
            return;
        }
        //target变为0说明当前tmp数组已选好了满足条件的数
        if (target == 0) {
            ans.push_back(tmp);
            return;
        }
        //当前数不要，直接看下一个
        dfs(candidates, target, index + 1, tmp, ans);
        if (target - candidates[index] >= 0) {
            tmp.push_back(candidates[index]);
            //当前数要，因为可用重复选择，index不变
            dfs(candidates, target - candidates[index], index, tmp, ans);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>tmp;
        dfs(candidates, target, 0, tmp, ans);
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> v({ 2,1,3,0 });

    return 0;
}