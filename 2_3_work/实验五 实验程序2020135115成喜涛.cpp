#define _CRT_SECURE_NO_WARNINGS 1

#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<stack>
#include<map>
using namespace std;
/*һ����д������ƺ�����ʵ�ְ�����������ַ�������ϲ����ϲ�ʱ����Сд��ĸ�ĳɴ�д��
��������һ���ɵ�����ɵ��ַ������ֱ���ƺ�����������´���
��1����ͳ���ַ��ĸ�������2����ͳ���ַ����е��ʵ�������
��3������5������һ�У�������е��ʣ���4����ͳ�Ƶ���ƽ���ַ�����
��5������������������ʣ��������ǣ�I am a student���student a am I��
�������֤���봦����1����ƺ����ж�һ�����֤���룬�Ƿ���ϱ�׼��
��2������һ�����֤���룺�Ƿ�Ϸ����������ڡ��Ա����Ϣ��
��3����ƺ�������һ��15λ���Ϻ��룬ת����18λ���º��롣���֤ת��������������
�ġ���Ʒ�������֤C�����У�������������ʱ��������ջ��˳�򡣣��������������������ӣ�
�塢��Ʒ�������֤C�����У���ָ������Ĵ洢�ռ��������޹أ�ָ������㿴���͡��Ľ��ۡ�(�����������������������)*/

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

/*��������һ���ɵ�����ɵ��ַ������ֱ���ƺ�����������´���
��1����ͳ���ַ��ĸ�������2����ͳ���ַ����е��ʵ�������
��3������5������һ�У�������е��ʣ���4����ͳ�Ƶ���ƽ���ַ�����
��5������������������ʣ��������ǣ�I am a student���student a am I*/
//ͳ���ַ��ĸ���
//int statistics_char(char* text_string)
//{
//	int count = 0, index = 0;
//	//���μ���ֱ����ֹ�ַ�����
//	while (text_string[index] != '\0')
//	{
//		count++;
//		index++;
//	}
//	return count;
//}
////ͳ���ַ����е��ʵ�����
//int statistics_word(char* text_string)
//{
//	int len = statistics_char(text_string);
//	int count = 0, index = 0, flag = 0;
//	while (text_string[index] != '\0')
//	{
//		//��ǰ�ַ���Ϊ�ո���˵����Ϊ���ʣ���ָ�������ߣ���flag��Ϊ1
//		while (text_string[index] != ' ' && text_string[index])
//		{
//			index++;
//			flag = 1;
//		}
//		//�ߵ���˵���Ѿ������ո��ˣ�Ҳ����˵һ�����ʽ����ˣ���ʱcount����
//		if(flag) count++;
//		//������ָ������ߣ�����flag��Ϊ0���������Ƿ�ֹ���������������ո�count����++
//		if(text_string[index])
//			index++; flag = 0;
//	}
//	return count;
//}
////���������һ�У�������е���
//void m_print(char* text_string)
//{
//	int len = statistics_char(text_string);
//	int count = 0, index = 0, flag = 0, count_newline = 0;
//	while (text_string[index])
//	{
//		int tmp = index;
//		//��ǰ�ַ���Ϊ�ո���˵����Ϊ���ʣ���ָ�������ߣ���flag��Ϊ1
//		while (text_string[index] != ' ' && text_string[index])
//		{
//			index++;
//			flag = 1;
//		}
//		//�ߵ���˵���Ѿ������ո��ˣ�Ҳ����˵һ�����ʽ����ˣ���ʱ����õ���
//		if (flag)
//		{
//			while (tmp < index)
//			{
//				printf("%c", text_string[tmp]);
//				tmp++;
//			}
//			printf(" ");
//			count_newline++;
//			if (!(count_newline % 5)) printf("\n");
//		}
//		//������ָ������ߣ�����flag��Ϊ0���������Ƿ�ֹ���������������ո�count����++
//		if (text_string[index])
//			index++; flag = 0;
//	}
//}
////ͳ�Ƶ���ƽ���ַ���
//int statistics_ave_char(char* text_string)
//{
//	return statistics_char(text_string) / statistics_word(text_string);
//}
////���������������
//void reverse_output(char* text_string)
//{
//	//����ջ��ŵ����±���Ϣ
//	stack<int> st;
//	int len = statistics_char(text_string);
//	int count = 0, index = 0, flag = 0, word_index = 0;
//	while (text_string[index])
//	{
//		int tmp = index;
//		//��ǰ�ַ���Ϊ�ո���˵����Ϊ���ʣ���ָ�������ߣ���flag��Ϊ1
//		while (text_string[index] != ' ' && text_string[index])
//		{
//			index++;
//			flag = 1;
//		}
//		//�ߵ���˵���Ѿ������ո��ˣ�Ҳ����˵һ�����ʽ����ˣ���ʱ����õ��ʵ���β�±굽ջ��
//		if (flag)
//		{
//			st.push(index - 1);
//			st.push(tmp);
//		}
//		//������ָ������ߣ�����flag��Ϊ0���������Ƿ�ֹ���������������ո�count����++
//		if (text_string[index])
//			index++; flag = 0;
//	}
//	//���ʱ�����Ϻ�ʼ���
//	//ÿ��ȡ����ջ�������ݣ���һ�����ʵ���β�±꣩�����������
//	while (!st.empty())
//	{
//		int first = st.top();
//		st.pop();
//		int last = st.top();
//		st.pop();
//		while (first <= last)
//		{
//			printf("%c", text_string[first]);
//			first++;
//		}
//		printf(" ");
//	}
//}
//int main()
//{
//	char* text_string = (char*)malloc(sizeof(char) * 100);
//	if(!text_string)
//	{
//		printf("����ռ�ʧ�ܣ�\n");
//		exit(-1);
//  }
//	scanf("%[^\n]%*c", text_string);
//	//ͳ���ַ��ĸ���
//	int len = statistics_char(text_string);
//	printf("���ַ������ַ�����Ϊ��%d\n", len);
//	//ͳ���ַ����е��ʵ�����
//	int word_num = statistics_word(text_string);
//	printf("���ַ����ĵ��ʸ���Ϊ��%d\n", word_num);
//	//���������һ�У�������е���
//	m_print(text_string);
//	printf("\n");
//	//ͳ�Ƶ���ƽ���ַ���
//	int ave_char = statistics_ave_char(text_string);
//	printf("���ַ����ĵ��ʵ�ƽ���ַ�����Ϊ��%d\n", ave_char);
//	//���������������
//	reverse_output(text_string);
//	free(text_string);
//	return 0;
//}

/*�������֤���봦��
��1����ƺ����ж�һ�����֤���룬�Ƿ���ϱ�׼��
��2������һ�����֤���룺�Ƿ�Ϸ����������ڡ��Ա����Ϣ��
��3����ƺ�������һ��15λ���Ϻ��룬ת����18λ���º��롣���֤ת��������������*/
//bool judge(char ID[])
//{
//	int sum = 0;
//	int a[17] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };
//	char b[11] = { '1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2' };
//	for (int i = 0; i < 17; i++)
//		sum += a[i] * (ID[i] - '0');
//	sum %= 11;
//	for (int i = 0; i < 11; i++)
//		if (sum == i)
//			if (b[i] == ID[17]) return true;
//	return false;
//}
//void analysis(char* ID)
//{
//	printf("\n������ݣ�\n");
//	for (int i = 6; i <= 9; i++)
//		printf("%c", ID[i]);
//	printf("\n�����·ݣ�\n");
//	for (int i = 10; i <= 11; i++)
//		printf("%c", ID[i]);
//	printf("\n�����գ�\n");
//	for (int i = 12; i <= 13; i++)
//		printf("%c", ID[i]);
//	if (!((ID[16] - '0') % 2))
//		printf("\n�Ա�Ů\n");
//	else
//		printf("\n�Ա���\n");
//}
//void change_new(char* ID)
//{
//	//�ɵĵ�һ�����֤����15λ��ת��Ϊ�µĵڶ������֤��18λ����һ������ǣ�
//	//��һ������ԭʮ��λ�����֤�ĵ���λ���������19 ���������֤���뼴Ϊʮ��λ����
//	//�ڶ��������չ��ҹ涨��ͳһ��ʽ�������ʮ��λ������ΪУ������ڵڶ������֤��β�š�
//	//�Ƚ�����λ��������ݶ�����Ų��
//	for (int i = 14; i > 6; i--)
//		ID[i + 2] = ID[i];
//	//��������
//	ID[6] = '1'; ID[7] = '9';
//	//����У��λ
//	int sum = 0;
//	int a[17] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };
//	char b[11] = { '1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2' };
//	for (int i = 0; i < 17; i++)
//		sum += a[i] * (ID[i] - '0');
//	sum %= 11;
//	for (int i = 0; i < 11; i++)
//		if (sum == i)
//			ID[17] = b[i];
//}
//int main()
//{
//	char ID[19] = { 0 };
//	scanf("%s", ID);
//	change_new(ID);
//	printf(ID);
//	bool ret = judge(ID);
//	if (ret)
//	{
//		printf("���ϱ�׼\n");
//		analysis(ID);
//	}
//	else 
//		printf("�����ϱ�׼\n");
//	return 0;
//}

/*�ġ���Ʒ�������֤C�����У�������������ʱ��������ջ��˳�򡣣��������������������ӣ�*/
//����˵���۰ɣ�������������ջ˳��Ϊ��������
//�������ù����У���һ����ջ���ǣ��������еģ����ô�����һ��ָ�����������������һ����ִ����䣩�ĵ�ַ��
//Ȼ���Ǻ����ĸ������������ڴ����C/C++�������У��ں������õĹ����У������Ĳ���������������ջ�ģ�
//Ȼ���Ǻ����ڲ��ľֲ�����������Ҫע��static���εľֲ������ǲ���ջ�ģ���
//�ں������ý������������н������󣬾ֲ��������ȳ�ջ��Ȼ���ǲ��������ջ��ָ��ָ���ʼ���ָ���ַ
//
//Ȼ����Ϊʲô�������������ջ˳�򣿼�����ʵ��
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
���н����
w = 40 at 000000DE018FF8F8
x = 10 at 000000DE018FF8E0
y = 20 at 000000DE018FF8E8
z = 30 at 000000DE018FF8F0
a = 1 at 000000DE018FF7A4
b = 2 at 000000DE018FF7C4
c = 3 at 000000DE018FF7E4
3 2 1
*/
//����������Ҫ֪����C����ջ��Ϊ�ߵ�ַ��ջ��Ϊ�͵�ַ�����ɸߵ�ַ��͵�ַ��չ��������չ��
//��������ʵ������˵������������ջ˳���ȷ�Ǵ�������,���β�����ջ���ֲ���������ջ�ġ�
//�ɵ���Ϊʲô�أ�
//����һֱЩ���ϵ�֪��������ջ˳���Ǻ;��������ʵ����صġ�
//���磬Pascal�����в������Ǵ�������ջ��
//��Ȼ���ַ�ʽ�����ԣ�ΪʲôC����Ҫѡ����������أ�
//��һ�����֣�Pascal���Բ�֧�ֿɱ䳤��������C����֧��������ɫ���������ԭ��ʹ��C���Ժ���������ջ˳��Ϊ��������
//���������������ջ��ʽ�����ҵ���һ��������λ��,���ڿɱ������ʵ�ֺ�ʹ��
//ͨ��ջ�ѷ�����֪(ջ������չ����������չ)���������ҵ���ջ��ʽ����ǰ��Ĳ�����ѹ��ջ�ס�
//����֪�������������������޷�ͨ��ջָ������λ���������ߵĲ�����
//�����ͱ������߲����ĸ�����ȷ�������úͶ�̬���������ķ����෴��
//��ˣ�C���Ժ����������������������ջ˳����Ҫԭ����Ϊ��֧�ֿɱ䳤������ʽ��
//���仰˵�������֧�������ɫ��C������ȫ��Pascalһ���������������ҵĲ�����ջ��ʽ��

/*�塢��Ʒ�������֤C�����У���ָ������Ĵ洢�ռ��������޹أ�ָ������㿴���͡��Ľ��ۡ�(�����������������������)*/
//int main()
//{
//    //����鿴��ͬ���͵�ָ���С
//    printf("%d %d %d %d\n",(int)sizeof(int*), (int)sizeof(char*), (int)sizeof(float*),(int)sizeof(double*));
//    //���н��Ϊ 4 4 4 4���ʿ�ָ֪������Ĵ洢�ռ��������޹�
//    //ԭ�������Ǻ������͵����ݣ��䶼�Ǵ洢���ڴ��ϵģ����ڴ�Ŀռ������ֽ�Ϊ��С��λ���ֵ�
//    // ÿһ���ֽڶ������Ӧ�ı��룬��32λ�����£�����2^32���ڴ��ţ��ʴ�ÿ����ŵĳ��ȶ�Ϊ32������λ���ĸ��ֽ�
//    // ָ������洢�ļ��Ƕ�Ӧ���ݵ����ֽڵĵ�ַ���õ�ַ�ı�Ź̶�Ϊ4���ֽ�
//    // �ʴ�ָ������Ĵ洢�ռ�ֻҪ�����������ַ�ı�ż��ɣ�Ҳ����4���ֽڣ���64λ��������Ϊ8���ֽڣ�
//    //��������
//    int arr[] = { 1,2,3,4,5 };
//    //��Ԫ�صĵ�ַӦ������ָ��洢���������ǿת��������ָ֤������㿴���͵Ľ���
//    short* p = (short*)arr;
//    int i = 0;
//    //ÿ�μ�1��һ�����ĴΣ���Ϊ����ָ�룬�������ʮ�����ֽڣ����Ϊ0 0 0 0 5
//    for (i = 0; i < 4; i++)
//        *(p + i) = 0;
//    //��Ϊ�Ƕ�����ָ�룬ÿ��ֻ�ܷ��������ֽڣ�������˰˸��ֽڣ��������Ϊ0 0 3 4 5
//    for (i = 0; i < 5; i++)
//        printf("%d ", arr[i]);
//    return 0;
//}