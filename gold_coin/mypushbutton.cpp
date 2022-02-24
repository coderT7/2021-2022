#include "mypushbutton.h"
#include<QPixmap>
#include<QPushButton>
#include<QPainter>
#include<QDebug>
#include<QPropertyAnimation>
//MyPushButton::MyPushButton(QWidget *parent)
//    : QWidget{parent}
//{

//}
MyPushButton::MyPushButton(QString normalImg, QString pressImg)
{
    this->normalImg = normalImg;
    this->pressImg = pressImg;
    QPixmap pix;
    bool ret = pix.load(this->normalImg);
    if(!ret)
    {
        qDebug() << this->normalImg << "图片加载失败" ;
        return;
    }
    //设置按钮固定大小
    this->setFixedSize(pix.width(),pix.height());
    //设置不规则图片样式
    this->setStyleSheet("QPushButton{border:0px;}");
    //设置图标
    this->setIcon(pix);
    //设置图标大小
    this->setIconSize(QSize(pix.width(),pix.height()));
}
//设置返回按钮的动效
void MyPushButton::mousePressEvent(QMouseEvent *e)
{
    if(this->pressImg != "")
    {
        QPixmap pix;
        bool ret = pix.load(this->pressImg);
        if(!ret)
        {
            qDebug() << "图片加载失败" ;
            return;
        }
        //设置按钮固定大小
        this->setFixedSize(pix.width(),pix.height());
        //设置不规则图片样式
        this->setStyleSheet("QPushButton{border:0px;}");
        //设置图标
        this->setIcon(pix);
        //设置图标大小
        this->setIconSize(QSize(pix.width(),pix.height()));
    }
    return QPushButton::mousePressEvent(e);
}
void MyPushButton::mouseReleaseEvent(QMouseEvent *e)
{
    if(this->pressImg != "")
    {
        QPixmap pix;
        bool ret = pix.load(this->normalImg);
        if(!ret)
        {
            qDebug() << "图片加载失败" ;
            return;
        }
        //设置按钮固定大小
        this->setFixedSize(pix.width(),pix.height());
        //设置不规则图片样式
        this->setStyleSheet("QPushButton{border:0px;}");
        //设置图标
        this->setIcon(pix);
        //设置图标大小
        this->setIconSize(QSize(pix.width(),pix.height()));
    }
    return QPushButton::mouseReleaseEvent(e);
}
void MyPushButton::zoom1()
{
    //创建动画对象
    QPropertyAnimation * animation1 = new QPropertyAnimation(this,"geometry");
    //设置动画持续的时间间隔
    animation1->setDuration(200);
    //设置起始位置
    animation1->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    animation1->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
    //设置缓和曲线
    animation1->setEasingCurve(QEasingCurve::OutBounce);
    animation1->start();
}
void MyPushButton::zoom2()
{
    //创建动画对象
    QPropertyAnimation * animation2 = new QPropertyAnimation(this,"geometry");
    //设置动画持续的时间间隔
    animation2->setDuration(200);
    //设置起始位置
    animation2->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    animation2->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
    //设置缓和曲线
    animation2->setEasingCurve(QEasingCurve::OutBounce);
    animation2->start();
}
