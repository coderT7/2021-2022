#define _CRT_SECURE_NO_WARNINGS 1
#include"Mangerment.h"
#include"Window.h"

int main()
{
	//��������
	Window window(640,900,EW_SHOWCONSOLE);
	//���ô��ڱ���
	window.setWindowTitle("ְ������ϵͳ");
	//ʵ�����������
	Mangerment manger;
	//��ʼ����������Ҫ���ֵĹ���
	manger.run();
	return window.exec();
}
