#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QMainWindow>
#include"chooselevelscene.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainScene; }
QT_END_NAMESPACE

class MainScene : public QMainWindow
{
    Q_OBJECT

public:
    MainScene(QWidget *parent = nullptr);
    ~MainScene();
    //将背景填上
    void paintEvent(QPaintEvent *);
    //选择关卡的场景
    chooseLevelScene * levelScene = NULL;

private:
    Ui::MainScene *ui;
};
#endif // MAINSCENE_H
