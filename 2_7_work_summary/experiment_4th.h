#pragma once
#include<iostream>
#include<cstdio>
#include<cmath>
#include<ctime>
using namespace std;
/*ʵ����*/
//1.һ��������������100����һ����ȫƽ�������ټ���168����һ����ȫƽ���������ʸ����Ƕ��٣�
void solve_equ(int);
//2.Ϊʹ���ı��ܣ�������һ�����ɽ���ת�������룬�ձ����ٰ�Լ���Ĺ��ɽ������ԭ�ġ�
//��Ӧ��ϵ���£�
//abcdefghijklmnopqrstuvwxyz
//efghijklmnopqrstuvwxyzabcd
//ABCDEFGHIJKLMNOPQRSTUVWXYZ
//EFGHIJKLMNOPQRSTUVWXYZABCD
//��д����ʵ�����ϱ���ת����Ҫ�󣺷���ĸ�ַ�����ԭ״���䣻����һ���ַ���Ҫ���������Ӧ�����롣
void simple_encrypt();
//3.�ж�101 - 200֮���ж��ٸ����������������������
//Ҫ���ж������ú���ʵ�֡�
void m_prime();
//4.��ӡ����
void print_diamond();
//5.��1 + 2!+ 3!+ ... + 20!�ĺ͡�Ҫ�󣺽׳��ú���ʵ�֡�
void fac();
//6.���һ������ģ����Ӳ�ҵĲ��ԣ�����Ӳ��ͷ�����ϼ����µĴ����ͱ�����
//ͨ��������ֵ��ģ����100�Σ�1000�κ�10000�ε������
void probability();