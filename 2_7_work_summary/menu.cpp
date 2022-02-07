#define _CRT_SECURE_NO_WARNINGS 1

#include"menu.h"
#include"All.h"
void all_menu::show_menu()
{
	cout << "请输入下列相应选项：" << endl;
	cout << "1、实验一相关程序测试" << endl;
	cout << "2、实验二相关程序测试" << endl;
	cout << "3、实验三相关程序测试" << endl;
	cout << "4、实验四相关程序测试" << endl;
	cout << "5、实验五相关程序测试" << endl;
	cout << "6、实验六相关程序测试" << endl;
	cout << "0、退出程序" << endl;
}
static void do_wrok(menu*& m)
{
	int n = 0;
	m->show_menu();
	cin >> n;
	m->get_enter(n);
	delete m;
}
void all_menu::get_enter(int enter)
{
	int n = 0;
	switch (enter)
	{
	case 0:
		break;
	case 1:
	{
		menu* m = new menu1;
		do_wrok(m);
		break;
	}
	//case 2:
	//{
	//	menu* m = new menu2;
	//	do_wrok(m);
	//	break;
	//}
	//case 3:
	//{
	//	menu* m = new menu3;
	//	do_wrok(m);
	//	break;
	//}
	//case 4:
	//{
	//	menu* m = new menu4;
	//	do_wrok(m);
	//	break;
	//}
	//case 5:
	//{
	//	menu* m = new menu5;
	//	do_wrok(m);
	//	break;
	//}
	//case 6:
	//{
	//	menu* m = new menu6;
	//	do_wrok(m);
	//	break;
	//}
	default:
		break;
	}
}

void menu1::show_menu()
{
	cout << "请选择你要测试的题目：" << endl;
	cout << "1.求3个整数的和" << endl;
	cout << "2.求2个数的和、差、积和商" << endl;
	cout << "3.求2个数中较大者；求3个数最大值" << endl;
	cout << "4.输入圆的半径，求圆的面积和周长" << endl;
	cout << "5.在屏幕上输出：“hello world!”" << endl;
	cout << "6.以你觉得好看的方式，输出自己的学号、姓名、性别、生日、班级、以及舍友名字。" << endl;
	cout << "0.返回上一层" << endl;
}
void menu1::get_enter(int enter)
{
	int a, b, c;
	int tmp = enter;
	while (tmp)
	{
		switch (tmp)
		{
		case 0:
			break;
		case 1:
			cout << "请输入要进行求和的三个整数:";
			cin >> a >> b >> c;
			sum_three(a, b, c);
			break;
		case 2:
			cout << "请输入要进行四则运算的两个数：";
			cin >> a >> b;
			four_arithmetic(a, b);
			break;
		case 3:
			cout << "请输入要进行比较的三位数：";
			cin >> a >> b >> c;
			max_num(a, b, c);
			break;
		case 4:
			cout << "请输入圆的周长：";
			cin >> a;
			cal_circle(a);
			break;
		case 5:
			m_print();
			break;
		case 6:
			m_print(2);
			break;
		default:
			cout << "输入有误，请重新选择：";
			break;
		}
		system("pause");
		system("cls");
		menu1().show_menu();
		cin >> tmp;
	}
}
void menu2::show_menu()
{
	cout << "1.实现信息格式化输出" << endl;
	cout << "2.小写字母转大写" << endl;
	cout << "3.输入两个不同类型数据后，经过适当的运算（加、减、乘、除）后输出" << endl;
	cout << "4.实现计算三角形面积、立方体的体积和表面积" << endl;
	cout << "5.验证int、char、float、double、long int、short int等数据类型的长度" << endl;
	cout << "0.返回上一层";
}
//void menu3::show_menu()
//{
//	cout << "1、输入自己的生日，姓名拼音的首字母，年龄，然后输出" << endl;
//	cout << "2、输入自己高考所有课程的成绩, 计算平均成绩和标准差，将其输出" << endl;
//	cout << "3、输出“学生管理系统”的菜单" << endl;
//	cout << "4、请设计口令验证程序，输入时，不显示口令明文，代之以‘#’"<< endl;
//	cout << "5、输入3门课的成绩，并输出所有成绩中最大的一门课" << endl;
//	cout << "6、先输入两个学生的姓名和生日，如果二者的姓名，生日都是相同的，则输出yes,否则输出no" << endl;
//	cout << "7、什么是短路规则？编写程序，验证短路规则" << endl;
//	cout << "8、自加运算的前缀和后缀有什么区别？编写程序，验证之" << endl;
//	cout << "7. 编写程序，求解一元二次方程" << endl;
//	cout << "0.返回上一层";
//}
//void menu4::show_menu()
//{
//	cout << "1.一个整数，它加上100后是一个完全平方数，再加上168又是一个完全平方数，请问该数是多少" << endl;
//	cout << "2.为使电文保密，往往按一定规律将其转换成密码，收报人再按约定的规律将其译回原文" << endl;
//	cout << "3.判断101 - 200之间有多少个素数，并输出所有素数" << endl;
//	cout << "4.打印菱形" << endl;
//	cout << "5.求1 + 2!+ 3!+ ... + 20!的和。要求：阶乘用函数实现" << endl;
//	cout << "6.设计一个程序，模拟抛硬币的测试" << endl;
//	cout << "0.返回上一层" << endl;
//}
//void menu5::show_menu()
//{
//	cout << "1.编写程序，设计函数，实现把两个输入的字符串交叉合并，合并时，把小写字母改成大写。" << endl;
//	cout << "2.输入一个由单词组成的字符串，对字符串进行相应处理"<< endl;
//	cout << "3.身份证号码处理" << endl;
//	cout << "4.设计方案，验证C语言中，函数参数传递时，参数入栈的顺序。（清晰的文字描述和例子）" << endl;
//	cout << "5.设计方案，验证C语言中，“指针变量的存储空间与类型无关，指针的运算看类型”的结论。" << endl;
//	cout << "0.返回上一层";
//}
//void menu6::show_menu()
//{
//	cout << "1.把一个正整数的各位数求和" << endl;
//	cout << "2.把一个正整数倒置" << endl;
//	cout << "3.先设计最大公约数函数，利用该函数，设计求最大公倍数的函数" << endl;
//	cout << "4.把一个正整数化为二进制" << endl;
//	cout << "5.使用提供0 - 9数字点阵字模，编写显示字模函数" << endl;
//	cout << "6.编写程序，设计函数，实现把两个输入的字符串交叉合并，合并时，把小写字母改成大写。" << endl;
//	cout << "7.将文本文件按照一定的算法进行加密" << endl;
//	cout << "8.计算计算机专业的学生大学毕业后的发量" << endl;
//	cout << "0.返回上一层";
//}



