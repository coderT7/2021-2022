#include "mainscene.h"
#include "ui_mainscene.h"
#include<QPainter>
#include<QPixmap>
#include"mypushbutton.h"
#include<QTimer>

MainScene::MainScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScene)
{
    ui->setupUi(this);

    setFixedSize(320,588);
    connect(ui->actionExit,&QAction::triggered,[=]()
    {
        this->close();
    });
    setWindowIcon(QIcon(":/n/res/Coin0001.png"));
    setWindowTitle("翻转金币");

    //准备开始按钮的音效

    //创建开始按钮
    MyPushButton * startBtn = new MyPushButton(":/n/res/MenuSceneStartButton.png");
    startBtn->setParent(this);
    startBtn->move(this->width() * 0.5 - startBtn->width()*0.5,this->height() * 0.7);

    //实例化选择关卡场景
    levelScene = new chooseLevelScene(this);
    //监听选择关卡的返回按钮的信号
    connect(levelScene,&chooseLevelScene::chooseBack,[=](){
       QTimer::singleShot(500,this,[=](){
       levelScene->hide();//选择场景隐藏
       this->show();//重新显示主场景
       });
    });
    //动效和场景切换
    connect(startBtn,&QPushButton::clicked,[=](){
        //动态效果
        startBtn->zoom1();//自上向下
        startBtn->zoom2();//自下向上
        //自身延时0.5秒后隐藏(定时器）
        QTimer::singleShot(500,this,[=](){
            this->hide();
            //切换场景到选择关卡
            levelScene->show();
        });


    });
}
void MainScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    //加载背景
    QPixmap pix;
    pix.load(":/n/res/MenuSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
//    //加载标题
//    pix.load(":/n/res/Title.png");
//    //缩放图片
//    pix = pix.scaled(pix.width()*0.5,pix.height()*0.5);
//    //绘制标题
//    painter.drawPixmap(10,30,pix.width(),pix.height(),pix);

}
MainScene::~MainScene()
{
    delete ui;
}

