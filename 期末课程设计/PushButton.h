#pragma once
#include "BasicWidget.h"

#include"config.h"

class PushButton :
    public BasicWidget
{
public:
    PushButton(const std::string& text = "PushButton", int x = 0, int y = 0, int w = 100, int h = 30);
    void show()override;
    //判断鼠标是否进入按钮
    virtual bool is_in();
    //判断鼠标是否点击按钮
    virtual bool is_clicked();
    //判断按钮是否被点击过
    bool was_clicked();
    virtual void event_loop(const ExMessage& msg);
    //设置按钮的默认背景颜色以及鼠标进入后的颜色（作被选中的现实特效）
    //后面因为界面设计，感觉透明的更好看，所以这个也没啥用了（已经实现了，就留下来了）
    void setBackgroundColor(COLORREF color);
    void setHoverColor(COLORREF color);//hover（徘徊、漂浮）
public:
    //标志着按钮是否被点击过，防止一些按钮被重复点击产生的逻辑bug（如可能添加按钮被重复点击造成重复添加）
    bool flag;
protected:
    //按钮文本
    std::string m_text;
    //按钮获取的监听消息
    ExMessage m_msg;


protected:
    //按钮的颜色变换
    COLORREF cur_c = RGB(161, 217, 252);
    COLORREF normal_c = RGB(161, 217, 252);
    COLORREF hover_c = RGB(98, 140, 224);
    //标识符，用于区分当前被选中的按钮
    char* m_flag;
};

