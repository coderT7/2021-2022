#define _CRT_SECURE_NO_WARNINGS 1

#include"experiment_st_nd.h"
///*
//һ����д���򣬸�ʽ�����
//������д����ʵ��Сд��ĸת��д��
//������д����ʵ������������ͬ�������ݺ󣬾����ʵ������㣨�ӡ������ˡ������������
//�ġ���д���򣬼�������������������������ͱ������
//�塢��д������֤int��char��float��double��long int��short int���������͵ĳ��ȡ�
//������д������֤ȡģ�����У����ָ���ʱ��������ɡ�*/
//
void print()
{
	printf("%-8s%-8s%-8s%-8s%-8s%-8s\n", "ѧ��", "����", "����", "��ѧ", "Ӣ��", "ƽ����");
	printf("%-8s%-8s%-8s%-8s%-8s%-8s\n", "====", "====", "====", "====", "====", "====");
	printf("%-8s%-8s%-8s%-8s%-8s%-8s\n", "1", "34", "56.0", "778.0", "23.0", "285.7");
}
void m_toupper()
{
	cout << "������Ҫ����ת������ĸ��";
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
		cout << "��ӣ�" << a + b << " " << "�����" << a - b << " "
			<< "��ˣ�" << a * b << " " << "�����" << a*1.0 / b << endl;
		cout << "ps��������Ϊ������Ľ��" << endl;
	}
	else
	{
		cout << "��������Ϊ0��" << endl;
		return;
	}
}
void geometry_cal(float a, float b, float c, int flag)//Ĭ�ϲ���ֻ�ܳ���һ��
{
	if (flag && (a + b) > c && (a + c) > b && (b + c) > a)
	{
		float p = (a + b + c) / 2;
		cout << "�����ε����Ϊ��" << sqrt(p * (p - a) * (p - b) * (p - c)) << endl;
		return;
	}
	else if(flag == 1)
	{
		cout << "��������������֮��Ҫ���ڵ�����Ŷ~" << endl;
		return;
	}
	else 
		cout << "����������Ϊ��" << pow(a, 3) << endl << "������ı����Ϊ��" << a * a * 6 << endl;
	return;
}
void data_size()
{
	cout << "���ͣ�" << sizeof(int) << " " << "�ַ����ͣ�" << sizeof(char) << " "
	<< "�����ͣ�" << sizeof(float) << " " << "˫���ȸ����ͣ�" << sizeof(double) << " "
	<< "�����ͣ�" << sizeof(long) << " " << "�����ͣ�" << sizeof(short) << endl;
	cout << "��λ���ֽ�" << endl;
}
void mod()
{
	cout << -2 % 1 << " " << 11 % -5 << " " << - 11 % 5 << " " << -2 % -1 << -11 % -5 << endl;
	cout << "Դ�룺" << endl
		<< "cout << -2 % 1 << " " << 11 % -5 << " " << - 11 % 5 << " " << -2 % -1 << -11 % -5 << endl;" 
		<< endl;
	cout << "��������0 1 - 1 0 - 1��֪����������ȡģʱ���������뱻������������һ��Ϊ0���������Ծ�������" << endl;
	cout << "��ȡģ����Ľ���ķ������һ���������ķ�����ͬ(��Ϊ0)" << endl;
}
