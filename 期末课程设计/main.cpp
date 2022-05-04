#define _CRT_SECURE_NO_WARNINGS 1
#include"Mangerment.h"
#include"Window.h"
#include<ctime>
#include<graphics.h>
#pragma comment(lib,"Winmm.lib")
int main()
{
	mciSendString("open ./嘉宾.mp3 alias BGM", 0, 0, 0);
	mciSendString("play BGM", 0, 0, 0);

	srand((unsigned int)time(nullptr));
	//创建窗口
	Window window(1024,1024,EW_SHOWCONSOLE|EW_NOCLOSE);
	//设置窗口标题
	window.setWindowTitle("职工管理系统");
	//实例化管理对象
	Mangerment manger;
	//开始整个程序主要部分的工作
	manger.run();
	return window.exec();
}
