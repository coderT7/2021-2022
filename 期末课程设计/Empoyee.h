#pragma once

#include"config.h"
using uint32 = unsigned int;
class Empoyee
{
public:
	Empoyee();
	Empoyee(uint32 id, std::string name, uint32 salary1 , uint32 salary2, uint32 salary3, 
		uint32 salary4, uint32 salary5, uint32 salary6);
	//格式化数据
	std::string formateInfo();
	//ID号 姓名 基本工资 职务工资 津贴 医疗保险 公积金 总工资 平均工资
	std::string formateInfoOfAverage();
public:
	uint32 id;
	std::string name;
	uint32 salary1;
	uint32 salary2;
	uint32 salary3;
	uint32 salary4;
	uint32 salary5;
	uint32 salary6;
	double averageSalary;
public:
	bool operator==(const Empoyee& right) const;
	bool operator>(const Empoyee& right) const;
	bool operator<(const Empoyee& right) const;
};

