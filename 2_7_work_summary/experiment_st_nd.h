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
/*ʵ��һ*/
//1.������ϻ����У���3�������ĺ͡�
void sum_three(int a, int b, int c);
//2.������ϻ����У���2�����ĺ͡�������̡�
void four_arithmetic(int a, int b);
//3.������ϻ����У���2�����нϴ��ߣ���3�������ֵ��
void max_num(int a, int b, int c = 0);//��C++�У��������β��б��е��β��ǿ�����Ĭ��ֵ��
//4.������ϻ����У�����Բ�İ뾶����Բ��������ܳ���
void cal_circle(float r);
//5.����Ļ���������hello world!����
void m_print();
//6��������úÿ��ķ�ʽ������Լ���ѧ�š��������Ա����ա��༶���Լ��������֡� * /
void m_print(int);//C++֧��ʹ��ռλ����
/*ʵ���*/
//һ����д���򣬸�ʽ�����
void print();
//������д����ʵ��Сд��ĸת��д��
void m_toupper();
//������д����ʵ������������ͬ�������ݺ󣬾����ʵ������㣨�ӡ������ˡ������������
void four_arithmetic(float a, float b);
//�ġ���д���򣬼�������������������������ͱ������
void geometry_cal(float a, float b = 0, float c = 0, int flag = 0);
//��֤���͵���Ŀ�ṩ���ۼ���֤˼·����
//�塢��д������֤int��char��float��double��long int��short int���������͵ĳ��ȡ�
void data_size();
//������д������֤ȡģ�����У����ָ���ʱ��������ɡ�
void mod();

