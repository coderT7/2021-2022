#pragma once
#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctype.h>
#include<cmath>
#include<conio.h>
#include<algorithm>
using namespace std;
/*ʵ����*/
//1. ��scanf, printf�������µ�����������
//��1�������Լ������գ�����ƴ��������ĸ������(�磺20.8)��Ȼ�������
//ע��ʹ��fflush(stdin)���������������
void print_1();
//��2�������Լ��߿����пγ̵ĳɼ�(��һ������ʵ�ɼ�һģһ��), ����ƽ���ɼ��ͱ�׼����������
void print_2();
//��3�������ѧ������ϵͳ���Ĳ˵����������1�����������ʾ����ѧԱ��Ϣ����
//�������2���������ѯѧԱ��Ϣ�����Դ����ƣ���switch()������
void print_3();
//2.��֤�������С���ĵ�¼�����ǡ�xmOK��������ƿ�����֤����С������ʱ��
//����ʾ�������ģ���֮�ԡ�#����������ȷ����ʾ����ӭ���������������ʾ�����󣡡���
//��������Ǵ�Сд�����еģ���������������
void password();
//3 ����3�ſεĳɼ�����������гɼ�������һ�ſΡ�
//���߼�����ϵ�����жϣ�������гɼ���������һ�ſδ���90�������good��
void max_3();
//4. ������һ��ѧ��A�����������գ�������һ��ѧ��B�����������ա�
//���߼�����ϵ�����жϣ����A��B�����������ն�����ͬ�ģ������yes, ���� ���no��
void m_compare();
//5. ʲô�Ƕ�·���򣿱�д������֤��·����
void rule();
//6.�Լ������ǰ׺�ͺ�׺��ʲô���𣿱�д������֤֮��
void difference();
//7. ��д�������һԪ���η��̡�
void solve_equ();