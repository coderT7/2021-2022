#pragma once
#include "PushButton.h"
#include<vector>
#include<iostream>
class CirclePushButton :
    public PushButton
{
public:
    CirclePushButton(const std::string & text, int x, int y, int r);

    void show()override;
    bool is_in()override;
    bool is_clicked() override;
    void event_loop(const ExMessage& msg) override;
    void move(int x, int y) override;

private:
    std::string m_Ctext;
    ExMessage m_Cmsg;
private:
    int m_Cx;
    int m_Cy;
    int m_Cr;
private:
    char* m_Cflag;
};

