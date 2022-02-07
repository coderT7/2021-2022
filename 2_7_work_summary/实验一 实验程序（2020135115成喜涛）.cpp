#define _CRT_SECURE_NO_WARNINGS 1

#include"experiment_st_nd.h"


//1.编程且上机运行：求3个整数的和。
void sum_three(int a, int b, int c)
{
	cout << a +b + c << endl;
}
//2.编程且上机运行：求2个数的和、差、积和商。
void four_arithmetic(int a, int b)
{
	cout << a + b << " " << a - b << " " << a * b << " " << a / b << endl;
}
//3.编程且上机运行：求2个数中较大者；求3个数最大值。
void max_num(int a, int b, int c)//在C++中，函数的形参列表中的形参是可以有默认值的
{
	cout << max(max(a, b), c) << endl;
}
//4.编程且上机运行：输入圆的半径，求圆的面积和周长。
void cal_circle(int r)
{
	cout << PI * (int)pow(r, 2) << " " << 2 * PI * r << endl;
}
//5.在屏幕上输出：“hello world!”。
void m_print()
{
	cout << "\"hello world!\"" << endl;
}
//6．以你觉得好看的方式，输出自己的学号、姓名、性别、生日、班级、以及舍友名字。 * /
void m_print(int)//C++支持使用占位参数
{
	cout << "学号：" << endl << "姓名：" << endl << "生日：" <<
		endl << "班级：2021030052" << endl << "舍友名字：***" << endl;
}

