#include"Stack.h"

int main()
{
    Stack stack;
    StackInit(&stack);
    push(&stack,10);
    push(&stack,20);
    push(&stack,30);
    push(&stack,40);
    push(&stack,50);
    pop(&stack);
    pop(&stack);
    while(!empty(&stack))
    {
        STDataType ret = top(&stack);
        printf("%d ",ret);
        printf("\n");
        pop(&stack);
    }
    printf("\n");
    return 0;
}
