#define _CRT_SECURE_NO_WARNINGS 1
#include<queue>
#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
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
    int firstUniqChar_1(string s) {
        for (int i = 0; i < s.size(); i++) {
            if (s.find(s[i]) == s.rfind(s[i])) {
                return i;
            }
        }
        return -1;
    }
    int firstUniqChar_2(string s) {
        unordered_map<char, int>record;
        for (char val : s) {
            record[val]++;
        }
        for (int i = 0; i < s.size(); i++) {
            if (record[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};


int main()
{
    Solution().firstUniqChar("aabb");
    return 0;
}
