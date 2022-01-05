#include"SeqList.h"

int main()
{
    SeqList sl;
    int enter = 0;
    InitList(&sl);
    do 
    {
        menu();
        scanf("%d",&enter);
        int val;
        switch(enter)
        {
            case 1:
                {
                    printf("请输入你要尾插的数据：\n");
                    printf("并以-1作为结束标志！\n");
                    do 
                    {
                        scanf("%d",&val);
                        if(val != -1)
                            PushBack(&sl,val);
                    }while(val != -1);
                printf("尾插成功!\n");
                break;
                }
            case 2:
                {
                    printf("请输入你要头插的数据：\n");
                    printf("并以-1作为结束标志！\n");
                    do 
                    {
                        scanf("%d",&val);
                        if(val != -1)    
                            PushFront(&sl,val);
                    }while(val != -1);
                printf("头插成功！\n");
                break;
                }
            case 3:
                PopBack(&sl);
                break;
            case 4:
                PopFront(&sl);
                break;
            case 5:
                printf("请输入你要插入的位置：");
                int pos;
                scanf("%d",&pos);
                printf("\n");
                printf("请输入你要插入的数据：");
                scanf("%d",&val);
                Inerst(&sl,pos,val);
                break;
            case 6:
                {
                    
                    printf("请输入你要查找的数据：");
                    scanf("%d",&val);
                    int ret = Find(&sl,val);
                    if(ret != 0)
                        printf("找到了，该数据在顺序表中的对应下标为：%d",ret);
                }
                break;
            case 7:
                {

                    printf("请输入你要修改的数据的下标：");
                    int pos;
                    scanf("%d",&pos);
                    printf("\n");
                    printf("请输入你要修改的数据：");
                    scanf("%d",&val);
                    ListModify(&sl,pos,val);
                    printf("修改成功！\n");
                }
                break;
            case 8:
                printf("你确定要销毁数据吗？\n");
                printf("请输入1进行确定，0即取消：");
                scanf("%d",&val);
                if(val == 1)
                    Destroy(&sl);
                printf("销毁成功！\n");
                break;
            case 9:
                PrintSList(&sl);
                break;
            case 0:
                printf("感谢您的使用，祝您生活愉快！\n");
                break;
            default:
                printf("输入有误，请重新输入！\n");
                break;
        }

    }while(enter);
    
    return 0;
}
