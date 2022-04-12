#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<cstdio>
#include"list.h"
void write_to_file(ListNode* phead) {
	assert(phead);
	FILE* pFile = fopen("joseph_ring.txt", "w");
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		fprintf(pFile, "%d", cur->val);
		fputc(' ', pFile);
		cur = cur->next;
	}
}
void joseph_ring() {
	ListNode* head = ListInit();
	for (int i = 0; i < 30; i++) {
		push_back(head, i);
	}
	//std::cout << list_size(head) << std::endl;
	ListNode* cur = head->next;
	while (list_size(head) > 15) {
		int count = 0;
		while (count < 9) {
			cur = cur->next;
			count++;
		}
		ListNode* tmp = cur;
		cur = cur->next;
		erase(tmp);
	}
	write_to_file(head);
}

int main()
{
	joseph_ring();
	return 0;
}