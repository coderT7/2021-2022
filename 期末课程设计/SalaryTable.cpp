#include "SalaryTable.h"
#include<iostream>

#include<string>
SalaryTable::SalaryTable(int row, int col)
	:Table(row, col), 
	allSalary1(0.0), allSalary2(0.0), allSalary3(0.0), allSalary4(0.0), allSalary5(0.0)
{

}

SalaryTable::~SalaryTable()
{
}

double SalaryTable::getAllSalary()
{
	return allSalary;
}

double SalaryTable::getAllSalary1()
{
	return allSalary1;
}

double SalaryTable::getAllSalary2()
{
	return allSalary2;
}

double SalaryTable::getAllSalary3()
{
	return allSalary3;
}

double SalaryTable::getAllSalary4()
{
	return allSalary4;
}

double SalaryTable::getAllSalary5()
{
	return allSalary5;
}

int SalaryTable::getMoreThan3000Humans()
{
	return moreThan3000Humans;
}

int SalaryTable::getBetween2000To3000Humans()
{
	return between2000To3000Humans;
}

int SalaryTable::getLessThan2000Humans()
{
	return lessThan2000Humans;
}


void SalaryTable::show()
{
	Table::drawTableData();
	Table::drawHeader();
	Table::drawTableGrid();
}

void SalaryTable::clear()
{
	m_data.clear();
	this->allSalary = 0;
	this->allSalary1 = 0;
	this->allSalary2 = 0;
	this->allSalary5 = 0;
	this->allSalary4 = 0;
	this->allSalary5 = 0;
	this->moreThan3000Humans = 0;
	this->lessThan2000Humans = 0;
	this->between2000To3000Humans = 0;
}

void SalaryTable::statisticsSalary()
{
	char str[50] = { 0 };
	//利用sprintf_s函数实现下标能够动态变化
	sprintf_s(str, "第 %d 页/共 %d 页", m_curPage + 1, m_maxPage + 1);
	::outtextxy(m_lastBtn->x() + m_lastBtn->width() + 100, m_lastBtn->y(), str);

	char str_1[50] = { 0 };
	sprintf_s(str_1, "当前人均工资为 %.2lf", 1.0 * allSalary / m_data.size());
	::outtextxy(m_lastBtn->x() + m_lastBtn->width() + 100, m_lastBtn->y() - 25, str_1);

	char str_2[50] = { 0 };
	sprintf_s(str_2, "各类项工资平均值");
	::outtextxy(m_preBtn->x(), m_preBtn->y() - 190, str_2);

	char str_3[50] = { 0 };
	sprintf_s(str_3, "基本工资均值：%lf", 1.0 * allSalary1 / m_data.size());
	::outtextxy(m_preBtn->x(), m_preBtn->y() - 190 + textheight(str_2) + 5, str_3);

	char str_4[40] = { 0 };
	sprintf_s(str_4, "职务工资均值：%lf", 1.0 * allSalary2 / m_data.size());
	::outtextxy(m_preBtn->x(), m_preBtn->y() - 190 + 2 * textheight(str_3) + 10, str_4);

	char str_5[50] = { 0 };
	sprintf_s(str_5, "津贴均值：%lf", 1.0 * allSalary3 / m_data.size());
	::outtextxy(m_preBtn->x(), m_preBtn->y() - 190 + 3 * textheight(str_4) + 15, str_5);

	char str_6[60] = { 0 };
	sprintf_s(str_6, "医疗保险均值：%lf", 1.0 * allSalary4 / m_data.size());
	::outtextxy(m_preBtn->x(), m_preBtn->y() - 190 + 4 * textheight(str_5) + 20, str_6);

	char str_7[70] = { 0 };
	sprintf_s(str_7, "公积金均值：%lf", 1.0 * allSalary5 / m_data.size());
	::outtextxy(m_preBtn->x(), m_preBtn->y() - 190 + 5 * textheight(str_6) + 25, str_7);
}
void SalaryTable::statisticsHumans()
{
	char str_1[50] = { 0 };
	sprintf_s(str_1, "工资在3000元以上占比 %.3lf%%，共 %s 人", (1.0 * moreThan3000Humans / m_data.size()) * 100, 
		std::to_string(moreThan3000Humans).c_str());
	::outtextxy(m_preBtn->x() + m_gridW * m_cols / 2, m_preBtn->y() - 190, str_1);

	char str_2[50] = { 0 };
	sprintf_s(str_2, "工资在3000元以下2000元以上占比 %.3lf%%，共 %s 人", 
		(1.0 * between2000To3000Humans / m_data.size()) * 100, std::to_string(between2000To3000Humans).c_str());
	//std::cout << between2000To3000Humans << std::endl;
	::outtextxy(m_preBtn->x() + m_gridW * m_cols / 2, m_preBtn->y() - 190 + textheight(str_1) + 10, str_2);

	char str_3[50] = { 0 };
	sprintf_s(str_3, "工资在2000元以下占比 %.3lf%%，共 %s 人", (1.0 * lessThan2000Humans / m_data.size()) * 100, 
		std::to_string(lessThan2000Humans).c_str());
	::outtextxy(m_preBtn->x() + m_gridW * m_cols / 2, m_preBtn->y() - 190 + 2 * textheight(str_1) + 20, str_3);
}

void SalaryTable::drawButton()
{
	m_preBtn->move(m_x, m_h + 350);
	m_nextBtn->move(m_preBtn->x() + m_preBtn->width(), m_preBtn->y());
	m_firstBtn->move(m_nextBtn->x() + m_nextBtn->width(), m_nextBtn->y());
	m_lastBtn->move(m_firstBtn->x() + m_firstBtn->width(), m_firstBtn->y());


	m_preBtn->show();
	m_nextBtn->show();
	m_firstBtn->show();
	m_lastBtn->show();
	statisticsSalary();
	statisticsHumans();
}

void SalaryTable::event_loop(const ExMessage& msg)
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