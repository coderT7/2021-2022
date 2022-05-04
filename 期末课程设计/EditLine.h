#pragma once
#include "BasicWidget.h"
#include"config.h"
//�ı��༭����
class EditLine :
    public BasicWidget
{
public:
    EditLine(const std::string& text = "EditLine", int x = 0, int y = 0, int w = 500, int h = 30);

    void show() override;
    //�ж�����Ƿ�����ı���
    bool is_in();
    //�ж�����Ƿ����ı���
    bool is_clicked();
    //��ȡ������Ϣ
    void event_loop(const ExMessage& msg);
    //�����ı�����ı�
    void set_textContent(const std::string& text);
    //��ȡ�ı�����ı�
    std::string get_text();
    //�ı���Ĭ���ı��Ƿ�ı�
    bool textChange();
    //�����ı����ڵ�Ĭ��������Ե�һ���ʴ˲����µļ̳���
    bool textOfNameChange();
    bool textOfSearchChange();
    //Ĭ����������ʾ��Ϣ��Ҳ��Ϊ��Ե�һ�������µļ̳���
    std::string getDelIDInput();
    std::string getDelNameInput();
    std::string getSearchTextInput();
    std::string getChooseModifyTextInput();
    std::string getModifyTextInput();


private:
    ExMessage m_msg;
    std::string m_text;
private:
    int m_textX;
    int m_textY;
public:
    bool flag;
};

