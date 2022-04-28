#define _CRT_SECURE_NO_WARNINGS 1
#include"Mangerment.h"
#include"Window.h"

int main()
{
	//创建窗口
	Window window(845,1350,EW_SHOWCONSOLE);
	//设置窗口标题
	window.setWindowTitle("职工管理系统");
	//实例化管理对象
	Mangerment manger;
	//开始整个程序主要部分的工作
	manger.run();
	return window.exec();
}
