#pragma once 

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<unistd.h>

typedef int SQDataType;

typedef struct Seqlist
{
    SQDataType *a;
    int size;
    int capacity;
}SeqList;

void menu();

void InitList(SeqList *plist);

void PushBack(SeqList *plist,SQDataType x);

void PopBack(SeqList *plist);
    
void PushFront(SeqList *plist,SQDataType x);

void PopFront(SeqList *plist);

void ListModify(SeqList *plist,int pos,SQDataType x);

void Inerst(SeqList *plist,int pos,SQDataType x);

int Find(const SeqList *plist,SQDataType x);

void Erase(SeqList *plist,int pos);

void Destroy(SeqList *plist); 

void PrintSList(const SeqList *plist);
