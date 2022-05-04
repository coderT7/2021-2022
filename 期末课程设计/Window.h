#pragma once
#include"config.h"

class Window
{
public:
	Window(int width, int height, int flag);
	//设置窗口的标题
	void setWindowTitle(const std::string& title);
	//防止闪退（基本不会）
	int exec();
	//获取窗口的宽高
	static int width();
	static int height();
	//对窗口的基本操作
	static void clear();//清空窗口
	static void beginDraw();//绘制窗口背景
	static void flushDraw();//刷新窗口背景
	static void endDraw();//结束绘制窗口背景

	//静态成员函数只能访问静态成员变量
	//监听消息
	inline static bool hasMsg() { return ::peekmessage(&m_msg, EM_KEY | EM_MOUSE); };
	//返回消息
	inline static const ExMessage& getMsg() { return m_msg; };
	 
private:
	HWND m_HWND; //窗口句柄
	//使用C++17内联的新语法，使得静态成员变量可以不用再在类外进行定义
	inline static ExMessage m_msg; //是否有消息（鼠标/键盘）
};

