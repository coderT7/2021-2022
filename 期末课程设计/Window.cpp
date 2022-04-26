#include "Window.h"
#include<iostream>
//��̬��Ա������Ҫ�����������������ʼ��
//�ڸ�Դ�ļ�ֱ�ӳ�ʼ�����Ա����ض�����������
#if 0
//����ֱ��ʹ������������C++17��׼��
ExMessage Window::m_msg; //�Ƿ�����Ϣ�����/���̣�
#endif
Window::Window(int width, int height, int flag)
{
    //::˵��ʹ�õ���ȫ�ֺ���
    m_HWND = ::initgraph(width, height, flag);
    ::setbkmode(TRANSPARENT);
}

void Window::setWindowTitle(const std::string& title)
{
    //������Unicode�ַ����´��ڶ��ֽںͿ��ֽڵ�ת������
    //��������Ŀ���������ã�Ҳ����ֱ��ʹ��Ԥ����ָ��
    ::SetWindowText(m_HWND, title.c_str());
}

int Window::exec()
{
    return getchar();
}

int Window::width()
{
    return ::getwidth();
}

int Window::height()
{
    return ::getheight();
}

void Window::clear()
{
    ::cleardevice();
}

void Window::beginDraw()
{
    ::BeginBatchDraw();
}

void Window::flushDraw()
{
    ::FlushBatchDraw();
}

void Window::endDraw()
{
    ::EndBatchDraw();
}
