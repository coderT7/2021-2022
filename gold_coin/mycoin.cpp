#include "mycoin.h"
#include<QPixmap>
#include<QDebug>
#include<QTimer>
//MyCoin::MyCoin(QWidget *parent)
//    : QWidget{parent}
//{

//}

MyCoin::MyCoin(QString btnImg)
{
    QPixmap pix;
    bool ret = pix.load(btnImg);
    if(!ret)
    {
        QString str = QString("图片%1加载失败").arg(btnImg);
        qDebug() << str;
    }
    this->setFixedSize(pix.width(),pix.height());
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(),pix.height()));

    //初始化定时器对象
    timer1 = new QTimer(this);
    timer2 = new QTimer(this);
    //金币翻银币
    connect(timer1,&QTimer::timeout,[=](){
       QPixmap pix;
       QString str = QString(":/n/res/Coin000%1.png").arg(this->min++);
       pix.load(str);

       this->setFixedSize(pix.width(),pix.height());
       this->setStyleSheet("QPushButton{border:0px;}");
       this->setIcon(pix);
       this->setIconSize(QSize(pix.width(),pix.height()));
       //判断如果翻转完毕，则停止计时器
       if(this->min > this->max)
       {
           this->min = 1;
           isAnimation = false;
           timer1->stop();
       }

    });

    //银币翻金币
    connect(timer2,&QTimer::timeout,[=](){
       QPixmap pix;
       QString str = QString(":/n/res/Coin000%1.png").arg(this->max--);
       pix.load(str);

       this->setFixedSize(pix.width(),pix.height());
       this->setStyleSheet("QPushButton{border:0px;}");
       this->setIcon(pix);
       this->setIconSize(QSize(pix.width(),pix.height()));
       //判断如果翻转完毕，则停止计时器
       if(this->max < this->min)
       {
           this->max = 8;
           isAnimation = false;
           timer2->stop();
       }

    });
}
void MyCoin::mousePressEvent(QMouseEvent *e)
{
    //如果正在做动画或者已经胜出，则鼠标按下不作反应
    if(this->isAnimation || this->isWin)
        return;
    else
        QPushButton::mousePressEvent(e);
}

//改变标志，并执行翻转效果
void MyCoin::changeFlag()
{
    //如果是正面则翻转成反面
    if(this->flag)
    {
        timer1->start(30);
        isAnimation = true;
        this->flag = false;
    }
    //反面则翻转成正面
    else
    {
        timer2->start(30);
        isAnimation = true;
        this->flag = true;
    }
}
