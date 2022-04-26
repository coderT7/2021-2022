#pragma once
#include"config.h"

class Window
{
public:
	Window(int width, int height, int flag);
	void setWindowTitle(const std::string& title);
	//��ֹ���ˣ��������ᣩ
	int exec();

	static int width();
	static int height();
	static void clear();
	static void beginDraw();
	static void flushDraw();
	static void endDraw();

	//��̬��Ա����ֻ�ܷ��ʾ�̬��Ա����
	//������Ϣ
	inline static bool hasMsg() { return ::peekmessage(&m_msg, EM_KEY | EM_MOUSE); };
	//������Ϣ
	inline static const ExMessage& getMsg() { return m_msg; };
	 
private:
	HWND m_HWND; //���ھ��
	//ʹ��C++17���������﷨��ʹ�þ�̬��Ա�������Բ�������������ж���
	inline static ExMessage m_msg; //�Ƿ�����Ϣ�����/���̣�
};

