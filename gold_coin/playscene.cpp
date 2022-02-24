#include "playscene.h"
#include<QMenuBar>
#include<QPainter>
#include<QPixmap>
#include<QTimer>
#include<QDebug>
#include<QLabel>
#include<mypushbutton.h>
#include<mycoin.h>
#include"dataconfig.h"
#include<QPropertyAnimation>
//PlayScene::PlayScene(QWidget *parent)
//    : QMainWindow{parent}
//{

//}
PlayScene::PlayScene(int levelNum)
{
    QString str = QString("进入了第 %1 关").arg(levelNum);
    qDebug() << str;

    this->levelNum = levelNum;

    //初始化游戏场景
    //固定场景大小
    this->setFixedSize(320,588);
    //设置图标
    this->setWindowIcon(QIcon(":/n/res/Coin0001.png"));
    //设置标题
    this->setWindowTitle("翻转金币");
    //创建菜单栏
    QMenuBar * menuBar = new QMenuBar;
    setMenuBar(menuBar);

    //创建开始菜单
    QMenu * startMenu = menuBar->addMenu("开始");
    //创建退出的菜单项
    QAction * action = startMenu->addAction("退出");
    //点击退出即关闭
    connect(action,&QAction::triggered,[=](){
        this->close();
    });
    //返回按钮
    MyPushButton * backBtn = new MyPushButton(":/n/res/BackButton.png",":/n/res/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(this->width()-backBtn->width(),this->height()-backBtn->height());
    //点击返回上一层
    connect(backBtn,&MyPushButton::clicked,[=](){
        qDebug() << "游戏中按下了返回按钮";
        QTimer::singleShot(200,this,[=](){
            emit this->chooseBack();
        });
    });

    //显示当前关卡数
    QLabel * label = new QLabel(this);
    QFont font;
    font.setFamily("华文新魏");
    font.setPointSize(20);
    QString str1 = QString("Level:%1").arg(QString::number(this->levelNum));
    label->setFont(font);
    label->setText(str1);
    label->setGeometry(QRect(30,this->height()-50,120,50));//设置大小和位置

    //初始化每个关卡的二维数组
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            this->gameArray[i][j] = dataConfig().mData[this->levelNum][i][j];
        }
    }

    //胜利图片的现实
    QLabel * winLabel = new QLabel;
    QPixmap tmpPix;
    tmpPix.load(":/n/res/LevelCompletedDialogBg.png");
    winLabel->setGeometry(0,0,tmpPix.width(),tmpPix.height());
    winLabel->setPixmap(tmpPix);
    winLabel->setParent(this);
    //置于显示界面的上方
    winLabel->move((this->width()-tmpPix.width())*0.5,-tmpPix.height());

    //显示金币的背景图
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            //绘制背景图
            QPixmap pix=QPixmap(":/n/res/BoardNode(1).png");
            QLabel *label=new QLabel;
            label->setGeometry(0,0,pix.width(),pix.height());
            label->setPixmap(pix);
            label->setParent(this);
            label->move(57+i*50,200+j*50);

            //创建金币
            QString str;
            if(this->gameArray[i][j] == 1)
            {
                str = ":/n/res/Coin0001.png";
            }
            else
            {
                str = ":/n/res/Coin0008.png";
            }
            MyCoin * coin = new MyCoin(str);
            coin->setParent(this);
            coin->move(59+i*50,204+j*50);

            coin->posX = i;
            coin->posY = j;
            coin->flag = gameArray[i][j];

            //将金币放入到对应的二维数组里进行维护，便于进行游戏
            coinBtn[i][j] = coin;
            //点击金币进行翻转
            connect(coin,&MyCoin::clicked,[=](){
               //进行点击时，整个界面的硬币都不允许点击，防止短间隔内多次点击不同的按钮造成bug
               for(int i = 0; i < 4; i++)
                   for(int j = 0; j < 4; j++)
                       this->coinBtn[i][j]->isWin = true;
               coin->changeFlag();
               //维护住游戏状态的数组，便于最后输赢的判断
               this->gameArray[i][j] = this->gameArray[i][j] == 0 ? 1 : 0;

               //对周围金币也进行 延时翻转
               //需对翻转的范围进行判断
               QTimer::singleShot(300,this,[=]{
                   if(coin->posX + 1 <= 3)//右侧
                   {
                       coinBtn[coin->posX+1][coin->posY]->changeFlag();
                       this->gameArray[coin->posX+1][coin->posY]
                               = this->gameArray[coin->posX+1][coin->posY] == 0 ? 1 : 0;
                   }
                   if(coin->posX - 1 >= 0)//左侧
                   {
                       coinBtn[coin->posX-1][coin->posY]->changeFlag();
                       this->gameArray[coin->posX-1][coin->posY]
                               = this->gameArray[coin->posX-1][coin->posY] == 0 ? 1 : 0;
                   }
                   if(coin->posY + 1 <= 3)//上侧
                   {
                       coinBtn[coin->posX][coin->posY+1]->changeFlag();
                       this->gameArray[coin->posX][coin->posY+1]
                               = this->gameArray[coin->posX][coin->posY+1] == 0 ? 1 : 0;
                   }
                   if(coin->posX - 1 >= 0)//下侧
                   {
                       coinBtn[coin->posX][coin->posY-1]->changeFlag();
                       this->gameArray[coin->posX][coin->posY-1]
                               = this->gameArray[coin->posX][coin->posY-1] == 0 ? 1 : 0;
                   }
                   //当翻转完毕后再解除禁止点击的效果
                   for(int i = 0; i < 4; i++)
                       for(int j = 0; j < 4; j++)
                           this->coinBtn[i][j]->isWin = false;
                   //金币翻转后则判断是否胜利
                   this->isWin = true;
                   for(int i = 0; i < 4; i++)
                   {
                       for(int j = 0; j < 4; j++)
                       {
                           if(coinBtn[i][j]->flag == false)
                           {
                               this->isWin = false;
                               break;
                           }
                       }
                   }
                   if(this->isWin)
                   {
                      qDebug() << "win";
                      //将所有按钮的胜利标志改为true，如果再次点击则无反应
                      for(int i = 0; i < 4; i++)
                      {
                          for(int j = 0; j < 4; j++)
                          {
                              coinBtn[i][j]->isWin = true;
                          }
                      }
                      //将胜利的图片移动到界面中
                      QPropertyAnimation * animation = new QPropertyAnimation(winLabel,"geometry");
                      //设置时间间隔
                      animation->setDuration(1000);
                      //设置开始位置
                      animation->setStartValue(QRect(winLabel->x(),winLabel->y(),
                                                     winLabel->width(),winLabel->height()));
                      //设置结束位置
                      animation->setEndValue(QRect(winLabel->x(),winLabel->y()+114,
                                                     winLabel->width(),winLabel->height()));
                      //设置缓和曲线
                      animation->setEasingCurve(QEasingCurve::OutBounce);
                      //开始动画
                      animation->start();
                   }

               });

            });

        }
    }
}
void PlayScene::paintEvent(QPaintEvent *event)
{
    //加载背景图
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/n/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    //加载标题
    pix.load(":/n/res/Title.png");
    //缩放图片
    pix = pix.scaled(pix.width()*0.5,pix.height()*0.5);
    painter.drawPixmap(10,30,pix.width(),pix.height(),pix);
}
