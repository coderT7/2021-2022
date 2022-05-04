#pragma once
#include "Table.h"

using uint32 = unsigned int;

class SalaryTable :
    public Table
{
public:
    SalaryTable(int row = 0, int col = 0);
    ~SalaryTable();
    //获取工资表格中的各项数据
    double getAllSalary();
    double getAllSalary1();
    double getAllSalary2();
    double getAllSalary3();
    double getAllSalary4();
    double getAllSalary5();
    //统计工资相关的信息
    void statisticsSalary();
    //统计人员相关的信息
    void statisticsHumans();
    //获取对应的统计数据
    int getMoreThan3000Humans();
    int getBetween2000To3000Humans();
    int getLessThan2000Humans();

    void show() override;
    void clear() override;

    void drawButton() override;
    void event_loop(const ExMessage& msg) override;

public:
    //当前表格中的总工资的平均值（静态内联便于共享于全部的表格中）
    inline static double allSalary;
    //每一类工资
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

