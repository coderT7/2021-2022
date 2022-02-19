#include<QMenu>
#include<QMenuBar>
#include<QPainter>
#include<QPixmap>
#include<QLabel>
#include"mypushbutton.h"
#include "chooselevelscene.h"
chooseLevelScene::chooseLevelScene(QWidget *parent)
    : QMainWindow{parent}
{
    //配置选择关卡的场景
    this->setFixedSize(320,588);
    //设置图标
    this->setWindowIcon(QPixmap(":/n/res/Coin0001.png"));
    //设置标题
    this->setWindowTitle("选择关卡场景");
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
        //主场景需要监听chooseLevelScene的返回按钮
        emit this->chooseBack();
    });
    //创建关卡按钮（20个）
    for(int i = 0; i < 20; i++)
    {
        MyPushButton * gameBtn = new MyPushButton(":/n/res/LevelIcon.png");
        gameBtn->setParent(this);
        gameBtn->move(25 + i % 4 * 70, 130 + i / 4 * 70);

        //需监听每个按钮的点击事件，进入到游戏场景
        connect(gameBtn,&MyPushButton::clicked,[=](){
            QString str = QString("您选择的是第 %1 关").arg(i+1);
            qDebug() << str;

            this->hide();//隐藏选择关卡场景
            play = new PlayScene(i+1);//创建游戏场景
            play->show();//显示游戏场景

            //监听play中的返回按钮
            connect(play,&PlayScene::chooseBack,[=](){
               delete play;
               this->show();
               play = NULL;
            });
        });

        QLabel * label = new QLabel;
        label->setParent(this);
        label->setFixedSize(gameBtn->width(),gameBtn->height());
        label->setText(QString::number(i+1));
        label->move(25 + i % 4 * 70, 130 + i / 4 * 70);
        //默认左对齐，需设置水平居中且垂直居中
        label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        //由于标签覆盖了按钮，故需设置让鼠标进行穿透,标签接收点击释放后按钮也能接收到
        label->setAttribute(Qt::WA_TransparentForMouseEvents);
    }
}
//设置背景
void chooseLevelScene::paintEvent(QPaintEvent *event)
{
    //加载背景图
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/n/res/OtherSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    //加载标题
    pix.load(":/n/res/Title.png");
    painter.drawPixmap(this->width()*0.5-pix.width()*0.5,30,pix.width(),pix.height(),pix);

}
