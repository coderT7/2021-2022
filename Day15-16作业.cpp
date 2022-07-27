#define _CRT_SECURE_NO_WARNINGS 1
#include<queue>
#include<iostream>
#include<vector>
using namespace std;
 struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    
};
 class Solution1 {
 public:
     bool isEvenOddTree(TreeNode* root) {
         queue<TreeNode*> q;
         q.push(root);
         int level = 0;
         while (!q.empty()) {
             int size = q.size();
             int pre = level % 2 == 0 ? INT_MIN : INT_MAX;
             for (int i = 0; i < size; i++) {
                 TreeNode* front = q.front();
                 q.pop();
                 if (level % 2 == 0 && front->val % 2 == 0
                     || level % 2 != 0 && front->val % 2 != 0) {
                     return false;
                 }
                 if (level % 2 == 0 && pre >= front->val
                     || level % 2 != 0 && pre <= front->val) {
                     return false;
                 }
                 pre = front->val;
                 if (front->left != nullptr) {
                     q.push(front->left);
                 }
                 if (front->right != nullptr) {
                     q.push(front->right);
                 }
             }
             level++;
         }
         return true;
     }
 };
 class Solution2 {
 public:
     vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
         vector<int> ans;
         int cnt[1001] = { 0 };
         for (int e : arr1) ++cnt[e];
         for (int e : arr2)
             while (0 < cnt[e]--) ans.push_back(e);
         for (int e = 0; e < 1001; ++e)
             while (0 < cnt[e]--) ans.push_back(e);
         return ans;
     }
 };
 class Solution3 {
 public:
     int findLHS(vector<int>& nums) {
         sort(nums.begin(), nums.end());
         int begin = 0;
         int res = 0;
         for (int end = 0; end < nums.size(); end++) {
             if (nums[end] - nums[begin] > 1) {
                 begin++;
             }
             if (nums[end] - nums[begin] == 1) {
                 res = max(res, end - begin + 1);
             }
         }
         return res;
     }
 };
int main()
{

    return 0;
}