#define _CRT_SECURE_NO_WARNINGS 1

#include"list.h"


int main()
{
	student s1("10001", "张三", 66);
	student s2("10002", "李四", 86);
	student s3("10003", "王五", 76);

	list* head = init_list();
	add_stu(head, s1);
	add_stu(head, s2);
	add_stu(head, s3);
	print_list(head);
	string id;
	cin >> id;
	del_stu(head, id);
	print_list(head);
	return 0;
}