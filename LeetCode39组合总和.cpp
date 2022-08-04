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
        //û������ѡ��ֱ�ӷ���
        if (index == candidates.size()) {
            return;
        }
        //target��Ϊ0˵����ǰtmp������ѡ����������������
        if (target == 0) {
            ans.push_back(tmp);
            return;
        }
        //��ǰ����Ҫ��ֱ�ӿ���һ��
        dfs(candidates, target, index + 1, tmp, ans);
        if (target - candidates[index] >= 0) {
            tmp.push_back(candidates[index]);
            //��ǰ��Ҫ����Ϊ�����ظ�ѡ��index����
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