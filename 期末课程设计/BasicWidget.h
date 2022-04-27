#pragma once
class BasicWidget
{
public:
	BasicWidget(int x, int y, int w, int h);
	//增加虚析构，防止子类对象有成员是在堆上创建时需要父类释放
	virtual ~BasicWidget();
	int x();
	int y();
	int width();
	int height();
	//设置控件的宽和高
	void setFixedSize(int w, int h);
	//移动控件的位置
	void move(int x, int y);
	//显示控件
	virtual void show() = 0;

protected:
	int m_x;
	int m_y;
	int m_w;
	int m_h;
};

