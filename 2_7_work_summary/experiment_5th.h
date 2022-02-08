#pragma once
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<stack>
using namespace std;
//一、编写程序，设计函数，实现把两个输入的字符串交叉合并，合并时，把小写字母改成大写。
void merge_string();
//二、输入一个由单词组成的字符串，分别设计函数，完成如下处理：
//（1）、统计字符的个数；
//（2）、统计字符串中单词的数量；
//（3）、按5个单词一行，输出所有单词；
//（4）、统计单词平均字符数；
//（5）、反向输出各个单词，如输入是：I am a student输出student a am I。
void string_manipulation();
//三、身份证号码处理。
//（1）设计函数判断一个身份证号码，是否符合标准；
//（2）分析一个身份证号码：是否合法、出生日期、性别等信息；
//（3）设计函数，把一个15位的老号码，转换成18位的新号码。身份证转换方法见附件。
void ID_number_processing();
//四、设计方案，验证C语言中，函数参数传递时，参数入栈的顺序。（清晰的文字描述和例子）
void push_order();
//五、设计方案，验证C语言中，“指针变量的存储空间与类型无关，指针的运算看类型”的结论。
//(清晰的文字描述和设计例子)
void point_conclusion();

