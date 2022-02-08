#define _CRT_SECURE_NO_WARNINGS 1

#include"experiment_rd.h"

/*1. 用scanf, printf进行如下的输入和输出：
一、输入自己的生日，姓名拼音的首字母，年龄(如：20.8)，然后输出。
 注意使用fflush(stdin)函数清除缓存区域
二、输入自己高考所有课程的成绩(不一定跟真实成绩一模一样),计算平均成绩和标准差，将其输出。
三、输出“学生管理系统”的菜单，如果输入1，则输出“显示所有学员信息”；
如果输入2则输出“查询学员信息”；如果输如3，则。。。。。
用switch()语句完成
2.验证口令程序。小明的登录口令是“xmOK”，请设计口令验证程序，小明输入时，
不显示口令明文，代之以‘#’。输入正确，显示“欢迎！”；输入错误，显示“错误！”。
如果口令是大小写不敏感的，程序又是怎样？
3 输入3门课的成绩，并输出所有成绩中最大的一门课。
用逻辑，关系运算判断：如果所有成绩中至少有一门课大于90，则输出good；
4. 先输入一个学生A的姓名和生日，再输入一个学生B的姓名和生日。
用逻辑，关系运算判断：如果A，B的姓名，生日都是相同的，则输出yes,否则 输出no。
5. 什么是短路规则？编写程序，验证短路规则。
6.自加运算的前缀和后缀有什么区别？编写程序，验证之。
7. 编写程序，求解一元二次方程。*/
void print_1()
{
	char birthday[10] = { 0 };
	char first = 0;
	int age = 0;
	cout << "请输入生日：";
	scanf("%s", birthday);
	//由于vs2022环境下fflush函数无法正常执行其功能故改用以下形式清空缓冲区
	//该种方式也是较为常用的方式之一
	int c = 0;
	while (c = getchar() != '\n' && c != EOF);
	cout << "请输入名字拼音首字母";
	scanf("%c", &first);
	cout << "请输入年龄：" << endl;
	scanf("%d", &age);
	printf("姓名拼音首字母：%c\n", first);
	printf("生日：%s\n", birthday);
	printf("年龄：%d\n", age);
	cout << endl;
}
void print_2()
{
	cout << "请输入要计算的三科成绩：";
	float a, b, c, average;
	cin >> a >> b >> c;
	average = (a + b + c) / 3;
	cout << "三科成绩的平均分：" << average << " " << "标准差：" <<
		sqrt((1.0 / 3) * (pow((a - average), 2) +
		pow((b - average), 2) + pow((c - average), 2)));
}
void menu()
{
	printf("=======学员信息管理系统=======\n\n");
	printf("以下是程序主目录，请选择功能\n\n");
	printf("(1)显示\n(2)查找\n(3)录入\n(4)删除\n(5)修改\n(6)排序\n(0)退出\n\n");
	printf("键入功能前的数字后，按“Enter”键：");
}
void print_3()
{

	int input = 0;
	do
	{
		system("cls");
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("显示所有学员信息\n");
			break;
		case 2:
			printf("查询学员信息\n");
			break;
		case 3:
			printf("录入学员信息\n");
			break;
		case 4:
			printf("删除学员信息\n");
			break;
		case 5:
			printf("修改学员信息\n");
			break;
		case 6:
			printf("排序学员信息\n");
			break;
		case 0:
			printf("退出程序\n");
			return;
		default:
			printf("输入错误，请重新输入：\n");
			break;
		}
		system("pause");
	} while (input);
}

void password()
{
	cout << "请输入四位数密码：";
	//大小写不敏感
	char password[5] = { 0 };
	int i = 0;
	int c = 0;
	while (i < 4)
	{
		password[i++] = _getch();
		putchar('#');
	}
	password[i] = '\0';
	i = 0;
	if (password[i] == 'x' || password[i] == 'X')
		if (password[i + 1] == 'm' || password[i + 1] == 'M')
			if (password[i + 2] == 'o' || password[i + 2] == 'O')
				if (password[i + 3] == 'k' || password[i + 3] == 'K')
				{
					printf("\n欢迎！\n");
					return;
				}
	printf("\n错误！\n");
}

void max_3()
{
	cout << "请输入三门课的成绩：";
	float a, b, c;
	cin >> a >> b >> c;
	cout << "最高分：" << max(max(a, b), c) << endl;
	if (a > 90 || b > 90 || c > 90)
		cout << "good" << endl;
}
typedef struct Stu
{
	char name[10];
	char birthday[10];
}Stu;
void m_compare()
{
	Stu a, b;
	cout << "请输入第一位学生的姓名及生日：" << endl;
	scanf("%s%s", a.name, a.birthday);
	cout << "请输入第二位学生的姓名及生日：" << endl;
	scanf("%s%s", b.name, b.birthday);
	if (!strcmp(a.name, b.name) && !strcmp(a.birthday, b.birthday))
		printf("yes\n");
	else printf("no\n");
}
void rule()
{
	cout << "短路规则即如下:" << endl
		<< "(表达式1） && (表达式2)如果表达式1为假，则表达式2不会进行运算，即表达式2“被短路" << endl
		<<"(表达式1） || (表达式2)如果表达式1为真，则表达式2不会进行运算，即表达式2“被短路"<<endl; 
	cout << "int a = 1, b = 1, c = 0, d = 0" << endl
		<< "验证 && 短路规则(“||”同理）：若表达式1成立则c为1，否则c为0" << endl
		<< "if (a != b && (c += a));" << endl
		<< "printf(\"%d\\n\", c);" << endl
		<< "if (a == b && (c += a));"<< endl
		<< "printf(\"%d\\n\", c);" << endl;
}
void difference()
{
	cout << "前置++即先进行加一运算再使用数值，后置++即先使用数值再进行加一" << endl;
}
void solve_equ()
{
	float a, b, c, x1, x2;
	printf("请输入一元二次方程系数:\n");
	scanf("%f%f%f", &a, &b, &c);
	if (a == 0)
	{
		cout << "第一个系数不能为0！" << endl;
		return;
	}
	float tmp = b * b - 4 * a * c;
	if (tmp < 0)
	{
		printf("该方程无实根\n");
		return;
	}
	x1 = (-b + sqrt(tmp)) / (2 * a);
	x2 = (-b - sqrt(tmp)) / (2 * a);
	printf("x1=%f\nx2=%f\n", x1, x2);
}
