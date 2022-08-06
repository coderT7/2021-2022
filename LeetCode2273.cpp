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
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string>ans;
        ans.push_back(words[0]);
        for (int i = 1; i < words.size(); i++) {
            string tmp1 = words[i];
            string tmp2 = ans.back();
            sort(tmp1.begin(), tmp1.end());
            sort(tmp2.begin(), tmp2.end());
            if (tmp1 == tmp2) {
                continue;
            }
            else {
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> v({ 2,1,3,0 });

    return 0;
}