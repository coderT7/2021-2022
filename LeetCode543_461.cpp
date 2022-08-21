#include <algorithm>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution2
{
    int ans;
    int depth(TreeNode *rt)
    {
        if (rt == nullptr)
        {
            return 0; // 访问到空节点了，返回0
        }
        int L = depth(rt->left);  // 左儿子为根的子树的深度
        int R = depth(rt->right); // 右儿子为根的子树的深度
        ans = max(ans, L + R);    // 更新ans
        return max(L, R) + 1;     // 返回该节点为根的子树的深度
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        ans = 0;
        depth(root);
        return ans;
    }
};
class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        int count = 0;
        for (int i = 0; i < 32; i++)
        {
            int a = x & 1;
            int b = y & 1;
            if (a != b)
            {
                count++;
            }
            x = x >> 1;
            y = y >> 1;
            if (x == 0 && y == 0)
            {
                break;
            }
        }
        return count;
    }
};
class Solution2
{
public:
    int hammingDistance(int x, int y)
    {
        return __builtin_popcount(x ^ y);
    }
};

int main()
{
    Solution().hammingDistance(1, 4);
    return 0;
}