#define _CRT_SECURE_NO_WARNINGS 1

#include"experiment_rd.h"

/*1. ��scanf, printf�������µ�����������
һ�������Լ������գ�����ƴ��������ĸ������(�磺20.8)��Ȼ�������
 ע��ʹ��fflush(stdin)���������������
���������Լ��߿����пγ̵ĳɼ�(��һ������ʵ�ɼ�һģһ��),����ƽ���ɼ��ͱ�׼����������
���������ѧ������ϵͳ���Ĳ˵����������1�����������ʾ����ѧԱ��Ϣ����
�������2���������ѯѧԱ��Ϣ�����������3���򡣡�������
��switch()������
2.��֤�������С���ĵ�¼�����ǡ�xmOK��������ƿ�����֤����С������ʱ��
����ʾ�������ģ���֮�ԡ�#����������ȷ����ʾ����ӭ���������������ʾ�����󣡡���
��������Ǵ�Сд�����еģ���������������
3 ����3�ſεĳɼ�����������гɼ�������һ�ſΡ�
���߼�����ϵ�����жϣ�������гɼ���������һ�ſδ���90�������good��
4. ������һ��ѧ��A�����������գ�������һ��ѧ��B�����������ա�
���߼�����ϵ�����жϣ����A��B�����������ն�����ͬ�ģ������yes,���� ���no��
5. ʲô�Ƕ�·���򣿱�д������֤��·����
6.�Լ������ǰ׺�ͺ�׺��ʲô���𣿱�д������֤֮��
7. ��д�������һԪ���η��̡�*/
void print_1()
{
	char birthday[10] = { 0 };
	char first = 0;
	int age = 0;
	cout << "���������գ�";
	scanf("%s", birthday);
	//����vs2022������fflush�����޷�����ִ���书�ܹʸ���������ʽ��ջ�����
	//���ַ�ʽҲ�ǽ�Ϊ���õķ�ʽ֮һ
	int c = 0;
	while (c = getchar() != '\n' && c != EOF);
	cout << "����������ƴ������ĸ";
	scanf("%c", &first);
	cout << "���������䣺" << endl;
	scanf("%d", &age);
	printf("����ƴ������ĸ��%c\n", first);
	printf("���գ�%s\n", birthday);
	printf("���䣺%d\n", age);
	cout << endl;
}
void print_2()
{
	cout << "������Ҫ��������Ƴɼ���";
	float a, b, c, average;
	cin >> a >> b >> c;
	average = (a + b + c) / 3;
	cout << "���Ƴɼ���ƽ���֣�" << average << " " << "��׼�" <<
		sqrt((1.0 / 3) * (pow((a - average), 2) +
		pow((b - average), 2) + pow((c - average), 2)));
}
void menu()
{
	printf("=======ѧԱ��Ϣ����ϵͳ=======\n\n");
	printf("�����ǳ�����Ŀ¼����ѡ����\n\n");
	printf("(1)��ʾ\n(2)����\n(3)¼��\n(4)ɾ��\n(5)�޸�\n(6)����\n(0)�˳�\n\n");
	printf("���빦��ǰ�����ֺ󣬰���Enter������");
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
			printf("��ʾ����ѧԱ��Ϣ\n");
			break;
		case 2:
			printf("��ѯѧԱ��Ϣ\n");
			break;
		case 3:
			printf("¼��ѧԱ��Ϣ\n");
			break;
		case 4:
			printf("ɾ��ѧԱ��Ϣ\n");
			break;
		case 5:
			printf("�޸�ѧԱ��Ϣ\n");
			break;
		case 6:
			printf("����ѧԱ��Ϣ\n");
			break;
		case 0:
			printf("�˳�����\n");
			return;
		default:
			printf("����������������룺\n");
			break;
		}
		system("pause");
	} while (input);
}

void password()
{
	cout << "��������λ�����룺";
	//��Сд������
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
					printf("\n��ӭ��\n");
					return;
				}
	printf("\n����\n");
}

void max_3()
{
	cout << "���������ſεĳɼ���";
	float a, b, c;
	cin >> a >> b >> c;
	cout << "��߷֣�" << max(max(a, b), c) << endl;
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
	cout << "�������һλѧ�������������գ�" << endl;
	scanf("%s%s", a.name, a.birthday);
	cout << "������ڶ�λѧ�������������գ�" << endl;
	scanf("%s%s", b.name, b.birthday);
	if (!strcmp(a.name, b.name) && !strcmp(a.birthday, b.birthday))
		printf("yes\n");
	else printf("no\n");
}
void rule()
{
	cout << "��·��������:" << endl
		<< "(���ʽ1�� && (���ʽ2)������ʽ1Ϊ�٣�����ʽ2����������㣬�����ʽ2������·" << endl
		<<"(���ʽ1�� || (���ʽ2)������ʽ1Ϊ�棬����ʽ2����������㣬�����ʽ2������·"<<endl; 
	cout << "int a = 1, b = 1, c = 0, d = 0" << endl
		<< "��֤ && ��·����(��||��ͬ���������ʽ1������cΪ1������cΪ0" << endl
		<< "if (a != b && (c += a));" << endl
		<< "printf(\"%d\\n\", c);" << endl
		<< "if (a == b && (c += a));"<< endl
		<< "printf(\"%d\\n\", c);" << endl;
}
void difference()
{
	cout << "ǰ��++���Ƚ��м�һ������ʹ����ֵ������++����ʹ����ֵ�ٽ��м�һ" << endl;
}
void solve_equ()
{
	float a, b, c, x1, x2;
	printf("������һԪ���η���ϵ��:\n");
	scanf("%f%f%f", &a, &b, &c);
	if (a == 0)
	{
		cout << "��һ��ϵ������Ϊ0��" << endl;
		return;
	}
	float tmp = b * b - 4 * a * c;
	if (tmp < 0)
	{
		printf("�÷�����ʵ��\n");
		return;
	}
	x1 = (-b + sqrt(tmp)) / (2 * a);
	x2 = (-b - sqrt(tmp)) / (2 * a);
	printf("x1=%f\nx2=%f\n", x1, x2);
}
