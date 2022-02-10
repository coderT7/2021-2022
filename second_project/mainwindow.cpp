#include "mainwindow.h"
#include<QMenuBar>
#include<QToolBar>
#include<QPushButton>
#include<Qstatusbar>
#include<QDockWidget>
#include<QTextEdit>
#include<QLabel>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //重置窗口大小
    setFixedSize(600,400);
    //设置窗口名称
    setWindowTitle("SecondProject");
    //菜单栏创建
    QMenuBar * bar = menuBar();
    //在窗口中添加菜单栏
    setMenuBar(bar);
    //添加菜单
    QMenu * fileName = bar->addMenu("文件");
    QMenu * editName = bar->addMenu("编辑");
    //添加菜单项
    QAction * createFile = fileName->addAction("新建");
    fileName->addSeparator();//设置分割线
    QAction * openFile = fileName->addAction("打开");
    //新建工具栏
    QToolBar * toolBar = new QToolBar(this);
    //在窗口添加工具栏
    addToolBar(Qt::LeftToolBarArea, toolBar);
    //设置工具栏默认停靠位置
    toolBar->setAllowedAreas(Qt::TopToolBarArea);
    //设置是否可以浮动
    toolBar->setFloatable(false);
    //设置是否可以移动工具栏
    toolBar->setMovable(true);
    //向工具栏中添加模块
    toolBar->addAction(createFile);
    toolBar->addSeparator();//两个模块之间添加分割线
    toolBar->addAction(openFile);
    //添加控件
    QPushButton * btn = new QPushButton(this);
    btn->setText("关闭窗口");
    toolBar->addWidget(btn);
    connect(btn,&QPushButton::clicked,this,&QWidget::close);
    //添加状态栏
    QStatusBar * stBar = new QStatusBar();
    setStatusBar(stBar);
    //添加标签控件
    QLabel * label = new QLabel(this);
    stBar->addWidget(label);
    //创建铆接部件
    QDockWidget * dockWidget = new QDockWidget("浮动窗口", this);
    addDockWidget(Qt::BottomDockWidgetArea, dockWidget);
    dockWidget->setAllowedAreas(Qt::TopDockWidgetArea | Qt::BottomDockWidgetArea);
    //添加中心部件
    QTextEdit * edit = new QTextEdit(this);
    setCentralWidget(edit);

}

MainWindow::~MainWindow()
{
}

