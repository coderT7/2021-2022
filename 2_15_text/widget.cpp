#include "widget.h"
#include "ui_widget.h"
#include<QTimer>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QTimer * timer = new QTimer(this);
    timer->start(1000);

    connect(timer,&QTimer::timeout,[=](){
        static int sum = 1;
        ui->label_2->setText(QString::number(sum++));
    });
    connect(ui->btn_begin,&QPushButton::clicked,[=](){
       timer->start(1000);
    });
    connect(ui->btn_stop,&QPushButton::clicked,[=](){
        timer->stop();
    });
}

Widget::~Widget()
{
    delete ui;
}

