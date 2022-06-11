#define _CRT_SECURE_NO_WARNINGS 1

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
    
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        *node = *node->next;
    }
};