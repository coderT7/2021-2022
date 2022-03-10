#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}

};
//关于回文链表利用数据结构栈进行解题

//class Solution {
//public:
//    bool isPalindrome(ListNode* head) {
//        if (head == nullptr || head->next == nullptr)
//            return true;
//
//        ListNode* cur = head, * pos = head;
//        //找到中间位置的结点
//        while (pos->next != nullptr && pos->next->next != nullptr)
//        {
//            cur = cur->next;
//            pos = pos->next->next;
//        }
//        //依次入栈
//        stack<ListNode*>v1;
//        while (cur != nullptr)
//        {
//            v1.push(cur);
//            cur = cur->next;
//        }
//        //依次出栈进行比较
//        pos = head;
//        while (!v1.empty())
//        {
//            if (pos->val != v1.top()->val)
//                return false;
//            pos = pos->next;
//            v1.pop();
//        }
//        return true;
//    }
//};

//链表中环的入口结点
// 1、
//class Solution {
//public:
//    ListNode* detectCycle(ListNode* head) {
//        unordered_set<ListNode*> visited;
//        while (head != nullptr) {
//            if (visited.count(head)) {
//                return head;
//            }
//            visited.insert(head);
//            head = head->next;
//        }
//        return nullptr;
//    }
//};
// 2、
//class Solution {
//public:
//    ListNode* detectCycle(ListNode* head) {
//        if (head == NULL || head->next == NULL)
//            return NULL;
//        ListNode* slow = head;
//        ListNode* fast = head;
//        while (fast->next != NULL && fast->next->next != NULL)
//        {
//            fast = fast->next->next;
//            slow = slow->next;
//            //如果快慢指针相遇那一定有环，套结论即可
//            if (fast == slow)
//            {
//                //快指针回到开头，慢指针仍在相遇位置
//                fast = head;
//                while (fast != slow)
//                {
//                    fast = fast->next;
//                    slow = slow->next;
//                }
//                //当快慢指针再次相遇时，所在的结点即为入环结点
//                return slow;
//            }
//        }
//        return NULL;
//    }
//};

//链表相交
//1、
//class Solution {
//public:
//    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
//        if (headA == NULL || headB == NULL)
//            return NULL;
//        ListNode* n1 = headA;
//        ListNode* n2 = headB;
//        int n = 0;
//        //依次遍历两个链表，并用n记录两链表长度的差值
//        while (n1->next != NULL)
//        {
//            n++;
//            n1 = n1->next;
//        }
//        while (n2->next != NULL)
//        {
//            n--;
//            n2 = n2->next;
//        }
//        //两链表的尾结点不相同则肯定不相交
//        if (n1 != n2)
//            return NULL;
//        //令n1为长链表的表头，n2为短链表的表头，便于下面长链表指针先进行偏移
//        n1 = n > 0 ? headA : headB;
//        n2 = n1 == headA ? headB : headA;
//        n = abs(n);//n因为是差值，可能为负数，取个绝对值
//        //长链表指针先进行偏移n个位置
//        while (n != 0)
//        {
//            n--;
//            n1 = n1->next;
//        }
//        //长短链表一起移动
//        while (n1 != n2)
//        {
//            n1 = n1->next;
//            n2 = n2->next;
//        }
//        //最后相遇的位置即相交结点
//        return n1;
//    }
//};
//2、大佬题解
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* A = headA, * B = headB;
        while (A != B) {
            A = A != nullptr ? A->next : headB;
            B = B != nullptr ? B->next : headA;
        }
        return A;
    }
};