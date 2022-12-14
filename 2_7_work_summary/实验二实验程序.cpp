#define _CRT_SECURE_NO_WARNINGS 1

#include"experiment_st_nd.h"
///*
//一、编写程序，格式化输出
//二、编写程序，实现小写字母转大写。
//三、编写程序，实现输入两个不同类型数据后，经过适当的运算（加、减、乘、除）后输出。
//四、编写程序，计算三角形面积、立方体的体积和表面积。
//五、编写程序，验证int、char、float、double、long int、short int等数据类型的长度。
//六、编写程序，验证取模运算中，出现负数时的运算规律。*/
//
void print()
{
	printf("%-8s%-8s%-8s%-8s%-8s%-8s\n", "学号", "姓名", "语文", "数学", "英语", "平均分");
	printf("%-8s%-8s%-8s%-8s%-8s%-8s\n", "====", "====", "====", "====", "====", "====");
	printf("%-8s%-8s%-8s%-8s%-8s%-8s\n", "1", "34", "56.0", "778.0", "23.0", "285.7");
}
void m_toupper()
{
	cout << "请输入要进行转换的字母：";
	getchar();
	int ch = getchar();
	if (islower(ch))
		ch = toupper(ch);
	putchar(ch);
	cout << endl;
}
void four_arithmetic(float a, float b)
{
	if (b)
	{
		cout << "相加：" << a + b << " " << "相减：" << a - b << " "
			<< "相乘：" << a * b << " " << "相除：" << a*1.0 / b << endl;
		cout << "ps：相除结果为浮点除的结果" << endl;
	}
	else
	{
		cout << "除数不能为0！" << endl;
		return;
	}
}
void geometry_cal(float a, float b, float c, int flag)//默认参数只能出现一次
{
	if (flag && (a + b) > c && (a + c) > b && (b + c) > a)
	{
		float p = (a + b + c) / 2;
		cout << "三角形的面积为：" << sqrt(p * (p - a) * (p - b) * (p - c)) << endl;
		return;
	}
	else if(flag == 1)
	{
		cout << "三角形任意两边之和要大于第三边哦~" << endl;
		return;
	}
	else 
		cout << "立方体的体积为：" << pow(a, 3) << endl << "立方体的表面积为：" << a * a * 6 << endl;
	return;
}
void data_size()
{
	cout << "整型：" << sizeof(int) << " " << "字符型型：" << sizeof(char) << " "
	<< "浮点型：" << sizeof(float) << " " << "双精度浮点型：" << sizeof(double) << " "
	<< "长整型：" << sizeof(long) << " " << "短整型：" << sizeof(short) << endl;
	cout << "单位：字节" << endl;
}
void mod()
{
	cout << -2 % 1 << " " << 11 % -5 << " " << - 11 % 5 << " " << -2 % -1 << -11 % -5 << endl;
	cout << "源码：" << endl
		<< "cout << -2 % 1 << " " << 11 % -5 << " " << - 11 % 5 << " " << -2 % -1 << -11 % -5 << endl;" 
		<< endl;
	cout << "由输出结果0 1 - 1 0 - 1可知，负数进行取模时，若除数与被除数能整除则一样为0，否则结果仍旧是余数" << endl;
	cout << "即取模运算的结果的符号与第一个操作数的符号相同(或为0)" << endl;
}
