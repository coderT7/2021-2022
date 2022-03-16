#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
    
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        ListNode* next = head->next;
        ListNode* cur = head;
        ListNode* prev = NULL;
        while (cur) {
            cur->next = prev;
            prev = cur;
            cur = next;
            if (next != NULL)
                next = next->next;
        }
        return prev;
    }
};