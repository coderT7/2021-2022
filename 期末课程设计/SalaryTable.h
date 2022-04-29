#pragma once
#include "Table.h"

using uint32 = unsigned int;

class SalaryTable :
    public Table
{
public:
    SalaryTable(int row = 0, int col = 0);
    ~SalaryTable();
    double getAllSalary();
    double getAllSalary1();
    double getAllSalary2();
    double getAllSalary3();
    double getAllSalary4();
    double getAllSalary5();

    void statisticsSalary();
    void statisticsHumans();
    int getMoreThan3000Humans();
    int getBetween2000To3000Humans();
    int getLessThan2000Humans();

    void show() override;
    void clear() override;

    void drawButton() override;
    void event_loop(const ExMessage& msg) override;

public:
    //当前表格中的总工资的平均值
    inline static double allSalary;
    double allSalary1;
    double allSalary2;
    double allSalary3;
    double allSalary4;
    double allSalary5;
public:
    //工资相关的人数数据
    uint32 moreThan3000Humans;
    uint32 between2000To3000Humans;
    uint32 lessThan2000Humans;

};

