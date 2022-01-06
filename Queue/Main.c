#include"Queue.h"


int main()
{
    Queue q;
    QueueInit(&q);
    push(&q,10);
    push(&q,20);
    push(&q,30);
    push(&q,40);
    push(&q,50);
    while(!empty(&q))
    {
        printf("%d\n",front(&q));
        printf("%d\n",back(&q));
        pop(&q);
    }
    printf("%d\n",size(&q));
    return 0;
}
