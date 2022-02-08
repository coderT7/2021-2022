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
#define HAIR 120000
//一、把一个正整数的各位数求和
void digit_sum();
//二、把一个正整数倒置
void reverse_int();
//三、先设计最大公约数函数，利用该函数，设计求最大公倍数的函数；
void max_div_min_mul();
//四、把一个正整数化为二进制
void change_bin();
//五、使用提供0 - 9数字点阵字模，编写显示字模函数，并实现把字模镜像、倒影、斜体等特显。
//数字点阵
enum MODE
{
    EXIT,//退出
    GENERAL,//普通
    ITALIC,//斜体
    MIRROR,//镜像
    INVERTED//倒影
};
void digital_dot_matrix();
//按行输出自己的学号、生日。
//六、编写程序，设计函数，实现把两个输入的字符串交叉合并，合并时，把小写字母改成大写。
//如：两个串”aBc1122”、”7xYZ”合并后为”A7BXCY1Z122”。
void six_merge_string();
//七、编写程序，设计两个函数。
// 函数一：把一个文本文件加密成密文文件；
// 函数二：把密文文件解密成原文文件。加密的算法：（加、解密算法采用位操作）
// (1)每个字节高四位和低四位对调、
// (2)每个字节高二位和低2位对调、
// (3)字节逆序。
void en_de_crypt();

//八、一个计算机专业的大学生（准程序员），每天掉头发80 - 120根（随机模拟），每天长出0 - 80根（随机模拟）。
//假设该生入学时有头发12万根，请设计程序，计算该生4年后，毕业时头上的头发数量。
void last_hair();
