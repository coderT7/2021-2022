#ifndef CHOOSELEVELSCENE_H
#define CHOOSELEVELSCENE_H

#include <QMainWindow>
#include"playscene.h"
class chooseLevelScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit chooseLevelScene(QWidget *parent = nullptr);
    //背景图添加
    void paintEvent(QPaintEvent *event);
    //游戏场景对象
    PlayScene * play = NULL;
signals:
    //自定义信号，告诉主场景点击了返回按钮
    void chooseBack();
};

#endif // CHOOSELEVELSCENE_H
