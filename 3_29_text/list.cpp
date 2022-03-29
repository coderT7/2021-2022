#define _CRT_SECURE_NO_WARNINGS 1
#include"list.h"

list* buy_node(student stu) {
	list* newnode = new list(NULL, NULL, student("", "", 0));
	newnode->stu.id = stu.id;
	newnode->stu.mark = stu.mark;
	newnode->stu.name = stu.name;
	return newnode;
}

list* init_list() {
	list* head = buy_node(student("", "", 0));
	head->next = head;
	head->prev = head;
	return head;
}

void add_stu(list* head, student stu) {
	list* newnode = buy_node(stu);
	list* tail = head->prev;
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = head;
	head->prev = newnode;
}

void print_list(list* head)
{
	list* cur = head->next;
	while (cur != head)
	{
		cout << cur->stu.id << " " << cur->stu.name << " " << cur->stu.mark << endl;
		cur = cur->next;
	}
	cout << endl;
}
static list* find_stu(list* head, string id) {
	list* cur = head->next;
	while (cur != head) {
		if (!cur->stu.id.compare(id)) {
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
void del_stu(list* head, string id) {
	list* pos = find_stu(head, id);
	if (pos != NULL) {
		list* prev = pos->prev;
		list* next = pos->next;
		prev->next = next;
		next->prev = prev;
		delete(pos);
	}
}
