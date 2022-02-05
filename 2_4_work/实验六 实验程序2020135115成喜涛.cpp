#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<conio.h>
#include<Windows.h>
using namespace std;

/*把一个正整数的各位数求和*/
//int sum = 0;
//int digit_sum(int n)
//{
//	if (n > 9)
//		digit_sum(n / 10);
//	return sum += n % 10;
//}
//
//int main()
//{
//	int n = 0;
//	cin >> n;
//	cout << digit_sum(n);
//	return 0;
//}

/*把一个正整数倒置*/
//int reverse_int(int n)
//{
//    int rev = 0;
//    while (n)
//    {
//        //防止输入的数字超出32位下可运算范围
//        if (rev < INT_MIN / 10 || rev > INT_MAX / 10) 
//        {
//            cout << "输入数值超出运算范围" << endl;
//            return 0;
//        }
//        //每次取末位弹入rev的末位（即成为首位），逐步完成倒置
//        int digit = n % 10;
//        n /= 10;
//        rev = rev * 10 + digit;
//    }
//    return rev;
//}
//int main()
//{
//	int n = 0;
//	cin >> n;
//	cout << reverse_int(n);
//	return 0;
//}

/*先设计最大公约数函数，利用该函数，设计求最大公倍数的函数；*/
//int max_div(int a, int b)
//{
//	//试除法
//	//if (a < b) swap(a, b);
//	//int m = b;
//	//while (true)
//	//{
//	//	if (!(a % m) && !(b % m))
//	//		break;
//	//	m--;
//	//}
//	//return m;
//	//辗转相除法
//	int x = a % b;
//	while (x)
//	{
//		a = b;
//		b = x;
//		x = a % b;
//	}
//	return b;
//}
//int min_mul(int a, int b)
//{
//	int m = max_div(a, b);
//	//按公式进行计算
//	return a * b / m;
//}
//int main()
//{
//	int a, b;
//	cin >> a >> b;
//	cout << "最大公约数：" << max_div(a, b) << endl;
//	cout << "最小公倍数" << min_mul(a, b) << endl;
//	return 0;
//}

/*把一个正整数化成二进制*/
//void change_bin(int n, int arr[32])
//{
//	int index = 0;
//	for (int i = 31; i >= 0; i--)
//	{
//		//将每一位一次与1进行与运算，对应赋值到存储数组的对应位置即可
//		if (((n >> i) & 1))
//			arr[index] = 1;
//		else
//			arr[index] = 0;
//		index++;
//	}
//}
//
//int main()
//{
//	int n = 0;
//	cin >> n;
//	//存储该整数二进制位的每一位
//	int result[32] = { 0 };
//	change_bin(n, result);
//	for (int i = 0; i < 32; i++)
//		printf("%d", result[i]);
//	return 0;
//}

/*使用提供0-9数字点阵字模，编写显示字模函数，并实现把字模镜像、倒影、斜体等特显。
按行输出自己的学号、生日。*/
enum MODE
{
    EXIT,//退出
    GENERAL,//普通
    ITALIC,//斜体
    MIRROR,//镜像
    INVERTED//倒影
};
char a[10][8] =
{
    {0x00,0x18,0x24,0x24,0x24,0x24,0x24,0x18}, //0
    {0x00,0x18,0x1c,0x18,0x18,0x18,0x18,0x18}, //1
    {0x00,0x1e,0x30,0x30,0x1c,0x06,0x06,0x3e}, //2
    {0x00,0x1e,0x30,0x30,0x1c,0x30,0x30,0x1e}, //3
    {0x00,0x30,0x38,0x34,0x32,0x3e,0x30,0x30}, //4
    {0x00,0x1e,0x02,0x1e,0x30,0x30,0x30,0x1e}, //5
    {0x00,0x1c,0x06,0x1e,0x36,0x36,0x36,0x1c}, //6
    {0x00,0x3f,0x30,0x18,0x18,0x0c,0x0c,0x0c}, //7
    {0x00,0x1c,0x36,0x36,0x1c,0x36,0x36,0x1c}, //8
    {0x00,0x1c,0x36,0x36,0x36,0x3c,0x30,0x1c}, //9
};
void mirror_inverted_display(MODE mode, int n)
{
    int count[20] = { 0 };
    int k;
    for (k = 0; n && k < 20; k++)   //c数组将分离出n中的各位数，不过是倒着的，例n=123，c中保存3 2 1
    {
        count[k] = n % 10;
        n /= 10;
    }  //循环结束，将由k保存n是几位数，此处限最多20位数
    for (int i = 7; i >= 0; i--)   //一共要显示8行，不是依次显示k个数字，而是依次显示k个数字中对应的每一行
    {
        int m;//m记录着数组的下标
        if(mode == INVERTED)
            for (m = k - 1; m >= 0; m--)  //要显示n=123, c中是倒着保存各位数的，所以m由大到小
            {
                int x = 0;//x保存单个比特位的数值
                x = a[count[m]][i];     //现在要显示的数字是c[m]，所以取a数组中的第c[m]行，第i列数据
                for (int j = 0; j < 8; j++)
                {
                    if (x % 2)
                        cout << '*';
                    else
                        cout << ' ';
                    x = x / 2;
                }
            }
        else if(mode == MIRROR)
            for (m = 0; m < k; m++) 
            {
                int x = 0;//x保存单个比特位的数值
                x = a[count[m]][i];     //现在要显示的数字是c[m]，所以取a数组中的第c[m]行，第i列数据
                for (int j = 0; j < 8; j++)
                {
                    if (x % 2)
                        cout << '*';
                    else
                        cout << ' ';
                    x = x / 2;
                }
            }
        cout << endl;
    }
}
void general_italic_display(MODE mode, int n)
{
    //默认模式为普通输出，正常显示
    int count[20] = { 0 };
    int k;
    for (k = 0; n && k < 20; k++)   //c数组将分离出n中的各位数，不过是倒着的，例n=123，c中保存3 2 1
    {
        count[k] = n % 10;
        n /= 10;
    }  //循环结束，将由k保存n是几位数，此处限最多20位数
    for (int i = 0; i < 8; i++)   //一共要显示8行，不是依次显示k个数字，而是依次显示k个数字中对应的每一行
    {
        //斜体输出模式
        if(mode == ITALIC)
            for (int space = 8; space > i; space--)
                cout << " ";
        int m;//m记录着数组的下标
        for (m = k - 1; m >= 0; m--)  //要显示n=123, c中是倒着保存各位数的，所以m由大到小
        {
            int x = 0;//x保存单个比特位的数值
            x = a[count[m]][i];     //现在要显示的数字是c[m]，所以取a数组中的第c[m]行，第i列数据
            for (int j = 0; j < 8; j++)
            {
                if (x % 2)
                    cout << '*';
                else
                    cout << ' ';
                x = x / 2;
            }
        }
        cout << endl;
    }
}

void menu()
{
    cout << "***********************************" << endl;
    cout << "********     1.普通显示     *******" << endl;
    cout << "********     2.斜体显示     *******" << endl;
    cout << "********     3.镜像显示     *******" << endl;
    cout << "********     4.倒影显示     *******" << endl;
    cout << "********     0.退出         *******" << endl;
    cout << "***********************************" << endl;
}
void separator(int num)
{
    int count = 0;
    for (count = 0; num && count < 20; count++)
    {
        count++;
        num /= 10;
    }
    for (int i = 0; i < count; i++)
        cout << "----";
    cout << endl;
}
int main()
{
    int input = 0, num = 0;
    do
    {
        system("cls");
        menu();
        cout << "请选择数字点阵的模式：";
        cin >> input;
        cout << "请输入数字：";
        cin >> num;
        switch (input)
        {
        case GENERAL:
            general_italic_display(GENERAL, num);
            break;
        case ITALIC:
            general_italic_display(ITALIC, num);
            break;
        case MIRROR:
            general_italic_display(GENERAL, num);
            separator(num);
            mirror_inverted_display(MIRROR, num);
            break;
        case INVERTED:
            general_italic_display(GENERAL, num);
            separator(num);
            mirror_inverted_display(INVERTED, num);
            break;
        case EXIT:
            cout << "感谢使用！祝您生活愉快！" << endl;
            break;
        default:
            cout << "选择有误，请重新选择！" << endl;
            break;
        }
        system("pause");
    } while (input);

    return 0;
}
/*编写程序，设计函数，实现把两个输入的字符串交叉合并，合并时，把小写字母改成大写。
如：两个串”aBc1122”、”7xYZ”合并后为”A7BXCY1Z122”。*/
//char* merge_string(char* str1, char* str2)
//{
//	int len1 = (int)strlen(str1); int len2 = (int)strlen(str2);
//	//+1是为了在合并后的字符串末尾添入'\0'
//	int len = len1 + len2 + 1;
//	//合并到一个新的空间里去
//	char* merge = (char*)malloc(sizeof(char) * len);
//	//给定字符串的下标
//	int begin1 = 0, begin2 = 0, index = 0;
//	//进行合并插入新空间
//	while (str1[begin1] && str2[begin2])
//	{
//		if (islower(str1[begin1]))
//			str1[begin1] = toupper(str1[begin1]);
//		if (islower(str2[begin2]))
//			str2[begin2] = toupper(str2[begin2]);
//		merge[index++] = str1[begin1++];
//		merge[index++] = str2[begin2++];
//	}
//	//因为是依次合并，可能会有某个字符串未合并完，有遗留，故此处理
//	while (str1[begin1])
//	{
//		if (islower(str1[begin1]))
//			str1[begin1] = toupper(str1[begin1]);
//		merge[index++] = str1[begin1++];
//	}
//	while (str2[begin2])
//	{
//		if (islower(str2[begin2]))
//			str2[begin2] = toupper(str2[begin2]);
//		merge[index++] = str2[begin2++];
//	}
//	//给合并字符串添加终止字符
//	merge[index] = '\0';
//	return merge;
//}
//	/*编写程序，设计函数，实现把两个输入的字符串交叉合并，合并时，把小写字母改成大写。*/
//int main()
//{
//	char* arr1 = (char*)malloc(sizeof(char) * 100);
//	char* arr2 = (char*)malloc(sizeof(char) * 100);
//	if(!arr1 || !arr2)
//	{
//		printf("申请空间失败！\n");
//		exit(-1);
//  }
//	scanf("%s%s", arr1, arr2);
//	char* merge = merge_string(arr1, arr2);
//	cout << merge << endl;
//  free(arr1);free(arr2);free(merge);
//	return 0;
//}

/*编写程序，设计两个函数。
函数一：把一个文本文件加密成密文文件；
函数二：把密文文件解密成原文文件。加密的算法：
(1)每个字节高四位和低四位对调、(2)每个字节高二位和低2位对调、(3)字节逆序。（加、解密算法采用位操作）*/
//char fun1(char ch)
//{
//	//ch&0xf   取低4位
//	//(ch&0xf)<<4 将低4位移到高4位
//	//(ch&0xf0) 取高4位
//	//(ch&0xf0)>>4 将高4位移到低4位
//	char tmp = ((ch & 0xf) << 4) | ((ch & 0xf0)>>4);
//	return tmp;
//}
//char fun2(char ch)
//{
//	//与加密算法1大致相同，不过需要注意当高低二位进行对调后，中间四位要与原先一致
//	char tmp = ((ch & 0x3) << 6) | ((ch & 0xC0) >> 6) | (ch & 0x3C);
//	return tmp;
//}
//char fun3(char ch)
//{
//	char tmp;
//	//通过控制循环变量来控制每次取的二进制位
//	for (int j = 7,i = 7; i >= 1; i -= 2, j -= 1)
//	{
//		//每次进行首尾比特位交换后，除了交换的两端改变之外，两端中间的二进制位要与原先一致
//		//这里采用枚举法暴力加密
//		if (j == 7)
//			tmp = (ch & (int)pow(2, j) >> i) | (ch & (int)pow(2, 7 - j) << i) | (ch & 0x7E);
//		else if (j == 6)
//			tmp |= (ch & (int)pow(2, j) >> i) | (ch & (int)pow(2, 7 - j) << i) | (ch & 0x3C);
//		else if(j == 5)
//			tmp |= (ch & (int)pow(2, j) >> i) | (ch & (int)pow(2, 7 - j) << i) | (ch & 0x18);
//	}
//	return tmp;
//}
//void encrypt(char text[],int len)
//{
//	//按要求依次进行加密
//	for (int i = 0; i < len; i++)
//	{
//		text[i] = fun1(text[i]);
//		text[i] = fun2(text[i]);
//		text[i] = fun3(text[i]);
//	}
//}
//void decrypt(char text[],int len)
//{
//	//倒着解密即可
//	for (int i = 0; i < len; i++)
//	{
//		text[i] = fun3(text[i]);
//		text[i] = fun2(text[i]);
//		text[i] = fun1(text[i]);
//	}
//}
//int main()
//{
//	char text[100] = { 0 };
//	scanf("%[^\n]%*c", text);
//	int len = (int)strlen(text);
//	//打开文件
//	FILE* pfile = fopen("encrypt.txt", "wb");
//	//对输入的文本内容进行加密
//	encrypt(text,len);
//	//输出到文件
//	fwrite(text, sizeof(char), sizeof(text), pfile);
//	fclose(pfile);
//	printf("加密后的内容：\n%s\n",text);
//	decrypt(text,len);
//	//可将文件内容取出进行解密
//	//pfile = fopen("encrypt.txt", "wb");
//	//fwrite(text, sizeof(char), sizeof(text), pfile);
//	//fclose(pfile);
//	printf("解密后的内容：\n%s\n", text);
//	return 0;
//}

/*八、一个计算机专业的大学生（准程序员），
每天掉头发80-120根（随机模拟），每天长出0-80根（随机模拟）。
假设该生入学时有头发12万根，请设计程序，计算该生4年后，毕业时头上的头发数量。*/
//#define HAIR 120000
//int last_hair()
//{
//	int hair = HAIR;
//	//粗略计算一年为365天，四年则为1460天
//	int day = 1460;
//	while (day--)
//		hair = (hair - (rand() % 41 + 80)) + (rand() % 81);
//	return hair;
//}
//
//int main()
//{
//	srand((unsigned int)time(NULL));
//	cout << last_hair();
//	return 0;
//}