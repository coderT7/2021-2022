#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

#include<stack>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    
};
class Solution1 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s;
        ListNode* cur = l1;
        while (cur) {
            s.push(cur->val);
            cur = cur->next;
        }
        long num1 = 0;
        while (!s.empty()) {
            int tmp = s.top();
            s.pop();
            num1 = num1 * 10 + tmp;
        }
        cur = l2;
        while (cur) {
            s.push(cur->val);
            cur = cur->next;
        }
        long num2 = 0;
        while (!s.empty()) {
            int tmp = s.top();
            s.pop();
            num2 = num2 * 10 + tmp;
        }
        long num = num1 + num2;
        ListNode* node = nullptr;
        ListNode* _node = nullptr;
        while (num) {
            
            int tmp = num % 10;
            if (node == nullptr) {
                node = new ListNode(tmp);
                _node = node;
            }
            else {  
                _node->next = new ListNode(tmp);
                _node = _node->next;
            }
            num /= 10;
        }
        return node;
    }
};
class Solution2 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr, * tail = nullptr;
        int carry = 0;
        while (l1 || l2) {
            int n1 = l1 == nullptr ? 0 : l1->val;
            int n2 = l2 == nullptr ? 0 : l2->val;

            int sum = n1 + n2 + carry;

            carry = sum / 10;
            sum = sum % 10;
            if (head == nullptr) {
                head = new ListNode(sum);
                tail = head;
            }
            else {
                tail->next = new ListNode(sum);
                tail = tail->next;
            }
            if (l1 != nullptr) {
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                l2 = l2->next;
            }
        }
        if (carry == 1) {
            tail->next = new ListNode(carry);
        }
        return head;
    }
};
int main()
{
    Solution1 solution;
    ListNode* l3 = new ListNode(3);
    ListNode* l2 = new ListNode(4,l3);
    
    ListNode* l6 = new ListNode(4);
    ListNode* l5 = new ListNode(6,l6);
    
    ListNode* l4 = new ListNode(0);
    ListNode* l1 = new ListNode(0);
    ListNode* ret = solution.addTwoNumbers(l1, l4);
    stack<int> s;
    ListNode* cur = ret;
    while (cur) {
        s.push(cur->val);
        cur = cur->next;
    }
    long num1 = 0;
    while (!s.empty()) {
        int tmp = s.top();
        s.pop();
        num1 = num1 * 10 + tmp;
    }
    cout << num1;
    return 0;
}