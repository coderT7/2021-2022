#include"game.h"
#include"ProcBar.h"


int main()
{
    int choose = 0;
    do 
    {
        Menu();
        scanf("%d",&choose);
        switch(choose)
        {
            case 1:
                process_bar();
                Game();
                break;
            case 0:
                printf("ByeBye!\n");
                break;
            default:
                printf("enter error!please enter again:/n");
                break;
        }
    }while(choose);
    return 0;
}
