#define _CRT_SECURE_NO_WARNINGS 1
#include"Mangerment.h"
#include"Window.h"

int main()
{
	//��������
	Window window(865,1200,EW_SHOWCONSOLE | EW_NOCLOSE);
	//���ô��ڱ���
	window.setWindowTitle("ְ������ϵͳ");
	//ʵ�����������
	Mangerment manger;
	//��ʼ����������Ҫ���ֵĹ���
	manger.run();
	return window.exec();
}
