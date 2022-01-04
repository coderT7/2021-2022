#include"SList.h"


void print_list(SLNode **const pplist)
{
    assert(pplist);
    if(*pplist == NULL)
    {
        printf("当前链表无数据！\n");
        return ;
    }
    SLNode *cur = *pplist;
    while(cur != NULL)
    {
        printf("%d ",cur->val);
        cur = cur->next;
    }
    printf("\n");
}

SLNode* buy_newnode(SLTDataType x)
{
    SLNode *newnode = (SLNode*)malloc(sizeof(SLNode));
    newnode->val = x;
    newnode->next = NULL;
    return newnode;
}

void push_back(SLNode** pplist,SLTDataType x)
{
    assert(pplist);
    SLNode *newnode = buy_newnode(x);
    if(*pplist == NULL)
        *pplist = newnode;
    else 
    {
        SLNode *tail = *pplist;
        while(tail->next)
            tail = tail->next;
        tail->next = newnode;
    }
}

void push_front(SLNode** pplist,SLTDataType x)
{
    assert(pplist);
    SLNode *newnode = buy_newnode(x);
    newnode->next = *pplist;
    *pplist = newnode;
}

void pop_back(SLNode** pplist)
{
    assert(pplist);
    if(*pplist == NULL)
    {
        printf("当前链表无数据！\n");
        return ;
    }
    if((*pplist)->next == NULL)
    {
        free(*pplist);
        *pplist = NULL;
    }
    else 
    {
        SLNode *cur = *pplist;
        SLNode *prev = NULL;
        while(cur->next)
        {
            prev = cur;
            cur = cur->next;
        }
        free(cur);
        prev->next = NULL;
    }
}
void pop_front(SLNode** pplist)
{
    assert(pplist);
    if(*pplist == NULL)
    {
        printf("当前链表无数据！\n");
        return ;
    }
    SLNode *next = (*pplist)->next;
    free(*pplist);
    *pplist = next;
}

SLNode* Find(SLNode** const pplist,SLTDataType x)
{
    assert(pplist);
    SLNode *cur = *pplist;
    while(cur)
    {
        if(cur->val == x)
            return cur;
        cur = cur->next;
    }
    printf("未找到该数据！\n");
}

void insert(SLNode** pplist,SLNode *pos,SLTDataType x)
{
    assert(pplist);
    SLNode *newnode = buy_newnode(x);
    if(*pplist == pos)
        push_front(pplist,x);
    SLNode *cur = *pplist;
    SLNode *prev = NULL;
    while(cur != pos)
    {
        prev = cur;
        cur = cur->next;
    }
    prev->next = newnode;
    newnode->next = pos;
}

void erase(SLNode** pplist,SLNode** pos)
{
    assert(pplist);
    if(*pplist == *pos)
        pop_front(pplist);
    if(*pos == NULL)
    {
        printf("该结点不存在！\n");
        return ;
    }
    SLNode *cur = *pplist;
    SLNode *prev = NULL;
    while(cur != *pos)
    {
        prev = cur;
        cur = cur->next;
    }
    prev->next = cur->next;
    free(*pos);
    *pos = NULL;
}

void destroy(SLNode **pplist)
{
    assert(pplist);
    if(*pplist == NULL)
    {
        printf("当前链表无数据！\n");
        return ;
    }
    SLNode *cur = *pplist;
    SLNode *next = (*pplist)->next;
    while(next)
    {
        free(cur);
        cur = next;
        next = next->next;
    }
    *pplist = NULL;
    printf("销毁成功！\n");
}
