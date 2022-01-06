#include"Stack.h"

void StackInit(Stack *ST)
{
    STDataType *tmp = (STDataType*)malloc(sizeof(STDataType)*4);
    assert(tmp);
    ST->stack = tmp;
    ST->size = 0;
    ST->capacity = 4;
    ST->top = -1;
}

void push(Stack *ST,STDataType x)
{
    assert(ST);
    if(ST->size == ST->capacity)
    {
        STDataType *tmp = (STDataType*)realloc(ST->stack,sizeof(STDataType)*ST->capacity*2);
        assert(tmp);
        ST->stack = tmp;
        ST->capacity *= 2;
    }
    ST->stack[ST->size] = x;
    ST->size++;
    ST->top++;
}

void pop(Stack *ST)
{
    assert(ST);
    assert(ST->top >= 0);
    ST->size--;
    ST->top--;
}

STDataType top(Stack *ST)
{
    assert(ST);
    assert(ST->top >= 0);
    return ST->stack[ST->top];
}

int size(Stack *ST)
{
    assert(ST);
    return ST->size;
}

bool empty(Stack *ST)
{
    assert(ST);
    return ST->top == -1;
}

void StackDestroy(Stack *ST)
{
    assert(ST);
    free(ST->stack);
    ST->size = 0;
    ST->capacity = 0;
    ST->top = -1;
    ST->stack = NULL;
}


