#define _CRT_SECURE_NO_WARNINGS 1
#include"Management.h"
#include"Window.h"
#include<ctime>
#include<graphics.h>
#pragma comment(lib,"Winmm.lib")
int main()
{
#if 0
	mciSendString("open ./�α�.mp3 alias BGM", 0, 0, 0);
	mciSendString("play BGM", 0, 0, 0);
#endif
	//��������
	Window window(1024,1024,EW_SHOWCONSOLE|EW_NOCLOSE);
	//���ô��ڱ���
	window.setWindowTitle("ְ������ϵͳ");
	//ʵ�����������
	Management manger;
	//��ʼ����������Ҫ���ֵĹ���
	manger.run();
	return window.exec();
}
