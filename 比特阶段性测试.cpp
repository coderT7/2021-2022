#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<list>
#include<vector>
using namespace std;



 struct TreeNode {
 	int val;
 	struct TreeNode *left;
 	struct TreeNode *right;
 	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };
 

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param root TreeNode类
     * @return int整型
     */
    int sumOfLeftLeaves(TreeNode* root) {
        int curVal = 0;
        if (root != nullptr) {
            return 0;
        }
        int leftVal = sumOfLeftLeaves(root->left);
        int rightVal = sumOfLeftLeaves(root->right);
        if (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr) {
            curVal = root->left->val;
        }
        return curVal + leftVal + rightVal;
    }
};

class Solution1 {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        while (n) {
            n /= 5;
            ans += n;
        }
        return ans;
    }
};
int main() {
    Solution s;
    
}

//int main()
//{
//    int n = 0,m = 0;
//    cin >> n >> m;
//    vector<int>v;
//    for(int i = 1; i <= n; i++){
//        v.push_back(i);
//    }
//    int count = 0;
//    vector<int>::iterator it = v.begin();
//    while(v.size() > 1){
//        if(it == v.end()){
//            it = v.begin();
//        }
//        if(count < m){
//            count++;
//            it++;
//        }else{
//            it = v.erase(it);
//            count = 0;
//        }
//    }
//    return 0;
//}