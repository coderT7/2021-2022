#include "Empoyee.h"
#include<sstream>
Empoyee::Empoyee()
{
}

Empoyee::Empoyee(uint32 id, std::string name, uint32 salary1, uint32 salary2, uint32 salary3,
	uint32 salary4, uint32 salary5, uint32 salary6) : id(id), name(name), salary1(salary1), salary2(salary2),
	salary3(salary3), salary4(salary4), salary5(salary5), salary6(salary6) 
{
	this->averageSalary = 1.0 * salary6 / 5;
}

std::string Empoyee::formateInfo()
{
	std::stringstream ss;
	//将数据按以'\t'分割的形式进行格式化处理
	ss << this->id << "\t" <<  this->name << "\t" << this->salary1 << "\t"
		<< this->salary2 << "\t" << this->salary3 << "\t" << this->salary4 << '\t' << this->salary5 <<
		'\t' << this->salary6 << std::endl;
	return ss.str();
}

std::string Empoyee::formateInfoOfAverage()
{
	std::stringstream ss;
	//将数据按以'\t'分割的形式进行格式化处理
	ss << this->id << "\t" << this->name << "\t" << this->salary1 << "\t"
		<< this->salary2 << "\t" << this->salary3 << "\t" << this->salary4 << '\t' << this->salary5 <<
		'\t' << this->salary6 << '\t' << this->averageSalary << std::endl;
	return ss.str();
}

bool Empoyee::operator==(const Empoyee& right) const
{
	return this->id == right.id;
}

bool Empoyee::operator>(const Empoyee& right) const
{
	if (this->id > right.id)
		return true;
	return false;
	/*else if (this->name.compare(right.name) > 0)
		return true;*/
}

bool Empoyee::operator<(const Empoyee& right) const
{
	if (this->id < right.id)
		return true;
	return false;
	/*else if (this->name.compare(right.name) > 0)
		return true;*/
}
