#define _CRT_SECURE_NO_WARNINGS 1
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


bool isSymmetricTree(TreeNode * left, TreeNode * right) {
    if (left == nullptr && right == nullptr) {
        return true;
    }
    if (left == nullptr || right == nullptr) {
        return false;
    }
    if (left->val != right->val) {
        return false;
    }
    return isSymmetricTree(left->left, right->right)
        && isSymmetricTree(left->right, right->left);
}


class Solution1 {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        return isSymmetricTree(root->left, root->right);
    }
};

bool _isSymmetricTree(TreeNode* left, TreeNode* right) {
    if (left == nullptr && right == nullptr) {
        return true;
    }
    if (left == nullptr || right == nullptr) {
        return false;
    }
    if (left->val != right->val) {
        return false;
    }
    return _isSymmetricTree(left->left, right->left)
        && _isSymmetricTree(left->right, right->right);
}
class Solution2 {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr) {
            return false;
        }
        if (_isSymmetricTree(root, subRoot)) {
            return true;
        }
        return isSubtree(root->left, subRoot)
            || isSubtree(root->right, subRoot);
    }
};

void preOrder(TreeNode* root, vector<int>& ret) {
    if (root == nullptr)
        return;
    ret.push_back(root->val);
    preOrder(root->left, ret);
    preOrder(root->right, ret);
}

class Solution3 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        preOrder(root, ret);
        return ret;
    }
};

int main()
{
    int a = 2;
    int* ptr = &a;
    *ptr = 8;
    a = (*ptr)++;
    printf("%d, %d", a, *ptr);
    return 0;
}