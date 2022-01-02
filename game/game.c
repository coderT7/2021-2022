#include"game.h"

//记录玩家最近一次输入的下标
int x = 0;
int y = 0;

void Menu()
{
    printf("#########################\n");
    printf("## 1.PLAY       0.EXIT ##\n");
    printf("#########################\n");
    printf("please enter your choose:\n");
}

//以x，y为起点，按照特定的方向，求连续相等的最大棋子数
int ChessCount(int board[][COL],int row,int col,enum Dir dir)
{
    //往不同的方向走，x，y有相对应的强相关的变化
    //将落子点先进行记录，便于后续进行坐标变化并判断是否相同，不改变上一个玩家的落子点
    int _x = x - 1;
    int _y = y - 1;
    int count = 0;
    //朝八个小方向去统计，每次调用该函数都是往同一个方向去统计棋子个数
    while(1)
    {
        switch(dir)
        {
            case LEFT:
                _y--;
                break;
            case RIGHT:
                _y++;
                break;
            case UP:
                _x--;
                break;
            case DOWN:
                _x++;
                break;
            case LEFT_UP:
                _x--, _y--;
                break;
            case RIGHT_DOWN:
                _x++,_y++;
                break;
            case RIGHT_UP:
                _x--,_y++;
                break;
            case LEFT_DOWN:
                _x++,_y--;
                break;
            default://所有情况已枚举
                break;
        }
        //判断其四周的坐标是否还在棋盘范围内
        if(_x < 0 || _x > row - 1 || _y < 0 || _y > col -1)
            break;
        //判断所落子和对应方向的棋子是否相同
        if(board[x-1][y-1] == board[_x][_y])
            count++;
        else break;
    }
    return count;
}

int IsOver(int board[][COL],int row,int col)
{
    //从前一个用户落子的判断哪进行统计
    //也就是x，y，判断四个大方向的棋子数即可
    //往四个方向去统计时，并没有统计上自身所在的位置
    int count1 = ChessCount(board,row,col,LEFT) + ChessCount(board,row,col,RIGHT)+1;
    int count2 = ChessCount(board,row,col,UP) + ChessCount(board,row,col,DOWN)+1;
    int count3 = ChessCount(board,row,col,LEFT_UP) + ChessCount(board,row,col,RIGHT_DOWN)+1;
    int count4 = ChessCount(board,row,col,LEFT_DOWN) + ChessCount(board,row,col,RIGHT_UP)+1;
    //任何一个方向有大于五个棋子连续，即出结果了
    //一定有人胜出
    if(count1 >= 5 || count2 >= 5 || count3 >= 5 || count4 >= 5)
    {
        //x,y保存的上一个用户落得子，只需要判定x，y是谁落的棋子即是谁胜出
        //return board[x-1][y-1];
        if(board[x-1][y-1] == PLAYER1)
            return PLAYER1_WIN;
        else 
            return PLAYER2_WIN;
    }
    //否则判断是否平局
    int i = 0;
    for(i = 0; i < row; i++)
    {
        int j = 0;
        for(j = 0; j < col; j++)
            if(board[i][j] == 0)
                return NEXT;
    }
}
void ShowBoard(int board[][COL],int row,int col)
{
    //清屏的格式控制，网上搜即可
    printf("\e[1;1H\e[2J");
    //将数组内容可视化
    printf("  ");
    int i = 1;
    for(i = 1; i <= col; i++)
        printf("%3d",i);
    printf("\n");
    for(i = 0; i < row; i++)
    {
        printf("%2d ",i+1);
        int j;
        for(j = 0; j < col; j++)
        {
            if(board[i][j] == 0)
                printf(" . ");
            //显示符号网上搜即可
            else if(board[i][j] == PLAYER1)
                printf(" ● ");
            else 
                printf(" ○ ");
        }
        printf("\n");
    }
}
void PlayerMove(int board[][COL],int row,int col,int player)
{
    while(1)
    {
        //要判断其合法性，并去重
        printf("Player[%d] please enter your pos# ",player);
       
        scanf("%d%d",&x,&y);
        if(x < 1 || x > row || y < 1 || y > col)
        {

            printf("pos is wrong!\n");
            continue;
        }   
        else if(board[x-1][y-1] != 0)
        {
            printf("This pos is occupied!\n");
            continue;
        }
        else 
        {
            board[x-1][y-1] = player;
            break;
        }
    }   
}
void Game()
{

    //建立棋盘，并进行初始化
    int board[ROW][COL];
    memset(board,0,sizeof(board));
    int result = NEXT;
    while(1)
    {
        ShowBoard(board,ROW,COL);
        PlayerMove(board,ROW,COL,PLAYER1);
        //玩家落子后便判定输赢，其二者为强绑定关系
        result = IsOver(board,ROW,COL);
        //棋局结果只有四种：玩家1赢/玩家2赢/平局/继续游戏
        //结果只要不为NEXT则就退出游戏
        if(result != NEXT)
            break;
        //判断完玩家1未胜出才到玩家2进行落子
        ShowBoard(board,ROW,COL);
        PlayerMove(board,ROW,COL,PLAYER2);
        result = IsOver(board,ROW,COL);
        if(result != NEXT)
            break;
    }

    ShowBoard(board,ROW,COL);
    switch(result)
    {
        case PLAYER1_WIN:
            printf("恭喜用户1取得本局胜利！\n");
            break;
        case PLAYER2_WIN:
            printf("恭喜用户2取得本局胜利！\n");
            break;
        case DRAW:
            printf("和棋！\n");
            break;
        default:
            //不会有该种情况，故此什么都不做
            break;
    }

}
