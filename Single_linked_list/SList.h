#pragma once 

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


typedef int SLTDataType;

typedef struct SLNode
{
    SLTDataType val;
    struct SLNode *next;
}SLNode;

void print_list(SLNode **const pplist);

void push_back(SLNode* *pplist,SLTDataType x);

void push_front(SLNode** pplist,SLTDataType X);

void pop_back(SLNode** pplist);

void pop_front(SLNode** pplist);

SLNode* Find(SLNode** const pplist,SLTDataType x);

void insert(SLNode** pplist,SLNode *pos,SLTDataType x);

void erase(SLNode** pplist,SLNode** pos);

void destroy(SLNode **pplist);
