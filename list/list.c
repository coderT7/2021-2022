#include"list.h"

ListNode* buy_newnode(LTDatatype x)
{
    ListNode *newnode = (ListNode*)malloc(sizeof(ListNode));
    newnode->next = NULL;
    newnode->prev = NULL; 
    newnode->val = x;
    return newnode;
}

ListNode* ListInit()
{
    ListNode *phead = buy_newnode(0);
    phead->next = phead;
    phead->prev = phead;
    return phead;
}
void print_list(ListNode *phead)
{
    assert(phead);
    ListNode *cur = phead->next;
    while(cur != phead)
    {
        printf("%d ",cur->val);
        cur = cur->next;
    }
    printf("\n");
}
void push_back(ListNode *phead,LTDatatype x)
{
    assert(phead);
    /*ListNode *tail = phead->prev;
    ListNode *newnode = buy_newnode(x);
    tail->next = newnode;
    newnode->prev = tail;
    newnode->next = phead;
    phead->prev = newnode;*/
    insert(phead,x);
}
void push_front(ListNode *phead,LTDatatype x)
{
    assert(phead);
    /*ListNode *next = phead->next;
    ListNode *newnode = buy_newnode(x);
    newnode->next = next;
    next->prev = newnode;
    phead->next = newnode;
    newnode->prev = phead;*/
    insert(phead->next,x);
}
void pop_back(ListNode *phead)
{
    assert(phead);
    assert(phead->next != phead);
    /*ListNode *tail = phead->prev;
    ListNode *prev = tail->prev;
    phead->prev = prev;
    prev->next = phead;
    free(tail);
    tail = NULL;*/
    erase(&(phead->prev));
    printf("尾删成功！\n");
}
void pop_front(ListNode *phead)
{
    assert(phead);
    assert(phead->next != phead);
    /*ListNode *first = phead->next;
    ListNode *second = first->next;
    phead->next = second;
    second->prev = phead;
    free(first);
    first = NULL;*/
    erase(&(phead->next));
    printf("头删成功！\n");
}
ListNode* find(ListNode *phead,LTDatatype x)
{
    assert(phead);
    assert(phead->next != phead);
    ListNode *cur = phead->next;
    while(cur != phead)
    {
        if(cur->val == x)
            return cur;
        cur = cur->next;
    }
    printf("未找到该数据！\n");
}
void insert(ListNode *pos,LTDatatype x)
{
    assert(pos);
    ListNode *prev = pos->prev;
    ListNode *newnode = buy_newnode(x);
    prev->next = newnode;
    newnode->prev = prev;
    newnode->next = pos;
    pos->prev = newnode;
}
void erase(ListNode **pos)
{
    if(*pos == NULL)
    {
        printf("该结点不存在！\n");
        return ;
    }
    ListNode *prev = (*pos)->prev;
    ListNode *next = (*pos)->next;
    free(*pos);
    *pos = NULL;
    prev->next = next;
    next->prev = prev;
    printf("删除成功\n");
}

void clean(ListNode **pphead)
{
    assert(pphead);
    ListNode *cur = (*pphead)->next;
    ListNode *next = cur->next;
    while(cur != *pphead)
    {
        free(cur);
        cur = next;
        next = next->next;
    }
    (*pphead) = NULL;
    printf("销毁成功！\n");
}
