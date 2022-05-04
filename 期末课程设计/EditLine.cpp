#include "EditLine.h"
#include<sstream>


EditLine::EditLine(const std::string& text, int x, int y, int w, int h)
	:m_text(text), BasicWidget(x, y, w, h), flag(false) { }

void EditLine::show()
{
	::setfillcolor(RGB(217, 242, 244));
	::fillroundrect(m_x, m_y, m_x + m_w, m_y + m_h, 5, 5);
	settextcolor(RGB(10, 14, 24));
	m_textX = m_x + (m_w - textwidth(m_text.c_str())) / 2;
	m_textY = m_y + (m_h - textheight(m_text.c_str())) / 2;
	::outtextxy(m_textX, m_textY, m_text.c_str());
}

bool EditLine::is_in()
{
	if (m_msg.x >= m_x && m_msg.x <= m_x + m_w && m_msg.y >= m_y && m_msg.y <= m_y + m_h)
		return true;
	
	return false;
}

bool EditLine::is_clicked()
{
	if (is_in()) {
		if (m_msg.message == WM_LBUTTONDOWN)
			return true;
	}
	return false;
}

void EditLine::event_loop(const ExMessage& msg)
{
	this->m_msg = msg;
}

void EditLine::set_textContent(const std::string& text)
{
	m_text = text;
	::setfillcolor(RGB(217, 242, 244));
	show();
}

std::string EditLine::get_text()
{
	return m_text;
}

bool EditLine::textChange()
{
	if (m_text.compare("���������ְ��id��������"))
		return true;
	return false;
}

bool EditLine::textOfNameChange()
{
	if (m_text.compare("���������ְ��������������"))
		return true;
	return false;
}

bool EditLine::textOfSearchChange()
{
	if (m_text.compare("���������ְ��id����������������"))
		return true;
	return false;
}

std::string EditLine::getDelIDInput()
{
	char buf[1024] = { 0 };
	std::stringstream ss(buf);

	InputBox(buf, 20, "������Ҫɾ����ID");
	ss << buf;
	
	return ss.str();
}

std::string EditLine::getDelNameInput()
{
	char buf[1024] = { 0 };
	std::stringstream ss(buf);

	InputBox(buf, 20, "������Ҫɾ��������");
	ss << buf;

	return ss.str();
}

std::string EditLine::getSearchTextInput()
{
	char buf[1024] = { 0 };
	std::stringstream ss(buf);

	InputBox(buf, 20, "������Ҫ������ID/����");
	ss << buf;

	return ss.str();
}

std::string EditLine::getChooseModifyTextInput()
{
	char buf[1024] = { 0 };
	std::stringstream ss(buf);

	InputBox(buf, 20, "������Ҫѡ���޸���Ϣ��id��");
	ss << buf;

	return ss.str();
}

std::string EditLine::getModifyTextInput()
{
	char buf[1024] = { 0 };
	std::stringstream ss(buf);

	InputBox(buf, 20, "������Ҫ�޸ĵ���Ϣ");
	ss << buf;

	return ss.str();
}