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

/*��һ���������ĸ�λ�����*/
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

/*��һ������������*/
//int reverse_int(int n)
//{
//    int rev = 0;
//    while (n)
//    {
//        //��ֹ��������ֳ���32λ�¿����㷶Χ
//        if (rev < INT_MIN / 10 || rev > INT_MAX / 10) 
//        {
//            cout << "������ֵ�������㷶Χ" << endl;
//            return 0;
//        }
//        //ÿ��ȡĩλ����rev��ĩλ������Ϊ��λ��������ɵ���
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

/*��������Լ�����������øú������������󹫱����ĺ�����*/
//int max_div(int a, int b)
//{
//	//�Գ���
//	//if (a < b) swap(a, b);
//	//int m = b;
//	//while (true)
//	//{
//	//	if (!(a % m) && !(b % m))
//	//		break;
//	//	m--;
//	//}
//	//return m;
//	//շת�����
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
//	//����ʽ���м���
//	return a * b / m;
//}
//int main()
//{
//	int a, b;
//	cin >> a >> b;
//	cout << "���Լ����" << max_div(a, b) << endl;
//	cout << "��С������" << min_mul(a, b) << endl;
//	return 0;
//}

/*��һ�����������ɶ�����*/
//void change_bin(int n, int arr[32])
//{
//	int index = 0;
//	for (int i = 31; i >= 0; i--)
//	{
//		//��ÿһλһ����1���������㣬��Ӧ��ֵ���洢����Ķ�Ӧλ�ü���
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
//	//�洢������������λ��ÿһλ
//	int result[32] = { 0 };
//	change_bin(n, result);
//	for (int i = 0; i < 32; i++)
//		printf("%d", result[i]);
//	return 0;
//}

/*ʹ���ṩ0-9���ֵ�����ģ����д��ʾ��ģ��������ʵ�ְ���ģ���񡢵�Ӱ��б������ԡ�
��������Լ���ѧ�š����ա�*/
enum MODE
{
    EXIT,//�˳�
    GENERAL,//��ͨ
    ITALIC,//б��
    MIRROR,//����
    INVERTED//��Ӱ
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
    for (k = 0; n && k < 20; k++)   //c���齫�����n�еĸ�λ���������ǵ��ŵģ���n=123��c�б���3 2 1
    {
        count[k] = n % 10;
        n /= 10;
    }  //ѭ������������k����n�Ǽ�λ�����˴������20λ��
    for (int i = 7; i >= 0; i--)   //һ��Ҫ��ʾ8�У�����������ʾk�����֣�����������ʾk�������ж�Ӧ��ÿһ��
    {
        int m;//m��¼��������±�
        if(mode == INVERTED)
            for (m = k - 1; m >= 0; m--)  //Ҫ��ʾn=123, c���ǵ��ű����λ���ģ�����m�ɴ�С
            {
                int x = 0;//x���浥������λ����ֵ
                x = a[count[m]][i];     //����Ҫ��ʾ��������c[m]������ȡa�����еĵ�c[m]�У���i������
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
                int x = 0;//x���浥������λ����ֵ
                x = a[count[m]][i];     //����Ҫ��ʾ��������c[m]������ȡa�����еĵ�c[m]�У���i������
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
    //Ĭ��ģʽΪ��ͨ�����������ʾ
    int count[20] = { 0 };
    int k;
    for (k = 0; n && k < 20; k++)   //c���齫�����n�еĸ�λ���������ǵ��ŵģ���n=123��c�б���3 2 1
    {
        count[k] = n % 10;
        n /= 10;
    }  //ѭ������������k����n�Ǽ�λ�����˴������20λ��
    for (int i = 0; i < 8; i++)   //һ��Ҫ��ʾ8�У�����������ʾk�����֣�����������ʾk�������ж�Ӧ��ÿһ��
    {
        //б�����ģʽ
        if(mode == ITALIC)
            for (int space = 8; space > i; space--)
                cout << " ";
        int m;//m��¼��������±�
        for (m = k - 1; m >= 0; m--)  //Ҫ��ʾn=123, c���ǵ��ű����λ���ģ�����m�ɴ�С
        {
            int x = 0;//x���浥������λ����ֵ
            x = a[count[m]][i];     //����Ҫ��ʾ��������c[m]������ȡa�����еĵ�c[m]�У���i������
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
    cout << "********     1.��ͨ��ʾ     *******" << endl;
    cout << "********     2.б����ʾ     *******" << endl;
    cout << "********     3.������ʾ     *******" << endl;
    cout << "********     4.��Ӱ��ʾ     *******" << endl;
    cout << "********     0.�˳�         *******" << endl;
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
        cout << "��ѡ�����ֵ����ģʽ��";
        cin >> input;
        cout << "���������֣�";
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
            cout << "��лʹ�ã�ף��������죡" << endl;
            break;
        default:
            cout << "ѡ������������ѡ��" << endl;
            break;
        }
        system("pause");
    } while (input);

    return 0;
}
/*��д������ƺ�����ʵ�ְ�����������ַ�������ϲ����ϲ�ʱ����Сд��ĸ�ĳɴ�д��
�磺��������aBc1122������7xYZ���ϲ���Ϊ��A7BXCY1Z122����*/
//char* merge_string(char* str1, char* str2)
//{
//	int len1 = (int)strlen(str1); int len2 = (int)strlen(str2);
//	//+1��Ϊ���ںϲ�����ַ���ĩβ����'\0'
//	int len = len1 + len2 + 1;
//	//�ϲ���һ���µĿռ���ȥ
//	char* merge = (char*)malloc(sizeof(char) * len);
//	//�����ַ������±�
//	int begin1 = 0, begin2 = 0, index = 0;
//	//���кϲ������¿ռ�
//	while (str1[begin1] && str2[begin2])
//	{
//		if (islower(str1[begin1]))
//			str1[begin1] = toupper(str1[begin1]);
//		if (islower(str2[begin2]))
//			str2[begin2] = toupper(str2[begin2]);
//		merge[index++] = str1[begin1++];
//		merge[index++] = str2[begin2++];
//	}
//	//��Ϊ�����κϲ������ܻ���ĳ���ַ���δ�ϲ��꣬���������ʴ˴���
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
//	//���ϲ��ַ��������ֹ�ַ�
//	merge[index] = '\0';
//	return merge;
//}
//	/*��д������ƺ�����ʵ�ְ�����������ַ�������ϲ����ϲ�ʱ����Сд��ĸ�ĳɴ�д��*/
//int main()
//{
//	char* arr1 = (char*)malloc(sizeof(char) * 100);
//	char* arr2 = (char*)malloc(sizeof(char) * 100);
//	if(!arr1 || !arr2)
//	{
//		printf("����ռ�ʧ�ܣ�\n");
//		exit(-1);
//  }
//	scanf("%s%s", arr1, arr2);
//	char* merge = merge_string(arr1, arr2);
//	cout << merge << endl;
//  free(arr1);free(arr2);free(merge);
//	return 0;
//}

/*��д�����������������
����һ����һ���ı��ļ����ܳ������ļ���
���������������ļ����ܳ�ԭ���ļ������ܵ��㷨��
(1)ÿ���ֽڸ���λ�͵���λ�Ե���(2)ÿ���ֽڸ߶�λ�͵�2λ�Ե���(3)�ֽ����򡣣��ӡ������㷨����λ������*/
//char fun1(char ch)
//{
//	//ch&0xf   ȡ��4λ
//	//(ch&0xf)<<4 ����4λ�Ƶ���4λ
//	//(ch&0xf0) ȡ��4λ
//	//(ch&0xf0)>>4 ����4λ�Ƶ���4λ
//	char tmp = ((ch & 0xf) << 4) | ((ch & 0xf0)>>4);
//	return tmp;
//}
//char fun2(char ch)
//{
//	//������㷨1������ͬ��������Ҫע�⵱�ߵͶ�λ���жԵ����м���λҪ��ԭ��һ��
//	char tmp = ((ch & 0x3) << 6) | ((ch & 0xC0) >> 6) | (ch & 0x3C);
//	return tmp;
//}
//char fun3(char ch)
//{
//	char tmp;
//	//ͨ������ѭ������������ÿ��ȡ�Ķ�����λ
//	for (int j = 7,i = 7; i >= 1; i -= 2, j -= 1)
//	{
//		//ÿ�ν�����β����λ�����󣬳��˽��������˸ı�֮�⣬�����м�Ķ�����λҪ��ԭ��һ��
//		//�������ö�ٷ���������
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
//	//��Ҫ�����ν��м���
//	for (int i = 0; i < len; i++)
//	{
//		text[i] = fun1(text[i]);
//		text[i] = fun2(text[i]);
//		text[i] = fun3(text[i]);
//	}
//}
//void decrypt(char text[],int len)
//{
//	//���Ž��ܼ���
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
//	//���ļ�
//	FILE* pfile = fopen("encrypt.txt", "wb");
//	//��������ı����ݽ��м���
//	encrypt(text,len);
//	//������ļ�
//	fwrite(text, sizeof(char), sizeof(text), pfile);
//	fclose(pfile);
//	printf("���ܺ�����ݣ�\n%s\n",text);
//	decrypt(text,len);
//	//�ɽ��ļ�����ȡ�����н���
//	//pfile = fopen("encrypt.txt", "wb");
//	//fwrite(text, sizeof(char), sizeof(text), pfile);
//	//fclose(pfile);
//	printf("���ܺ�����ݣ�\n%s\n", text);
//	return 0;
//}

/*�ˡ�һ�������רҵ�Ĵ�ѧ����׼����Ա����
ÿ���ͷ��80-120�������ģ�⣩��ÿ�쳤��0-80�������ģ�⣩��
���������ѧʱ��ͷ��12���������Ƴ��򣬼������4��󣬱�ҵʱͷ�ϵ�ͷ��������*/
//#define HAIR 120000
//int last_hair()
//{
//	int hair = HAIR;
//	//���Լ���һ��Ϊ365�죬������Ϊ1460��
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