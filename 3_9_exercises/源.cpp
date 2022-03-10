#define _CRT_SECURE_NO_WARNINGS 1

#include<algorithm>
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

//class myGreater
//{
//public:
//	bool operator()(int a, int b)
//	{
//		return a < b;
//	}
//};
//
//int main()
//{
//	srand((unsigned int)time(NULL));
//	vector<int> num;
//	for (int i = 0; i < 10; i++)
//		num.push_back(rand() % 10);
//	make_heap(num.begin(), num.end(), myGreater());
//	unordered_map<string, int> mymap;
//	pair<string, int> mypair({ "banana", 2 }); 
//	mymap.insert(mypair);
//	mymap["world"] = 2;
//	for (int i = 0; i < 10; i++)
//		cout << num[i] << " ";
//	
//	return 0;
//}

//����������жϣ�ʱ�临�Ӷ�O(N),�ռ临�Ӷ�O(1)
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    
};
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return true;
        ListNode* cur = head, * pos = head;
        while (pos->next != nullptr && pos->next->next != nullptr)
        {
            cur = cur->next;
            pos = pos->next->next;
        }
        pos = cur->next;
        cur->next = nullptr;
        ListNode* tmp = nullptr;
        //����������������ת
        while (pos != nullptr)
        {
            tmp = pos->next;
            pos->next = cur;
            cur = pos;
            pos = tmp;
        }
        pos = head;
        tmp = cur;//��������һ����㣬�����ܸ�ԭ����
        //�ֱ�������������м�����ж�
        while (pos != nullptr && cur != nullptr)
        {
            if (pos->val != cur->val)
                return false;
            pos = pos->next;
            cur = cur->next;
        }
        //������ԭ
        cur = tmp->next;
        tmp->next = nullptr;
        while (cur != nullptr)
        {
            pos = cur->next;
            cur->next = tmp;
            tmp = cur;
            cur = pos;
        }
        return true;
    }
};