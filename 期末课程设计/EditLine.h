#pragma once
#include "BasicWidget.h"
#include"config.h"
class EditLine :
    public BasicWidget
{
public:
    EditLine(const std::string& text = "EditLine", int x = 0, int y = 0, int w = 500, int h = 30);

    void show() override;

    bool is_in();
    bool is_clicked();
    void event_loop(const ExMessage& msg);
    void set_textContent(const std::string& text);
    std::string get_text();
    bool textChange();
    bool textOfNameChange();
    bool textOfSearchChange();
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

