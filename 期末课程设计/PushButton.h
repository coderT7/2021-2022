#pragma once
#include "BasicWidget.h"

#include"config.h"

class PushButton :
    public BasicWidget
{
public:
    PushButton(const std::string& text = "PushButton", int x = 0, int y = 0, int w = 100, int h = 30);
    void show()override;
    //�ж�����Ƿ���밴ť
    virtual bool is_in();
    //�ж�����Ƿ�����ť
    virtual bool is_clicked();
    //�жϰ�ť�Ƿ񱻵����
    bool was_clicked();
    virtual void event_loop(const ExMessage& msg);
    //���ð�ť��Ĭ�ϱ�����ɫ�Լ�����������ɫ������ѡ�е���ʵ��Ч��
    //������Ϊ������ƣ��о�͸���ĸ��ÿ����������Ҳûɶ���ˣ��Ѿ�ʵ���ˣ����������ˣ�
    void setBackgroundColor(COLORREF color);
    void setHoverColor(COLORREF color);//hover���ǻ���Ư����
public:
    //��־�Ű�ť�Ƿ񱻵��������ֹһЩ��ť���ظ�����������߼�bug���������Ӱ�ť���ظ��������ظ���ӣ�
    bool flag;
protected:
    //��ť�ı�
    std::string m_text;
    //��ť��ȡ�ļ�����Ϣ
    ExMessage m_msg;


protected:
    //��ť����ɫ�任
    COLORREF cur_c = RGB(161, 217, 252);
    COLORREF normal_c = RGB(161, 217, 252);
    COLORREF hover_c = RGB(98, 140, 224);
    //��ʶ�����������ֵ�ǰ��ѡ�еİ�ť
    char* m_flag;
};

