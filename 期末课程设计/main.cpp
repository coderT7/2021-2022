#define _CRT_SECURE_NO_WARNINGS 1
#include"Management.h"
#include"Window.h"
#include<ctime>
#include<graphics.h>
#pragma comment(lib,"Winmm.lib")
int main()
{
#if 0
	mciSendString("open ./嘉宾.mp3 alias BGM", 0, 0, 0);
	mciSendString("play BGM", 0, 0, 0);
#endif
	//创建窗口
	Window window(1024,1024,EW_SHOWCONSOLE|EW_NOCLOSE);
	//设置窗口标题
	window.setWindowTitle("职工管理系统");
	//实例化管理对象
	Management manger;
	//开始整个程序主要部分的工作
	manger.run();
	return window.exec();
}
