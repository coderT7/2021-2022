#define _CRT_SECURE_NO_WARNINGS 1

//#include<stdio.h>
//#include<stdlib.h>
//#include<conio.h>
///*�ڸó����У�Ϊ����ʹ���ֺ��������������ԭ�����Ļ����ϣ�
//  ÿһ�����趼���Ӽ������ĸ��������ٰ������е��������ֵ�32�ֽڷֱ�������������У�
//  ����������У���������ʽһ�������ֻ����������ʾ�����Ժ�����*/
//
//void fnDisplayHz_heng(char* str1); //������� 
//void fnDisplayHz_jing(char* str1);   //������ʾ 
//void fnDisplayHz_xie(char* str1);   //��б����б��ʾ��б�ʹ̶�45�ȣ� 
//void fnDisplayHz_da(char* str1);     //�������Ŵ���ʾ���Ŵ���Ĭ��Ϊ2����ͨ���ı�ȫ�ֱ���times��ֵ�ı�Ŵ�����
//
//int times = 2;
//
//int main(int argc, char* argv[])
//{
//	char word1[7], word2[7], word3[7], word4[7];
//	printf("����Ҫ������ģ������(����):");
//	scanf("%s", word1);
//	fnDisplayHz_heng(word1);
//	printf("\n\n");
//	printf("����Ҫ������ģ������(����):");
//	scanf("%s", word2);
//	fnDisplayHz_xie(word2);
//	printf("\n\n");
//	printf("����Ҫ������ģ������(����):");
//	scanf("%s", word3);
//	fnDisplayHz_jing(word3);
//	printf("\n\n");
//	printf("����Ҫ������ģ������(����):");
//	scanf("%s", word4);
//	fnDisplayHz_da(word4);
//	printf("\n\n");
//
//	return 0;
//}
//void fnDisplayHz_heng(char* str1)
//{
//	unsigned int u, v, w, x, y, z;
//	long m1, m2, m3;
//	int i, j, k;
//	unsigned char  ch1, ch2, ch3, ch4, ch5, ch6;
//	unsigned char buffer32_one[32], buffer32_two[32], buffer32_three[32];
//	FILE* fp1;
//	fp1 = fopen(".\\hzk16", "rb");
//	if (fp1 == NULL) { printf("Error open file!"); return; }
//
//	ch1 = *str1++;
//	ch2 = *str1++;
//	ch3 = *str1++;
//	ch4 = *str1++;
//	ch5 = *str1++;
//	ch6 = *str1++;
//
//	u = ch1 - 160;
//	v = ch2 - 160;
//	w = ch3 - 160;
//	x = ch4 - 160;
//	y = ch5 - 160;
//	z = ch6 - 160;
//
//	m1 = (long)(u - 1) * 94 + (v - 1);
//	m2 = (long)(w - 1) * 94 + (x - 1);
//	m3 = (long)(y - 1) * 94 + (z - 1);       //�ֱ��������������HZK16�еľ���ƫ��λ��
//
//	fseek(fp1, (long)m1 * 32, 0);
//	fread(buffer32_one, 32, 1, fp1);
//
//	fseek(fp1, (long)m2 * 32, 0);
//	fread(buffer32_two, 32, 1, fp1);
//
//	fseek(fp1, (long)m3 * 32, 0);
//	fread(buffer32_three, 32, 1, fp1);
//
//	fclose(fp1);
//	printf("\n");
//	for (i = 0; i <= 31; i++) {
//		for (k = 0; k <= 7; k++) {
//			if (buffer32_one[i] & 128 >> k) printf("* ");
//			else printf("  ");
//		}
//		j = i + 1;
//		for (k = 0; k <= 7; k++) {
//			if (buffer32_one[j] & 128 >> k) printf("* ");
//			else printf("  ");
//		}
//		for (k = 0; k <= 7; k++) {
//			if (buffer32_two[i] & 128 >> k) printf("* ");
//			else printf("  ");
//		}
//		for (k = 0; k <= 7; k++) {
//			if (buffer32_two[j] & 128 >> k) printf("* ");
//			else printf("  ");
//		}
//		for (k = 0; k <= 7; k++) {
//			if (buffer32_three[i] & 128 >> k) printf("* ");
//			else printf("  ");
//		}
//		for (k = 0; k <= 7; k++) {
//			if (buffer32_three[j] & 128 >> k) printf("* ");
//			else printf("  ");
//		}
//		i = j;
//		printf("\n");
//	}
//}
//
//void fnDisplayHz_jing(char* str1)
//{
//	unsigned int u, v, w, x, y, z;
//	long m1, m2, m3;
//	int i, j, k;
//	unsigned char  ch1, ch2, ch3, ch4, ch5, ch6;
//	unsigned char buffer32_one[32], buffer32_two[32], buffer32_three[32];
//	FILE* fp1;
//	fp1 = fopen(".\\hzk16", "rb");
//	if (fp1 == NULL) { printf("Error open file!"); return; }
//
//	ch1 = *str1++;
//	ch2 = *str1++;
//	ch3 = *str1++;
//	ch4 = *str1++;
//	ch5 = *str1++;
//	ch6 = *str1++;
//
//	u = ch1 - 160;
//	v = ch2 - 160;
//	w = ch3 - 160;
//	x = ch4 - 160;
//	y = ch5 - 160;
//	z = ch6 - 160;
//
//	m1 = (long)(u - 1) * 94 + (v - 1);
//	m2 = (long)(w - 1) * 94 + (x - 1);
//	m3 = (long)(y - 1) * 94 + (z - 1);			//�ֱ��������������HZK16�еľ���ƫ��λ��
//
//	fseek(fp1, (long)m1 * 32, 0);
//	fread(buffer32_one, 32, 1, fp1);
//
//	fseek(fp1, (long)m2 * 32, 0);
//	fread(buffer32_two, 32, 1, fp1);
//
//	fseek(fp1, (long)m3 * 32, 0);
//	fread(buffer32_three, 32, 1, fp1);
//
//	fclose(fp1);
//	printf("\n");
//
//	for (i = 31; i >= 0; i--) {			//��i= 31����ѭ����ʹ���ֵ�����ʾ
//		j = i - 1;
//		for (k = 7; k >= 0; k--) {				//��k= 7����ѭ����ʹ�������ҶԵ�
//			if (buffer32_one[i] & 128 >> k) printf("* ");
//			else printf("  ");
//		}
//		for (k = 7; k >= 0; k--) {
//			if (buffer32_one[j] & 128 >> k) printf("* ");
//			else printf("  ");
//		}
//		for (k = 7; k >= 0; k--) {
//			if (buffer32_two[i] & 128 >> k) printf("* ");
//			else printf("  ");
//		}
//		for (k = 7; k >= 0; k--) {
//			if (buffer32_two[j] & 128 >> k) printf("* ");
//			else printf("  ");
//		}
//		for (k = 7; k >= 0; k--) {
//			if (buffer32_three[i] & 128 >> k) printf("* ");
//			else printf("  ");
//		}
//		for (k = 7; k >= 0; k--) {
//			if (buffer32_three[j] & 128 >> k) printf("* ");
//			else printf("  ");
//		}
//		i = j;
//		printf("\n");
//	}
//}
//void fnDisplayHz_xie(char* str1)
//{
//	unsigned int u, v, w, x, y, z;
//	long m1, m2, m3;
//	int i, j, k, l;
//	unsigned char  ch1, ch2, ch3, ch4, ch5, ch6;
//	unsigned char buffer32_one[32], buffer32_two[32], buffer32_three[32];
//	FILE* fp1;
//	fp1 = fopen(".\\hzk16", "rb");
//	if (fp1 == NULL) { printf("Error open file!"); return; }
//
//	ch1 = *str1++;
//	ch2 = *str1++;
//	ch3 = *str1++;
//	ch4 = *str1++;
//	ch5 = *str1++;
//	ch6 = *str1++;
//
//	u = ch1 - 160;
//	v = ch2 - 160;
//	w = ch3 - 160;
//	x = ch4 - 160;
//	y = ch5 - 160;
//	z = ch6 - 160;
//
//	m1 = (long)(u - 1) * 94 + (v - 1);
//	m2 = (long)(w - 1) * 94 + (x - 1);
//	m3 = (long)(y - 1) * 94 + (z - 1);      //�ֱ��������������HZK16�еľ���ƫ��λ��
//
//	fseek(fp1, (long)m1 * 32, 0);
//	fread(buffer32_one, 32, 1, fp1);
//
//	fseek(fp1, (long)m2 * 32, 0);
//	fread(buffer32_two, 32, 1, fp1);
//
//	fseek(fp1, (long)m3 * 32, 0);
//	fread(buffer32_three, 32, 1, fp1);
//
//	fclose(fp1);
//	printf("\n");
//
//	l = 0;
//	for (i = 0; i <= 31; i++) {
//		int a = l;
//		for (a = l; a <= 15; a++) {		//��ӱ���a��ͨ��ѭ��ʹԭ������ʾ*�ŵ�λ�õĵط�����бƫ�Ƶ���ȷλ��
//			printf(" ");
//		}
//		for (k = 0; k <= 7; k++) {
//			if (buffer32_one[i] & 128 >> k) printf("* ");
//			else printf("  ");
//		}
//		j = i + 1;
//		for (k = 0; k <= 7; k++) {
//			if (buffer32_one[j] & 128 >> k) printf("* ");
//			else printf("  ");
//		}
//
//		for (k = 0; k <= 7; k++) {
//			if (buffer32_two[i] & 128 >> k) printf("* ");
//			else printf("  ");
//		}
//		j = i + 1;
//		for (k = 0; k <= 7; k++) {
//			if (buffer32_two[j] & 128 >> k) printf("* ");
//			else printf("  ");
//		}
//		for (k = 0; k <= 7; k++) {
//			if (buffer32_three[i] & 128 >> k) printf("* ");
//			else printf("  ");
//		}
//		j = i + 1;
//		for (k = 0; k <= 7; k++) {
//			if (buffer32_three[j] & 128 >> k) printf("* ");
//			else printf("  ");
//		}
//		i = j;
//		l++;
//		printf("\n");
//	}
//}
//void fnDisplayHz_da(char* str1)
//{
//	unsigned int u, v, w, x, y, z;
//	long m1, m2, m3;
//	int i, j, k, l;
//	unsigned char  ch1, ch2, ch3, ch4, ch5, ch6;
//	unsigned char buffer32_one[32], buffer32_two[32], buffer32_three[32];
//	FILE* fp1;
//	fp1 = fopen(".\\hzk16", "rb");
//	if (fp1 == NULL) { printf("Error open file!"); return; }
//
//	ch1 = *str1++;
//	ch2 = *str1++;
//	ch3 = *str1++;
//	ch4 = *str1++;
//	ch5 = *str1++;
//	ch6 = *str1++;
//
//	u = ch1 - 160;
//	v = ch2 - 160;
//	w = ch3 - 160;
//	x = ch4 - 160;
//	y = ch5 - 160;
//	z = ch6 - 160;
//
//	m1 = (long)(u - 1) * 94 + (v - 1);
//	m2 = (long)(w - 1) * 94 + (x - 1);
//	m3 = (long)(y - 1) * 94 + (z - 1);       //�ֱ��������������HZK16�еľ���ƫ��λ��
//
//	fseek(fp1, (long)m1 * 32, 0);
//	fread(buffer32_one, 32, 1, fp1);
//
//	fseek(fp1, (long)m2 * 32, 0);
//	fread(buffer32_two, 32, 1, fp1);
//
//	fseek(fp1, (long)m3 * 32, 0);
//	fread(buffer32_three, 32, 1, fp1);
//
//	fclose(fp1);
//	printf("\n");
//
//	for (i = 0; i <= 31; i++) {
//		for (int a = times; a >= 1; a--) {			//ͨ������a��ʹԭ���ڸ���ʾ*�ŵ�λ���ܹ����������� 
//			for (k = 0; k <= 7; k++) {
//				if (buffer32_one[i] & 128 >> k) {
//					for (l = 1; l <= times; l++)
//						printf("* ");
//				}
//				else {
//					for (l = 1; l <= times; l++)
//						printf("  ");
//				}
//			}
//			j = i + 1;
//			for (k = 0; k <= 7; k++) {
//				if (buffer32_one[j] & 128 >> k) {
//					for (l = 1; l <= times; l++)
//						printf("* ");
//				}
//				else
//				{
//					for (l = 1; l <= times; l++)
//						printf("  ");
//				}
//			}
//			for (k = 0; k <= 7; k++) {
//				if (buffer32_two[i] & 128 >> k) {
//					for (l = 1; l <= times; l++)
//						printf("* ");
//				}
//				else {
//					for (l = 1; l <= times; l++)
//						printf("  ");
//				}
//			}
//			j = i + 1;
//			for (k = 0; k <= 7; k++) {
//				if (buffer32_two[j] & 128 >> k) {
//					for (l = 1; l <= times; l++)
//						printf("* ");
//				}
//				else
//				{
//					for (l = 1; l <= times; l++)
//						printf("  ");
//				}
//			}
//			for (k = 0; k <= 7; k++) {
//				if (buffer32_three[i] & 128 >> k) {
//					for (l = 1; l <= times; l++)
//						printf("* ");
//				}
//				else {
//					for (l = 1; l <= times; l++)
//						printf("  ");
//				}
//			}
//			j = i + 1;
//			for (k = 0; k <= 7; k++) {
//				if (buffer32_three[j] & 128 >> k) {
//					for (l = 1; l <= times; l++)
//						printf("* ");
//				}
//				else
//				{
//					for (l = 1; l <= times; l++)
//						printf("  ");
//				}
//			}
//			printf("\n");
//		}
//		i = j;
//	}
//}