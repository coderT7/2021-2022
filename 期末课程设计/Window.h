#pragma once
#include"config.h"

class Window
{
public:
	Window(int width, int height, int flag);
	//���ô��ڵı���
	void setWindowTitle(const std::string& title);
	//��ֹ���ˣ��������ᣩ
	int exec();
	//��ȡ���ڵĿ��
	static int width();
	static int height();
	//�Դ��ڵĻ�������
	static void clear();//��մ���
	static void beginDraw();//���ƴ��ڱ���
	static void flushDraw();//ˢ�´��ڱ���
	static void endDraw();//�������ƴ��ڱ���

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

