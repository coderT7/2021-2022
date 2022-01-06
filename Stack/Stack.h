#pragma once 

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int STDataType;

typedef struct Stack
{
    STDataType *stack;
    int size;
    int top;
    int capacity;
}Stack;


void StackInit(Stack *ST);

void push(Stack *ST,STDataType x);

void pop(Stack *ST);

STDataType top(Stack *ST);

int size(Stack *ST);

bool empty(Stack *ST);

void StackDestroy(Stack *ST);


