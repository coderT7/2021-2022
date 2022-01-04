#include"SList.h"

int main()
{
    //存放头结点的地址
    SLNode *plist = NULL;
    push_back(&plist,10);
    push_back(&plist,10);
    push_front(&plist,20);
    push_front(&plist,20);
    pop_back(&plist);
    pop_front(&plist);
    SLNode *pos = Find(&plist,10);
    insert(&plist,pos,30);
    insert(&plist,pos,40);
    erase(&plist,&pos);
    erase(&plist,&pos);
    print_list(&plist);
    destroy(&plist);
    print_list(&plist);
    return 0;
}
