#include"Queue.h"



void QueueInit(Queue *pq)
{
    assert(pq);
    pq->head = pq->tail = NULL;
}

void push(Queue *pq,QDataType x)
{
    assert(pq);
    QNode *newnode = (QNode*)malloc(sizeof(QNode));
    assert(newnode);
    newnode->next = NULL;
    newnode->val = x;
    if(pq->tail == NULL)
        pq->head = pq->tail = newnode;
    else 
    {
        pq->tail->next = newnode;
        pq->tail = newnode;
    }
}

void pop(Queue *pq)
{
    assert(pq);
    assert(pq->head);

    QNode *next = pq->head->next;
    free(pq->head);
    pq->head = next;
    if(pq->head == NULL)
        pq->head = pq->tail = NULL;
}

QDataType back(Queue *pq)
{
    assert(pq);
    assert(pq->head);
    return pq->tail->val;
}

QDataType front(Queue *pq)
{
    assert(pq);
    assert(pq->head);
    return pq->head->val;
}

bool empty(Queue *pq)
{
    assert(pq);
    return pq->head == NULL;
}

int size(Queue *pq)
{
    int count = 0;
    QNode *cur = pq->head;
    while(cur)
    {
        count++;
        cur = cur->next;
    }
    return count;
}

void clean(Queue *pq)
{
    assert(pq);
    QNode *cur = pq->head;
    while(cur)
    {
        QNode *next = cur->next;
        free(cur);
        cur = next;
    }
    pq->head = pq->tail = NULL;
}

