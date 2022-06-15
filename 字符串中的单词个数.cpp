#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<ctype.h>
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    int countSegments(string s) {
        vector<string> ans;
        string s1 = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                if (s1.size() != 0) {
                    ans.push_back(s1);
                    s1 = "";
                }
                continue;
            }
            if (s[i] != ' ')
                s1 += s[i];
        }
        if (s1.size() != 0) ans.push_back(s1);
        return ans.size();
    }
};

 struct TreeNode {
     int val;
     TreeNode*  left;
     TreeNode*  right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode*  left, TreeNode*  right) : val(x), left(left), right(right) {}
     
};

class Solution1 {
public:
    vector<int> levelOrder(TreeNode* root) {
        if (root == nullptr) {
            return vector<int>(0);
        }
        queue<TreeNode*> q;
        vector<int>ans;
        q.push(root);
        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            if (cur->left != nullptr) {
                q.push(cur->left);
            }
            if (cur->right != nullptr) {
                q.push(cur->right);
            }
            ans.push_back(cur->val);
        }
        return ans;
    }
};
class Solution2 {
public:
    vector<int> levelOrder(TreeNode* root) {
        if (root == nullptr) {
            return vector<int>(0);
        }
        queue<TreeNode*> q;
        vector<int>ans;
        q.push(root);
        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            if (cur->left != nullptr) {
                q.push(cur->left);
            }
            if (cur->right != nullptr) {
                q.push(cur->right);
            }
            ans.push_back(cur->val);
        }
        return ans;
    }
};
int main()
{
    Solution1 s1;

    return 0;
}

