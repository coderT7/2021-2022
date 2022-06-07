#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
#include<set>
#include<iostream>
using namespace std;

#define LEN sizeof(struct singer)

struct singer {
	int num;
	char name[50];
	int score[6];
	int sum;
	float average;
	struct singer* next;
};
struct singer* sortList(struct singer* head);
struct singer* toSortList(struct singer* head, struct singer* tail);
struct singer* sort(struct singer* head);
struct singer* creat(void);
void output(struct singer* head);

int main()
{
	struct singer* head;
	head = creat();
	output(head);
	printf("排序后：\n");
	head = sortList(head);
	output(head);
	return 0;
}
int n;
struct singer* creat(void)
{
	struct singer* head;
	struct singer* p1, * p2;
	n = 0;
	p1 = p2 = (struct singer*)malloc(sizeof(LEN));//开辟新结点
	FILE* fp;
	fp = fopen("score.txt", "r");//读入选手的成绩
	if (fp == NULL)
	{
		printf("无法打开文件\n");
		exit(1);
	}
	head = NULL;
	fscanf(fp, "%d %s %d %d %d %d %d %d\n", &p1->num, p1->name, &p1->score[0], &p1->score[1], 
		&p1->score[2], &p1->score[3], &p1->score[4], &p1->score[5]);
	int i, max, min;
	min = 10;
	max = 0;
	p1->sum = 0;
	p1->average = 0;
	for (i = 0; i < 6; i++)
	{
		p1->sum += p1->score[i];
		if (p1->score[i] > max)
			max = p1->score[i];
		if (p1->score[i] < min)
			min = p1->score[i];
	}
	p1->sum = p1->sum - max - min;
	p1->average = p1->sum / 4.0;

	while (!feof(fp))
	{
		n = n + 1;
		if (n == 1) head = p1;
		else p2->next = p1;
		p2 = p1;
		p1 = (struct singer*)malloc(LEN);//开辟新结点 
		fscanf(fp, "%d %s %d %d %d %d %d %d\n", &p1->num, p1->name, &p1->score[0], &p1->score[1], 
			&p1->score[2], &p1->score[3], &p1->score[4], &p1->score[5]);
		p1->sum = 0;
		p1->average = 0;
		max = 0; min = 10;
		for (i = 0; i < 6; i++)
		{
			p1->sum += p1->score[i];
			if (p1->score[i] > max)
				max = p1->score[i];
			if (p1->score[i] < min)
				min = p1->score[i];
		}
		p1->sum = p1->sum - max - min;
		p1->average = p1->sum * 1.0 / 4;
	}
	p2->next = p1;
	p2 = p1;
	p2->next = NULL;
	return (head);
}
void output(struct singer* head)
{
	struct singer* p3;
	p3 = head;
	if (head != NULL)
		do
		{
			printf("%d %s %d %d %d %d %d %d %d %4.2f\n", p3->num, p3->name, p3->score[0], p3->score[1], 
				p3->score[2], p3->score[3], p3->score[4], p3->score[5], p3->sum, p3->average);
			p3 = p3->next;
		} while (p3 != NULL);

}

struct singer* merge(struct singer* head1, struct singer* head2) {
	//新建临时结点，用于返回归并链表（哨兵卫）
	struct singer* dummyHead = (struct singer*)malloc(sizeof(struct singer));
	dummyHead->average = 0;//该行可省略，只是与后面匹配一下，看着顺眼
	//新建临时结点，用于进行链表归并
	struct singer* temp = dummyHead, * temp1 = head1, * temp2 = head2;
	while (temp1 != NULL && temp2 != NULL) {
		if (temp1->average <= temp2->average) {
			temp->next = temp1;
			temp1 = temp1->next;
		}
		else {
			temp->next = temp2;
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
	if (temp1 != NULL) {
		temp->next = temp1;
	}
	else if (temp2 != NULL) {
		temp->next = temp2
	}
	return dummyHead->next;
}
struct singer* toSortList(struct singer* head, struct singer* tail) {
	//特殊情况判断
	if (head == NULL) {
		return head;
	}
	if (head->next == tail) {
		head->next = NULL;
		return head;
	}
	//利用快慢指针走到中间结点，分割链表
	struct singer* slow = head, * fast = head;
	while (fast != tail) {
		slow = slow->next;
		fast = fast->next;
		if (fast != tail) {
			fast = fast->next;
		}
	}
	struct singer* mid = slow;
	//开始递归对左右区间进行归并排序
	return merge(toSortList(head, mid), toSortList(mid, tail));
}
struct singer* sortList(struct singer* head) {
	//排序链表
	return toSortList(head, NULL);
}

