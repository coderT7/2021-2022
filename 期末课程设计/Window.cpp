#include "Window.h"
#include<iostream>
//静态成员变量需要在类内声明，类外初始化
//在该源文件直接初始化可以避免重定义的情况发生
#if 0
//可以直接使用内联声明（C++17标准）
ExMessage Window::m_msg; //是否有消息（鼠标/键盘）
#endif
Window::Window(int width, int height, int flag)
{
    //::说明使用的是全局函数
    m_HWND = ::initgraph(width, height, flag);
    ::setbkmode(TRANSPARENT);
}

void Window::setWindowTitle(const std::string& title)
{
    //这里在Unicode字符集下存在多字节和宽字节的转换问题
    //可以在项目属性里设置，也可以直接使用预编译指令
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
