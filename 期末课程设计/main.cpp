#define _CRT_SECURE_NO_WARNINGS 1
#include"Mangerment.h"
#include"Window.h"

int main()
{
	Window window(960,640,EW_SHOWCONSOLE);

	window.setWindowTitle("ְ������ϵͳ");

	Mangerment manger;
	manger.run();
	return window.exec();
}
