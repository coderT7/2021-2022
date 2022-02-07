#pragma once
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cctype>
#include<cmath>
#include<conio.h>
#include<cstring>
#include<stack>
#include<Windows.h>
#include<cstdlib>
#include<ctime>

using namespace std;

#define PI 3.14
/*实验一*/
//1.编程且上机运行：求3个整数的和。
void sum_three(int a, int b, int c);
//2.编程且上机运行：求2个数的和、差、积和商。
void four_arithmetic(int a, int b);
//3.编程且上机运行：求2个数中较大者；求3个数最大值。
void max_num(int a, int b, int c = 0);//在C++中，函数的形参列表中的形参是可以有默认值的
//4.编程且上机运行：输入圆的半径，求圆的面积和周长。
void cal_circle(int r);
//5.在屏幕上输出：“hello world!”。
void m_print();
//6．以你觉得好看的方式，输出自己的学号、姓名、性别、生日、班级、以及舍友名字。 * /
void m_print(int);//C++支持使用占位参数
/*实验二*/
//一、编写程序，格式化输出
void print();
//二、编写程序，实现小写字母转大写。
void m_toupper(char c);
//三、编写程序，实现输入两个不同类型数据后，经过适当的运算（加、减、乘、除）后输出。
// float four_arithmetic(int a, int b);
//四、编写程序，计算三角形面积、立方体的体积和表面积。
float geometry_cal(int a, int b = 0, int c = 0);
//验证类型的题目提供结论及验证思路即可
//五、编写程序，验证int、char、float、double、long int、short int等数据类型的长度。
//六、编写程序，验证取模运算中，出现负数时的运算规律。

