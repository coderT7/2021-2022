/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string>ans;
    void dfs(TreeNode* root, string str){
        if(root == nullptr){
            return;
        }
        if(root->left == nullptr && root->right == nullptr){
            ans.push_back(str+to_string(root->val));
            return;
        }
        dfs(root->left,str + to_string(root->val)+"->");
        dfs(root->right,str + to_string(root->val)+"->");
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root,"");
        return ans;
    }
};
// @lc code=end

