#include "Table.h"
#include"SalaryTable.h"
#include<iostream>
Table::Table(int row, int col)
	:BasicWidget(0, 0, 0, 0), m_rows(row), m_cols(col),
	m_curPage(0), m_maxPage(0), m_extraData(0), m_flag(false)
{
	m_preBtn = new PushButton("上一页");
    m_nextBtn = new PushButton("下一页");
    m_firstBtn = new PushButton("首页");
    m_lastBtn = new PushButton("尾页");
}

Table::~Table()
{
	delete m_preBtn;
	delete m_nextBtn;
	delete m_firstBtn;
	delete m_lastBtn;
}

void Table::setRowCount(int row)
{
	m_rows = row;
}

void Table::setColCount(int col)
{
	m_cols = col;
}

void Table::setHeader(const std::string& header)
{
	m_header = header;
	m_cols = (int)std::count(m_header.begin(), m_header.end(), '\t') + 1;
	
	//文字的宽高
	m_textW = ::textwidth("基本工资");
	m_textH = ::textheight(header.c_str());
	//格子的宽高
	m_gridW = m_textW + 10;
	m_gridH = m_textH + 10;
	//表格的宽度
	m_w = m_gridW * m_cols;
	m_h = m_gridH * (m_rows + 1);
}

void Table::insertData(const std::string& data)
{
	m_data.push_back(data);
	updatePage();
}

void Table::show()
{
	drawHeader();
	drawTableGrid();
	drawTableData();
}

void Table::clear()
{
	m_data.clear();
}

void Table::drawTableGrid()
{
	//确定表格的行列数
	//画横线
	for (int i = 0; i < m_rows + 1; i++) {
		line(m_x, m_y + i * m_gridH, m_x + m_cols * m_gridW, m_y + i * m_gridH);
	}
	//画竖线
	for (int i = 0; i < m_cols + 1; i++) {
		line(m_x + i * m_gridW, m_y, m_x + i * m_gridW, m_y + m_rows * m_gridH);
	}
	drawButton();
}

void Table::drawButton()
{
	m_preBtn->move(m_x, m_h + 425);
	m_nextBtn->move(m_preBtn->x() + m_preBtn->width(), m_preBtn->y());
	m_firstBtn->move(m_nextBtn->x() + m_nextBtn->width(), m_nextBtn->y());
	m_lastBtn->move(m_firstBtn->x() + m_firstBtn->width(), m_firstBtn->y());


	m_preBtn->show();
	m_nextBtn->show();
	m_firstBtn->show();
	m_lastBtn->show();

	char str[50] = { 0 };
	//利用sprintf_s函数实现下标能够动态变化
	sprintf_s(str, "第 %d 页/共 %d 页", m_curPage + 1, m_maxPage + 1);
	::outtextxy(m_lastBtn->x() + m_lastBtn->width() + 100, m_lastBtn->y(), str);

	char str_1[50] = { 0 };
	sprintf_s(str_1, "当前人均工资为 %.2lf", 1.0 * SalaryTable::allSalary / m_data.size());
	::outtextxy(m_lastBtn->x() + m_lastBtn->width() + 100, m_lastBtn->y() - 25, str_1);

	
}

void Table::drawTableData()
{
	if (m_data.empty()) {
		return;
	}
	int beginPos = m_curPage * m_rows;
	int endPos = m_curPage * m_rows + m_rows;
	//只有一页数据或者最后一页数据不足一页时，则只需要遍历剩下的数据
	if (m_curPage == m_maxPage) {
		endPos = beginPos + m_extraData;
	}
	//每次输出一页数据时，y都是从0开始，如果与i绑定，i一直++则导致坐标越来越往下走
	for (int i = beginPos, row = 0; i < endPos; i++, row++) {
		//分割字符串输出
		auto line_data = split(m_data[i]);
		for (int k = 0; k < line_data.size(); k++) {
			//进行居中输出（简单的数学计算就不详述了）
			int x = m_x + k * m_gridW + (m_gridW - ::textwidth(line_data[k].c_str())) / 2;
			int y = m_y + row * m_gridH + 5;
			outtextxy(x, y, line_data[k].c_str());
		}
	}

}

void Table::drawHeader()
{
	::setlinestyle(PS_SOLID, 2);
	::rectangle(m_x, m_y - 30, m_x + m_w, m_y);
	for (int i = 0; i < m_cols; i++) {
		line(m_x + i * m_gridW, m_y - 30, m_x + i * m_gridW, m_y);
	}
	::setlinestyle(PS_SOLID, 1);

	//分割表头数据
	auto headers = split(m_header);
	for (int i = 0; i < headers.size(); i++) {
		int spaceH = (m_gridW - ::textwidth(headers[i].c_str())) / 2;
		int spaceW = (30 - ::textheight(headers[i].c_str())) / 2;
		::outtextxy(m_x + i * m_gridW+ spaceH, m_y - m_gridH + spaceW, headers[i].c_str());
	}
}

std::vector<std::string> Table::split(std::string str, char sperator)
{
	std::vector<std::string> res;
	for (size_t pos = 0; pos != std::string::npos; )
	{
		pos = str.find(sperator);
		res.push_back(str.substr(0, pos));
		str = std::string(str.c_str() + pos + 1);
	}
	return res;
}

std::vector<std::string> Table::get_data()
{
	return m_data;
}

void Table::updatePage()
{
	if (m_rows >= (int)m_data.size()) {
		m_maxPage = 0;
		m_extraData = (int)m_data.size();
	}
	else {
		m_maxPage = (int)m_data.size() / m_rows;
		m_extraData = (int)m_data.size() % m_rows;
	}
	
	
}

void Table::event_loop(const ExMessage& msg)
{
	m_preBtn->event_loop(msg);
	m_nextBtn->event_loop(msg);
	m_firstBtn->event_loop(msg);
	m_lastBtn->event_loop(msg);

	if (m_preBtn->is_clicked()) {
		if (m_curPage != 0) {
			m_curPage--;
		}
	}
	if (m_nextBtn->is_clicked()) {
		if (m_curPage != m_maxPage) {
			m_curPage++;
		}
	}
	if (m_firstBtn->is_clicked()) {
		m_curPage = 0;
	}
	if (m_lastBtn->is_clicked()) {
		m_curPage = m_maxPage;
	}
}

bool Table::get_status()
{
	return m_flag;
}

void Table::set_status(bool flag)
{
	m_flag = flag;
}
