#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctype.h>
#include<cmath>
#include<conio.h>
#include<algorithm>
using namespace std;

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
//void menu()
//{
//	printf("=======ѧԱ��Ϣ����ϵͳ=======\n\n");
//	printf("�����ǳ�����Ŀ¼����ѡ����\n\n");
//	printf("(1)��ʾ\n(2)����\n(3)¼��\n(4)ɾ��\n(5)�޸�\n(6)����\n(0)�˳�\n\n");
//	printf("���빦��ǰ�����ֺ󣬰���Enter������");
//}

//typedef struct Stu
//{
//	char name[10];
//	char birthday[10];
//}Stu;
int main()
{
	//char birthday[10] = { 0 };
	//char first = 0;
	//int age = 0;
	//scanf("%s", birthday);
	////����vs2022������fflush�����޷�����ִ���书�ܹʸ���������ʽ��ջ�����
	////���ַ�ʽҲ�ǽ�Ϊ���õķ�ʽ֮һ
	//int c;
	//while (c = getchar() != '\n' && c != EOF);
	//scanf("%c", &first);
	//scanf("%d", &age);
	//printf("����ƴ������ĸ��%c\n", first);
	//printf("���գ�%s\n", birthday);
	//printf("���䣺%d\n", age);
	
	//float a, b, c, average;
	//cin >> a >> b >> c;
	//average = (a + b + c) / 3;
	//cout << average << " " << sqrt((1.0 / 3) * (pow((a - average), 2) +
	//	pow((b - average), 2) + pow((c - average), 2)));

	//int input = 0;
	//do
	//{
	//	system("cls");
	//	menu();
	//	scanf("%d", &input);
	//	switch (input)
	//	{
	//	case 1:
	//		printf("��ʾ����ѧԱ��Ϣ\n");
	//		break;
	//	case 2:
	//		printf("��ѯѧԱ��Ϣ\n");
	//		break;
	//	case 3:
	//		printf("¼��ѧԱ��Ϣ\n");
	//		break;
	//	case 4:
	//		printf("ɾ��ѧԱ��Ϣ\n");
	//		break;
	//	case 5:
	//		printf("�޸�ѧԱ��Ϣ\n");
	//		break;
	//	case 6:
	//		printf("����ѧԱ��Ϣ\n");
	//		break;
	//	case 0:
	//		printf("�˳�����\n");
	//		break;
	//	default:
	//		printf("����������������룺\n");
	//		break;
	//	}
	//	system("pause");
	//} while (input);

	//��Сд����
	//char password[5] = { 0 };
	//int i = 0;
	//int c = 0;
	//while (i < 4)
	//{
	//	password[i++] = _getch();
	//	putchar('#');
	//}
	//password[i] = '\0';
	//if (!strcmp(password, "xmOK"))
	//	printf("\n��ӭ��\n");
	//else
	//	printf("\n����\n");
	//��Сд������
	//char password[5] = { 0 };
	//int i = 0;
	//int c = 0;
	//while (i < 4)
	//{
	//	password[i++] = _getch();
	//	putchar('#');
	//}
	//password[i] = '\0';
	//if (!strcmp(password, "xmOK") || !strcmp(password, "XmOK") 
	//	|| !strcmp(password, "xMOK") || !strcmp(password, "XMOK"))
	//	printf("\n��ӭ��\n");
	//else
	//	printf("\n����\n");

	//int a, b, c;
	//cin >> a >> b >> c;
	//cout << max(max(a, b), c) << endl;
	//if (a > 90 || b > 90 || c > 90)
	//	cout << "good" << endl;

	//Stu a, b;
	//scanf("%s%s", a.name, a.birthday);
	//scanf("%s%s", b.name, b.birthday);
	//if (!strcmp(a.name, b.name) && !strcmp(a.birthday, b.birthday))
	//	printf("yes\n");
	//else printf("no\n");

	/*��·�������£�
	(���ʽ1��&&(���ʽ2) ������ʽ1Ϊ�٣�����ʽ2����������㣬�����ʽ2������·��
	(���ʽ1��||(���ʽ2) ������ʽ1Ϊ�棬����ʽ2����������㣬�����ʽ2������·��*/
	//int a = 1, b = 1, c = 0, d = 0;
	//��֤&&��·���������ʽ1������cΪ1������cΪ0
	//if (a != b && (c += a));
	//printf("%d\n", c);
	//if (a == b && (c += a));
	//printf("%d\n", c);
	//�����ʽ1������cΪ0������cΪ1
	//if (a == b || (c += a));
	//printf("%d\n", c);	
	//if (a != b || (c += a));
	//printf("%d\n", c);

/*ǰ��++���Ƚ��м�һ������ʹ����ֵ������++����ʹ����ֵ�ٽ��м�һ*/
	//int i = 0;
	//printf("%d", i++);



	float a, b, c, x1, x2;
	printf("������һԪ���η���ϵ��:\n");
	scanf("%f%f%f", &a, &b, &c);
	float tmp = b * b - 4 * a * c;
	if (tmp < 0)
	{
		printf("�÷�����ʵ��\n");
		exit(-1);
	}
	x1 = (-b + sqrt(tmp)) / (2 * a);
	x2 = (-b - sqrt(tmp)) / (2 * a);
	printf("x1=%f\nx2=%f\n", x1, x2);

	return 0;
}