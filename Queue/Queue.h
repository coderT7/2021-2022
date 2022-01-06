#pragma once 

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int QDataType;

typedef struct QueueNode
{
    struct QueueNode *next;
    QDataType val;
}QNode;

typedef struct Queue
{
    QNode *head;
    QNode *tail;
}Queue;

void QueueInit(Queue *pq);

void push(Queue *pq,QDataType x);

void pop(Queue *pq);

QDataType back(Queue *pq);

QDataType front(Queue *pq);

bool empty(Queue *pq);

int size(Queue *pq);

void clean(Queue *pq);

