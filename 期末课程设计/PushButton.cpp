#include "PushButton.h"

PushButton::PushButton(const std::string& text, int x, int y, int w, int h)
	:BasicWidget(x, y, w, h), m_text(text)
{

}

void PushButton::show()
{
	::setfillcolor(cur_c);
	//绘制圆角矩形作为按钮
	::fillroundrect(m_x, m_y, m_x + m_w, m_y + m_h, 20, 20);
	settextcolor(BLACK);
	int x = m_x + (m_w - textwidth(m_text.c_str())) / 2;
	int y = m_y + (m_h - textheight(m_text.c_str())) / 2;
	::outtextxy(x, y, m_text.c_str());
}
//监听鼠标消息
bool PushButton::is_in()
{
	if (m_msg.x >= m_x && m_msg.x <= m_x + m_w && m_msg.y >= m_y && m_msg.y <= m_y + m_h)
		return true;
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

void PushButton::event_loop(const ExMessage& msg)
{
	this->m_msg = msg;
	if (!is_in()) {
		cur_c = normal_c;
	}
	else
		cur_c = hover_c;
}

void PushButton::setBackgroundColor(COLORREF color)
{
	normal_c = color;
}

void PushButton::setHoverColor(COLORREF color)
{
	hover_c = color;
}
