#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include"mycoin.h"
class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
//    explicit PlayScene(QWidget *parent = nullptr);
    PlayScene(int levelNum);

    int levelNum;//记录所选择的关卡

    //重写绘图事件
    void paintEvent(QPaintEvent *event);
    //维护关卡数据
    int gameArray[4][4];
    //维护生成的coin信息
    MyCoin * coinBtn[4][4];
    //判断胜利的标志
    bool isWin;
signals:
    void chooseBack();

};

#endif // PLAYSCENE_H
