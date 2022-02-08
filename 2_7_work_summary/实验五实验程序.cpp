#define _CRT_SECURE_NO_WARNINGS 1

#include"experiment_5th.h"
/*一、编写程序，设计函数，实现把两个输入的字符串交叉合并，合并时，把小写字母改成大写。
二、输入一个由单词组成的字符串，分别设计函数，完成如下处理：
（1）、统计字符的个数；（2）、统计字符串中单词的数量；
（3）、按5个单词一行，输出所有单词；（4）、统计单词平均字符数；
（5）、反向输出各个单词，如输入是：I am a student输出student a am I。
三、身份证号码处理。（1）设计函数判断一个身份证号码，是否符合标准；
（2）分析一个身份证号码：是否合法、出生日期、性别等信息；
（3）设计函数，把一个15位的老号码，转换成18位的新号码。身份证转换方法见附件。
四、设计方案，验证C语言中，函数参数传递时，参数入栈的顺序。（清晰的文字描述和例子）
五、设计方案，验证C语言中，“指针变量的存储空间与类型无关，指针的运算看类型”的结论。(清晰的文字描述和设计例子)*/
static char* merge_string(char* str1, char* str2)
{
	int len1 = (int)strlen(str1); int len2 = (int)strlen(str2);
	//+1是为了在合并后的字符串末尾添入'\0'
	int len = len1 + len2 + 1;
	//合并到一个新的空间里去
	char* merge = (char*)malloc(sizeof(char) * len);
	//给定字符串的下标
	int begin1 = 0, begin2 = 0, index = 0;
	//进行合并插入新空间
	while (str1[begin1] && str2[begin2])
	{
		if (islower(str1[begin1]))
			str1[begin1] = toupper(str1[begin1]);
		if (islower(str2[begin2]))
			str2[begin2] = toupper(str2[begin2]);
		merge[index++] = str1[begin1++];
		merge[index++] = str2[begin2++];
	}
	//因为是依次合并，可能会有某个字符串未合并完，有遗留，故此处理
	while (str1[begin1])
	{
		if (islower(str1[begin1]))
			str1[begin1] = toupper(str1[begin1]);
		merge[index++] = str1[begin1++];
	}
	while (str2[begin2])
	{
		if (islower(str2[begin2]))
			str2[begin2] = toupper(str2[begin2]);
		merge[index++] = str2[begin2++];
	}
	//给合并字符串添加终止字符
	merge[index] = '\0';
	return merge;
}
void merge_string()
{
	char* arr1 = (char*)malloc(sizeof(char) * 100);
	char* arr2 = (char*)malloc(sizeof(char) * 100);
	if(!arr1 || !arr2)
	{
		printf("申请空间失败！\n");
		exit(-1);
	}
	cout << "请输入要合并的两个字符串" << endl;
	scanf("%s%s", arr1, arr2);
	char* merge = merge_string(arr1, arr2);
	cout << "合并后的字符串：" << endl << merge << endl;
	free(arr1);free(arr2);free(merge);
	return;
}

/*二、输入一个由单词组成的字符串，分别设计函数，完成如下处理：
（1）、统计字符的个数；（2）、统计字符串中单词的数量；
（3）、按5个单词一行，输出所有单词；（4）、统计单词平均字符数；
（5）、反向输出各个单词，如输入是：I am a student输出student a am I*/
//统计字符的个数
int statistics_char(char* text_string)
{
	int count = 0, index = 0;
	//依次计数直到终止字符即可
	while (text_string[index] != '\0')
	{
		count++;
		index++;
	}
	return count;
}
//统计字符串中单词的数量
int statistics_word(char* text_string)
{
	int len = statistics_char(text_string);
	int count = 0, index = 0, flag = 0;
	while (text_string[index] != '\0')
	{
		//当前字符不为空格则说明其为单词，则指针往后走，且flag置为1
		while (text_string[index] != ' ' && text_string[index])
		{
			index++;
			flag = 1;
		}
		//走到这说明已经碰到空格了，也就是说一个单词结束了，此时count计数
		if(flag) count++;
		//计数后指针继续走，并将flag置为0，这样做是防止如果连续遇到多个空格，count无脑++
		if(text_string[index])
			index++; flag = 0;
	}
	return count;
}
//按五个单词一行，输出所有单词
void m_print(char* text_string)
{
	int len = statistics_char(text_string);
	int count = 0, index = 0, flag = 0, count_newline = 0;
	while (text_string[index])
	{
		int tmp = index;
		//当前字符不为空格则说明其为单词，则指针往后走，且flag置为1
		while (text_string[index] != ' ' && text_string[index])
		{
			index++;
			flag = 1;
		}
		//走到这说明已经碰到空格了，也就是说一个单词结束了，此时输出该单词
		if (flag)
		{
			while (tmp < index)
			{
				printf("%c", text_string[tmp]);
				tmp++;
			}
			printf(" ");
			count_newline++;
			if (!(count_newline % 5)) printf("\n");
		}
		//计数后指针继续走，并将flag置为0，这样做是防止如果连续遇到多个空格，count无脑++
		if (text_string[index])
			index++; flag = 0;
	}
}
//统计单词平均字符数
int statistics_word_char(char* text_string)
{
	int count = 0, index = 0;
	//依次计数直到终止字符即可
	while (text_string[index] != '\0')
	{
		if (text_string[index] != ' ')
			count++;
		index++;
	}
	return count;
}
int statistics_ave_char(char* text_string)
{
	return statistics_word_char(text_string) / statistics_word(text_string);
}
//反向输出各个单词
void reverse_output(char* text_string)
{
	//建立栈存放单词下标信息
	stack<int> st;
	int len = statistics_char(text_string);
	int count = 0, index = 0, flag = 0, word_index = 0;
	while (text_string[index])
	{
		int tmp = index;
		//当前字符不为空格则说明其为单词，则指针往后走，且flag置为1
		while (text_string[index] != ' ' && text_string[index])
		{
			index++;
			flag = 1;
		}
		//走到这说明已经碰到空格了，也就是说一个单词结束了，此时保存该单词的首尾下标到栈中
		if (flag)
		{
			st.push(index - 1);
			st.push(tmp);
		}
		//计数后指针继续走，并将flag置为0，这样做是防止如果连续遇到多个空格，count无脑++
		if (text_string[index])
			index++; flag = 0;
	}
	//单词保存完毕后开始输出
	//每次取两个栈顶的数据（即一个单词的首尾下标）依次输出即可
	while (!st.empty())
	{
		int first = st.top();
		st.pop();
		int last = st.top();
		st.pop();
		while (first <= last)
		{
			printf("%c", text_string[first]);
			first++;
		}
		printf(" ");
	}
}
void string_manipulation()
{
	getchar();
	char* text_string = (char*)malloc(sizeof(char) * 100);
	if(!text_string)
	{
		printf("申请空间失败！\n");
		exit(-1);
	}
	cout << "请输入要进行分析处理的字符串：" << endl;
	scanf("%[^\n]%*c", text_string);
	//统计字符的个数
	int len = statistics_char(text_string);
	printf("该字符串的字符个数为：%d\n", len);
	//统计字符串中单词的数量
	int word_num = statistics_word(text_string);
	printf("该字符串的单词个数为：%d\n", word_num);
	//按五个单词一行，输出所有单词
	m_print(text_string);
	printf("\n");
	//统计单词平均字符数
	int ave_char = statistics_ave_char(text_string);
	printf("该字符串的单词的平均字符个数为：%d\n", ave_char);
	//反向输出各个单词
	reverse_output(text_string);
	free(text_string);
	return;
}

/*三、身份证号码处理。
（1）设计函数判断一个身份证号码，是否符合标准；
（2）分析一个身份证号码：是否合法、出生日期、性别等信息；
（3）设计函数，把一个15位的老号码，转换成18位的新号码。身份证转换方法见附件。*/
bool judge(char ID[])
{
	//根据国家身份证校验位计算公式进行运算
	int sum = 0;
	int a[17] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };
	char b[11] = { '1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2' };
	for (int i = 0; i < 17; i++)
		sum += a[i] * (ID[i] - '0');
	sum %= 11;
	//校验位符合标准则身份证合法否则不合法
	if (b[sum] == ID[17]) return true;
	return false;
}
 //解析身份证个人信息
void analysis(char* ID)
{
	printf("\n出生年份：\n");
	for (int i = 6; i <= 9; i++)
		printf("%c", ID[i]);
	printf("\n出生月份：\n");
	for (int i = 10; i <= 11; i++)
		printf("%c", ID[i]);
	printf("\n出生日：\n");
	for (int i = 12; i <= 13; i++)
		printf("%c", ID[i]);
	if (!((ID[16] - '0') % 2))
		printf("\n性别：女\n");
	else
		printf("\n性别：男\n");
}
//15位旧身份证转换成新18位身份证
void change_new(char* ID)
{
	//按转换规则进行运算即可
	for (int i = 14; i > 6; i--)
		ID[i + 2] = ID[i];
	//插入数据
	ID[6] = '1'; ID[7] = '9';
	//计算校验位
	int sum = 0;
	//稍微复杂的一个计算公式
	int a[17] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };
	char b[11] = { '1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2' };
	for (int i = 0; i < 17; i++)
		sum += a[i] * (ID[i] - '0');
	sum %= 11;
 //得出校验位并添入身份证末位中
	for (int i = 0; i < 11; i++)
		if (sum == i)
			ID[17] = b[i];
}
void ID_number_processing()
{
	char ID[19] = { 0 };
	cout << "请输入要进行分析的身份证号码：" << endl;
	scanf("%s", ID);
	int len = (int)strlen(ID);
	if (len == 15)
	{
		cout << "检测到您输入的身份证号码为老式身份证号码" << endl
			<< "已为您转换成新式身份证号码" << endl;
		//以旧换新
		change_new(ID);
	}
	printf(ID);
	//判断是否符合标准
	bool ret = judge(ID);
	if (ret)
	{
		printf("该身份证号码符合标准\n");
		//解析身份证信息
		analysis(ID);
	}
	else 
		printf("该身份证号码不符合标准\n");
	return ;
}

/*四、设计方案，验证C语言中，函数参数传递时，参数入栈的顺序。（清晰的文字描述和例子）*/
void push_order()
{
	cout << "函数调用过程中，第一个进栈的是（主函数中的）调用处的下一条指令" <<
		"（即函数调用语句的下一条可执行语句）的地址；" << endl
		<< "然后是函数的各个参数，而在大多数C/C++编译器中，在函数调用的过程中，函数的参数是由右向左入栈的；"
		<< endl << "然后是函数内部的局部变量（这里要注意static修饰的局部变量是不入栈的）；"
		<< "在函数调用结束（函数运行结束）后，局部变量最先出栈，然后是参数，最后栈顶指针指向最开始存的指令地址"
		<< endl;
	cout << "更具体的详情请见源码" << endl;
}
//
//然后是为什么是自右向左的入栈顺序？见以下实例
//void text(int x, int y, int z, int w)
//{
//	int a = 1, b = 2, c = 3;
//	printf("w = %d at %p\n", w, &w);
//	printf("x = %d at %p\n", x, &x);
//	printf("y = %d at %p\n", y, &y);
//	printf("z = %d at %p\n", z, &z);
//	printf("a = %d at %p\n", a, &a);
//	printf("b = %d at %p\n", b, &b);
//	printf("c = %d at %p\n", c, &c);
//	printf("%d %d %d\n", a, a++, a++);
//}
//int main()
//{
//	text(10, 20, 30, 40);
//	return 0;
//}
/*
运行结果：
w = 40 at 000000DE018FF8F8
x = 10 at 000000DE018FF8E0
y = 20 at 000000DE018FF8E8
z = 30 at 000000DE018FF8F0
a = 1 at 000000DE018FF7A4
b = 2 at 000000DE018FF7C4
c = 3 at 000000DE018FF7E4
3 2 1
*/
/*首先我们需要知道：C程序栈底为高地址，栈顶为低地址，即由高地址向低地址扩展（向下扩展）
因此上面的实例可以说明函数参数入栈顺序的确是从右至左,且形参先入栈，局部变量后入栈的。*/
//可到底为什么呢？
//查了一直些资料得知，参数入栈顺序是和具体编译器实现相关的,C/CPP语言设计时存在有两种函数调用的约定。
//比如，Pascal语言中参数就是从左到右入栈的
//即然两种方式都可以，为什么C语言要选择从右至左呢？
//进一步发现，Pascal语言不支持可变长参数，而C语言支持这种特色，正是这个原因使得C语言函数参数入栈顺序为从右至左。
//首先自右向左的入栈方式便于找到第一个参数的位置,便于可变参数的实现和使用
//通过栈堆分析可知(栈向下扩展，堆向上扩展)，自左向右的入栈方式，最前面的参数被压在栈底。
//除非知道参数个数，否则是无法通过栈指针的相对位移求得最左边的参数。
/*对于可变长参数的实现，可去stdar.h库中的源码进行查看*/
//这样就变成了左边参数的个数不确定，正好和动态参数个数的方向相反。
//因此，C语言函数参数采用自右向左的入栈顺序，主要原因是为了支持可变长参数形式。
//换句话说，如果不支持这个特色，C语言完全和Pascal一样，采用自左向右的参数入栈方式。

/*五、设计方案，验证C语言中，“指针变量的存储空间与类型无关，指针的运算看类型”的结论。(清晰的文字描述和设计例子)*/
void point_conclusion()
{
	cout << "//计算查看不同类型的指针大小" <<
		"printf(\"%d %d %d %d\\n\", (int)sizeof(int*), (int)sizeof(char*), (int)sizeof(float*), (int)sizeof(double*))"
		<< "运行结果为 4 4 4 4，故可知指针变量的存储空间与类型无关" << endl;
	cout << "具体原因以及下一个问题见源码" << endl;
	//原因：无论是何种类型的数据，其都是存储在内存上的，而内存的空间是以字节为最小单位划分的
	// 每一个字节都有其对应的编码，在32位机器下，则共有2^32个内存编号，故此每个编号的长度都为32个比特位即四个字节
	// 指针变量存储的即是对应数据的首字节的地址，该地址的编号固定为4个字节
	// 故此指针变量的存储空间只要够容纳这个地址的编号即可，也就是4个字节（在64位机器下则为8个字节）
	//整型数组
	//int arr[] = { 1,2,3,4,5 };
	////首元素的地址应用整型指针存储，这里进行强转，用于验证指针的运算看类型的结论
	//short* p = (short*)arr;
	//int i = 0;
	////每次加1，一共加四次，若为整型指针，则操作了十六个字节，结果为0 0 0 0 5
	//for (i = 0; i < 4; i++)
	//    *(p + i) = 0;
	////因为是短整型指针，每次只能访问两个字节，则操作了八个字节，故最后结果为0 0 3 4 5
	//for (i = 0; i < 5; i++)
	//    printf("%d ", arr[i]);
	return ;
}
