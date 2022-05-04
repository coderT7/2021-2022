#pragma once
#include "Table.h"

using uint32 = unsigned int;

class SalaryTable :
    public Table
{
public:
    SalaryTable(int row = 0, int col = 0);
    ~SalaryTable();
    //��ȡ���ʱ���еĸ�������
    double getAllSalary();
    double getAllSalary1();
    double getAllSalary2();
    double getAllSalary3();
    double getAllSalary4();
    double getAllSalary5();
    //ͳ�ƹ�����ص���Ϣ
    void statisticsSalary();
    //ͳ����Ա��ص���Ϣ
    void statisticsHumans();
    //��ȡ��Ӧ��ͳ������
    int getMoreThan3000Humans();
    int getBetween2000To3000Humans();
    int getLessThan2000Humans();

    void show() override;
    void clear() override;

    void drawButton() override;
    void event_loop(const ExMessage& msg) override;

public:
    //��ǰ����е��ܹ��ʵ�ƽ��ֵ����̬�������ڹ�����ȫ���ı���У�
    inline static double allSalary;
    //ÿһ�๤��
    double allSalary1;
    double allSalary2;
    double allSalary3;
    double allSalary4;
    double allSalary5;
public:
    //������ص���������
    uint32 moreThan3000Humans;
    uint32 between2000To3000Humans;
    uint32 lessThan2000Humans;

};

