#pragma once
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<conio.h>
#include<Windows.h>
using namespace std;
//#define HAIR 120000
////һ����һ���������ĸ�λ�����
//int digit_sum(int n);
////������һ������������
//int reverse_int(int n);
////������������Լ�����������øú������������󹫱����ĺ�����
//int max_div(int a, int b);
//int min_mul(int a, int b);
////�ġ���һ����������Ϊ������
//void change_bin(int n, int arr[32]);
////�塢ʹ���ṩ0 - 9���ֵ�����ģ����д��ʾ��ģ��������ʵ�ְ���ģ���񡢵�Ӱ��б������ԡ�
////���ֵ���
//char a[10][8] =
//{
//    {0x00,0x18,0x24,0x24,0x24,0x24,0x24,0x18}, //0
//    {0x00,0x18,0x1c,0x18,0x18,0x18,0x18,0x18}, //1
//    {0x00,0x1e,0x30,0x30,0x1c,0x06,0x06,0x3e}, //2
//    {0x00,0x1e,0x30,0x30,0x1c,0x30,0x30,0x1e}, //3
//    {0x00,0x30,0x38,0x34,0x32,0x3e,0x30,0x30}, //4
//    {0x00,0x1e,0x02,0x1e,0x30,0x30,0x30,0x1e}, //5
//    {0x00,0x1c,0x06,0x1e,0x36,0x36,0x36,0x1c}, //6
//    {0x00,0x3f,0x30,0x18,0x18,0x0c,0x0c,0x0c}, //7
//    {0x00,0x1c,0x36,0x36,0x1c,0x36,0x36,0x1c}, //8
//    {0x00,0x1c,0x36,0x36,0x36,0x3c,0x30,0x1c}, //9
//};
//enum MODE
//{
//    EXIT,//�˳�
//    GENERAL,//��ͨ
//    ITALIC,//б��
//    MIRROR,//����
//    INVERTED//��Ӱ
//};
//void mirror_inverted_display(MODE mode, int n);
//void general_italic_display(MODE mode, int n);
////��������Լ���ѧ�š����ա�
////������д������ƺ�����ʵ�ְ�����������ַ�������ϲ����ϲ�ʱ����Сд��ĸ�ĳɴ�д��
////�磺��������aBc1122������7xYZ���ϲ���Ϊ��A7BXCY1Z122����
////char* merge_string(char* str1, char* str2);
////�ߡ���д�����������������
//// ����һ����һ���ı��ļ����ܳ������ļ���
//// ���������������ļ����ܳ�ԭ���ļ������ܵ��㷨�����ӡ������㷨����λ������
//// (1)ÿ���ֽڸ���λ�͵���λ�Ե���
//char fun1(char ch);
//// (2)ÿ���ֽڸ߶�λ�͵�2λ�Ե���
//char fun2(char ch);
//// (3)�ֽ�����
//char fun3(char ch);
//void encrypt(char text[], int len);
//void decrypt(char text[], int len);
////�ˡ�һ�������רҵ�Ĵ�ѧ����׼����Ա����ÿ���ͷ��80 - 120�������ģ�⣩��ÿ�쳤��0 - 80�������ģ�⣩��
////���������ѧʱ��ͷ��12���������Ƴ��򣬼������4��󣬱�ҵʱͷ�ϵ�ͷ��������
//long last_hair();
