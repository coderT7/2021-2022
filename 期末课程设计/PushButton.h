#pragma once
#include "BasicWidget.h"

#include"config.h"

class PushButton :
    public BasicWidget
{
public:
    PushButton(const std::string& text = "PushButton", int x = 0, int y = 0, int w = 100, int h = 30);
    void show()override;

    virtual bool is_in();
    virtual bool is_clicked();
    bool was_clicked();
    virtual void event_loop(const ExMessage& msg);

    void setBackgroundColor(COLORREF color);
    void setHoverColor(COLORREF color);
    bool flag;
protected:
    std::string m_text;
    ExMessage m_msg;


protected:
    //按钮的颜色变换
    COLORREF cur_c = RGB(161, 217, 252);
    COLORREF normal_c = RGB(161, 217, 252);
    COLORREF hover_c = RGB(98, 140, 224);
    //标识符
    char* m_flag;
};

