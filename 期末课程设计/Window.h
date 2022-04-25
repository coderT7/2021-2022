#pragma once
#include"config.h"
class Window
{
public:
	Window(int width, int height, int flag);
	void setWindowTitle(const std::string& title);
	int exec();

	static int width();
	static int height();
	static void clear();
	static void beginDraw();
	static void flushDraw();
	static void endDraw();

	//静态成员函数只能访问静态成员变量
	inline static bool haveMsg() { return ::peekmessage(&m_msg, EM_KEY | EM_MOUSE); };
	inline static const ExMessage& getMsg() { return m_msg; };
	 
private:
	HWND m_HWND; //窗口句柄
	inline static ExMessage m_msg; //是否有消息（鼠标/键盘）
};

