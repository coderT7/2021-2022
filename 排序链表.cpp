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
	printf("�����\n");
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
	p1 = p2 = (struct singer*)malloc(sizeof(LEN));//�����½��
	FILE* fp;
	fp = fopen("score.txt", "r");//����ѡ�ֵĳɼ�
	if (fp == NULL)
	{
		printf("�޷����ļ�\n");
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
		p1 = (struct singer*)malloc(LEN);//�����½�� 
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
	//�½���ʱ��㣬���ڷ��ع鲢�����ڱ�����
	struct singer* dummyHead = (struct singer*)malloc(sizeof(struct singer));
	dummyHead->average = 0;//���п�ʡ�ԣ�ֻ�������ƥ��һ�£�����˳��
	//�½���ʱ��㣬���ڽ�������鲢
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
	//��������ж�
	if (head == NULL) {
		return head;
	}
	if (head->next == tail) {
		head->next = NULL;
		return head;
	}
	//���ÿ���ָ���ߵ��м��㣬�ָ�����
	struct singer* slow = head, * fast = head;
	while (fast != tail) {
		slow = slow->next;
		fast = fast->next;
		if (fast != tail) {
			fast = fast->next;
		}
	}
	struct singer* mid = slow;
	//��ʼ�ݹ������������й鲢����
	return merge(toSortList(head, mid), toSortList(mid, tail));
}
struct singer* sortList(struct singer* head) {
	//��������
	return toSortList(head, NULL);
}

