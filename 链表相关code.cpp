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
//���ڻ��������������ݽṹջ���н���

//class Solution {
//public:
//    bool isPalindrome(ListNode* head) {
//        if (head == nullptr || head->next == nullptr)
//            return true;
//
//        ListNode* cur = head, * pos = head;
//        //�ҵ��м�λ�õĽ��
//        while (pos->next != nullptr && pos->next->next != nullptr)
//        {
//            cur = cur->next;
//            pos = pos->next->next;
//        }
//        //������ջ
//        stack<ListNode*>v1;
//        while (cur != nullptr)
//        {
//            v1.push(cur);
//            cur = cur->next;
//        }
//        //���γ�ջ���бȽ�
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

//�����л�����ڽ��
// 1��
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
// 2��
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
//            //�������ָ��������һ���л����׽��ۼ���
//            if (fast == slow)
//            {
//                //��ָ��ص���ͷ����ָ����������λ��
//                fast = head;
//                while (fast != slow)
//                {
//                    fast = fast->next;
//                    slow = slow->next;
//                }
//                //������ָ���ٴ�����ʱ�����ڵĽ�㼴Ϊ�뻷���
//                return slow;
//            }
//        }
//        return NULL;
//    }
//};

//�����ཻ
//1��
//class Solution {
//public:
//    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
//        if (headA == NULL || headB == NULL)
//            return NULL;
//        ListNode* n1 = headA;
//        ListNode* n2 = headB;
//        int n = 0;
//        //���α���������������n��¼�������ȵĲ�ֵ
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
//        //�������β��㲻��ͬ��϶����ཻ
//        if (n1 != n2)
//            return NULL;
//        //��n1Ϊ������ı�ͷ��n2Ϊ������ı�ͷ���������泤����ָ���Ƚ���ƫ��
//        n1 = n > 0 ? headA : headB;
//        n2 = n1 == headA ? headB : headA;
//        n = abs(n);//n��Ϊ�ǲ�ֵ������Ϊ������ȡ������ֵ
//        //������ָ���Ƚ���ƫ��n��λ��
//        while (n != 0)
//        {
//            n--;
//            n1 = n1->next;
//        }
//        //��������һ���ƶ�
//        while (n1 != n2)
//        {
//            n1 = n1->next;
//            n2 = n2->next;
//        }
//        //���������λ�ü��ཻ���
//        return n1;
//    }
//};
//2���������
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