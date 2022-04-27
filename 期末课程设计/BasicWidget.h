#pragma once
class BasicWidget
{
public:
	BasicWidget(int x, int y, int w, int h);
	//��������������ֹ��������г�Ա���ڶ��ϴ���ʱ��Ҫ�����ͷ�
	virtual ~BasicWidget();
	int x();
	int y();
	int width();
	int height();
	//���ÿؼ��Ŀ�͸�
	void setFixedSize(int w, int h);
	//�ƶ��ؼ���λ��
	void move(int x, int y);
	//��ʾ�ؼ�
	virtual void show() = 0;

protected:
	int m_x;
	int m_y;
	int m_w;
	int m_h;
};

