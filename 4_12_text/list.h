#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int LTDatatype;

typedef struct ListNode
{
    struct ListNode* prev;
    struct ListNode* next;
    LTDatatype val;
}ListNode;

ListNode* ListInit();

int list_size(ListNode* phead);

void print_list(ListNode* phead);

void push_back(ListNode* phead, LTDatatype x);

void push_front(ListNode* phead, LTDatatype x);

void pop_back(ListNode* phead);

void pop_front(ListNode* phead);

ListNode* find(ListNode* phead, LTDatatype x);

void insert(ListNode* pos, LTDatatype x);

void erase(ListNode* pos);

void clean(ListNode** phead);

