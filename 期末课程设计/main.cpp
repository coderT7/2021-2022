#define _CRT_SECURE_NO_WARNINGS 1
#include"Mangerment.h"
#include"Window.h"
#include<ctime>
int main()
{
	srand((unsigned int)time(nullptr));
	//��������
	Window window(1024,1024,EW_NOCLOSE);
	//���ô��ڱ���
	window.setWindowTitle("ְ������ϵͳ");
	//ʵ�����������
	Mangerment manger;
	//��ʼ����������Ҫ���ֵĹ���
	manger.run();
	return window.exec();
}
