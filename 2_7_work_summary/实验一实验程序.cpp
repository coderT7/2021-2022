#define _CRT_SECURE_NO_WARNINGS 1

#include"experiment_st_nd.h"


//1.������ϻ����У���3�������ĺ͡�
void sum_three(int a, int b, int c)
{
	cout << "��ӵĽ����" << a + b + c << endl;
}
//2.������ϻ����У���2�����ĺ͡�������̡�
void four_arithmetic(int a, int b)
{
	if (b)
	{
		cout << "��ӣ�" << a + b << " " << "�����" <<  a - b << " " 
			<< "��ˣ�"<<a * b << " " << "�����" << a / b << endl;
		cout << "ps��������Ϊ�����Ľ��" << endl;
	}
	else
	{
		cout << "��������Ϊ0��" << endl;
		return;
	}
}
//3.������ϻ����У���2�����нϴ��ߣ���3�������ֵ��
void max_num(int a, int b, int c)//��C++�У��������β��б��е��β��ǿ�����Ĭ��ֵ��
{
	cout << "�������е����ֵΪ��" << max(max(a, b), c) << endl;
}
//4.������ϻ����У�����Բ�İ뾶����Բ��������ܳ���
void cal_circle(float r)
{
	cout << "��Բ�����Ϊ��" << PI * pow(r, 2) << " " << "��Բ���ܳ�Ϊ��" << 2 * PI * r << endl;
}
//5.����Ļ���������hello world!����
void m_print()
{
	cout << "\"hello world!\"" << endl;
}
//6��������úÿ��ķ�ʽ������Լ���ѧ�š��������Ա����ա��༶���Լ��������֡� * /
void m_print(int)//C++֧��ʹ��ռλ����
{
	cout << "ѧ�ţ�" << endl << "������" << endl << "���գ�" <<
		endl << "�༶��2021030052" << endl << "�������֣�***" << endl;
}

