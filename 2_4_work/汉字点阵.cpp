#define _CRT_SECURE_NO_WARNINGS 1

//#include<stdio.h>
//#include<stdlib.h>
//#include<conio.h>
///*在该程序中，为了能使名字横向输出，所以在原函数的基础上，
//  每一个步骤都增加计算了四个变量，再把名字中的三个汉字的32字节分别存于三个数组中，
//  在最后的输出中，以整体形式一起输出（只调用依次显示或特显函数）*/
//
//void fnDisplayHz_heng(char* str1); //横向输出 
//void fnDisplayHz_jing(char* str1);   //镜像显示 
//void fnDisplayHz_xie(char* str1);   //按斜率倾斜显示（斜率固定45度） 
//void fnDisplayHz_da(char* str1);     //按倍数放大显示（放大倍数默认为2，可通过改变全局变量times的值改变放大倍数）
//
//int times = 2;
//
//int main(int argc, char* argv[])
//{
//	char word1[7], word2[7], word3[7], word4[7];
//	printf("输入要生成字模的名字(三个):");
//	scanf("%s", word1);
//	fnDisplayHz_heng(word1);
//	printf("\n\n");
//	printf("输入要生成字模的名字(三个):");
//	scanf("%s", word2);
//	fnDisplayHz_xie(word2);
//	printf("\n\n");
//	printf("输入要生成字模的名字(三个):");
//	scanf("%s", word3);
//	fnDisplayHz_jing(word3);
//	printf("\n\n");
//	printf("输入要生成字模的名字(三个):");
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
//	m3 = (long)(y - 1) * 94 + (z - 1);       //分别算出三个汉字在HZK16中的绝对偏移位置
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
//	m3 = (long)(y - 1) * 94 + (z - 1);			//分别算出三个汉字在HZK16中的绝对偏移位置
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
//	for (i = 31; i >= 0; i--) {			//令i= 31进入循环，使汉字倒置显示
//		j = i - 1;
//		for (k = 7; k >= 0; k--) {				//令k= 7进入循环，使汉字左右对调
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
//	m3 = (long)(y - 1) * 94 + (z - 1);      //分别算出三个汉字在HZK16中的绝对偏移位置
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
//		for (a = l; a <= 15; a++) {		//添加变量a，通过循环使原本该显示*号的位置的地方能倾斜偏移到正确位置
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
//	m3 = (long)(y - 1) * 94 + (z - 1);       //分别算出三个汉字在HZK16中的绝对偏移位置
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
//		for (int a = times; a >= 1; a--) {			//通过变量a，使原本在该显示*号的位置能够按倍数扩大 
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