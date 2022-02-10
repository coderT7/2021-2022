#include "widget.h"
#include "ui_widget.h"
#include<QPushButton>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPushButton * btn = new QPushButton;
    btn->setParent(this);
    btn->setText("你好");

    QPushButton * btn2 = new QPushButton("world",this);
    btn2->move(100,200);

    connect(btn,&QPushButton::clicked,this,&QWidget::close);

    resize(600,400);

    setFixedSize(600,400);

    setWindowTitle("First QT");
}

Widget::~Widget()
{
    delete ui;
}

