#pragma once
#include "BasicWidget.h"
#include"config.h"
//文本编辑框类
class EditLine :
    public BasicWidget
{
public:
    EditLine(const std::string& text = "EditLine", int x = 0, int y = 0, int w = 500, int h = 30);

    void show() override;
    //判断鼠标是否进入文本框
    bool is_in();
    //判断鼠标是否点击文本框
    bool is_clicked();
    //获取监听消息
    void event_loop(const ExMessage& msg);
    //设置文本框的文本
    void set_textContent(const std::string& text);
    //获取文本框的文本
    std::string get_text();
    //文本框默认文本是否改变
    bool textChange();
    //由于文本框内的默认内容相对单一，故此不作新的继承类
    bool textOfNameChange();
    bool textOfSearchChange();
    //默认输入框的提示信息，也因为相对单一，不作新的继承类
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

