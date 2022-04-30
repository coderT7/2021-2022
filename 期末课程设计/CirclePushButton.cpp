#include "CirclePushButton.h"

CirclePushButton::CirclePushButton(const std::string& text, int x, int y, int r)
	:m_Ctext(text), m_Cx(x), m_Cy(y), m_Cr(r), m_Cflag((char*)"")
{
}

void CirclePushButton::show()
{
	::setfillcolor(cur_c);
	//绘制圆形作为按钮
	::circle(m_Cx, m_Cy, m_Cr);
	settextcolor(BLACK);
	
	int x = m_Cx - textwidth(m_Ctext.c_str())/2;
	int y = m_Cy - textheight(m_Ctext.c_str())/2;
	::outtextxy(x, y, m_Ctext.c_str());
}

bool CirclePushButton::is_in()
{
	if (m_Cmsg.x > (m_Cx - m_Cr) && m_Cmsg.x < (m_Cx + m_Cr) && m_Cmsg.y >(m_Cy - m_Cr) && m_Cmsg.y < (m_Cy + m_Cr)) {
		return true;
		std::cout << "已经进入目标" << std::endl;
	}

	return false;
}

bool CirclePushButton::is_clicked()
{
	if (is_in()) {
		if (m_Cmsg.message == WM_LBUTTONDOWN)
			return true;
	}
	return false;
}

void CirclePushButton::event_loop(const ExMessage& msg)
{
	this->m_Cmsg = msg;
	char tmp[20] = { 0 };
	if (is_in()) {
		m_Cflag = (char*)"○";
	}
	else {
		m_Cflag = (char*)"";
	}
	sprintf_s(tmp, "%s", m_Cflag);
	outtextxy(m_Cx, m_Cy, tmp);
}

void CirclePushButton::move(int x, int y)
{
	m_Cx = x;
	m_Cy = y;
}
