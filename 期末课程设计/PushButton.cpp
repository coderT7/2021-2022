#include "PushButton.h"

PushButton::PushButton(const std::string& text, int x, int y, int w, int h)
	:BasicWidget(x, y, w, h), m_text(text), m_flag((char*)""), flag(false)
{

}

void PushButton::show()
{
	::setfillcolor(cur_c);
#if 0
	//发现按钮的另一种展现方式更为好看，故此废弃初版设计
	//绘制圆角矩形作为按钮
	//::fillroundrect(m_x, m_y, m_x + m_w, m_y + m_h, 20, 20);
#endif
	::roundrect(m_x, m_y, m_x + m_w, m_y + m_h, 20, 20);
	settextcolor(BLACK);
	int x = m_x + (m_w - textwidth(m_text.c_str())) / 2;
	int y = m_y + (m_h - textheight(m_text.c_str())) / 2;
	::outtextxy(x, y, m_text.c_str());
}
//监听鼠标消息
bool PushButton::is_in()
{
	if (m_msg.x > m_x && m_msg.x < m_x + m_w && m_msg.y > m_y && m_msg.y < m_y + m_h) {
		return true;
	}
		
	return false;
}

bool PushButton::is_clicked()
{
	if (is_in()) {
		if (m_msg.message == WM_LBUTTONDOWN)
			return true;
	}
	return false;
}

bool PushButton::was_clicked()
{
	return flag;
}

void PushButton::event_loop(const ExMessage& msg)
{
	this->m_msg = msg;
	char tmp[20] = { 0 };
	if (is_in()) {
		cur_c = normal_c;
		m_flag = (char*)"○";
	}
	else {
		cur_c = hover_c;
		m_flag = (char*)"";
	}
	sprintf_s(tmp, "%s", m_flag);
	//(((this->x() - textwidth(m_text.c_str())) / 2) - 20, ((this->y() - textheight(m_text.c_str())) / 2), m_flag);
	outtextxy(((this->width() - textwidth(m_text.c_str())) / 2) + this->x() - 35,
		((this->height() - textheight(m_text.c_str())) / 2) + this->y() - 3, m_flag);
}

void PushButton::setBackgroundColor(COLORREF color)
{
	normal_c = color;
}

void PushButton::setHoverColor(COLORREF color)
{
	hover_c = color;
}
