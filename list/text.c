#include"list.h"

int main()
{
    ListNode *phead = ListInit();
    push_back(phead,10);
    push_back(phead,10);
    push_back(phead,10);
    push_front(phead,20);
    push_front(phead,20);
    push_front(phead,20);
    pop_back(phead);
    pop_back(phead);
    pop_back(phead);
    pop_front(phead);
    pop_front(phead);
    pop_front(phead);
    pop_front(phead);
    ListNode *pos = find(phead,20);
    insert(pos,40);
    insert(pos,80);
    erase(&pos);
    erase(&pos);
    print_list(phead);
    return 0;
}
