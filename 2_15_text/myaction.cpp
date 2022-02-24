#include "myaction.h"
#include<QDebug>
#include<QEnterEvent>
#include<QMouseEvent>
MyAction::MyAction(QWidget *parent)
    : QLabel{parent}
{
    setMouseTracking(true);
}
void MyAction::enterEvent(QEnterEvent *event)
{
    qDebug() << "鼠标进入了";

}
void MyAction::leaveEvent(QEvent *)
{
    qDebug() << "鼠标离开了";
}
void MyAction::mousePressEvent(QMouseEvent *ev)
{
    if(ev->button() == Qt::LeftButton)
    {
        qDebug() << "鼠标按下了";
        qDebug() << QString("x = %1  y = %2  globalX = %3  globalY = %4")
                    .arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
    }

}
void MyAction::mouseReleaseEvent(QMouseEvent *ev)
{
    if(ev->button() == Qt::LeftButton)
        qDebug() << "鼠标释放了";
}
void MyAction::mouseMoveEvent(QMouseEvent *ev)
{
//    if(ev->buttons() & Qt::LeftButton)
//    {
        qDebug() << "鼠标移动了";
        qDebug() << QString("x = %1  y = %2  globalX = %3  globalY = %4")
                    .arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
//    }
}
