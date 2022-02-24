#ifndef MYCOIN_H
#define MYCOIN_H

#include <QPushButton>
#include<QTimer>
class MyCoin : public QPushButton
{
    Q_OBJECT
public:
//    explicit MyCoin(QWidget *parent = nullptr);
    MyCoin(QString btnImg);

    int posX;//金币的x坐标
    int posY;//金币的y坐标
    bool flag;//正反的标志

    void changeFlag();//改变标志，并执行翻转效果
    QTimer * timer1;//正面翻转至反面的定时器
    QTimer * timer2;//反面翻转至正面的定时器
    int min = 1;//最小图片
    int max = 8;//最大图片

    //执行动画的标志,一次动画执行完后再执行下一次的动画
    bool isAnimation = false;
    //重写按下的事件
    void mousePressEvent(QMouseEvent *e);
    //判断胜利的标志
    bool isWin = false;
signals:

};

#endif // MYCOIN_H
