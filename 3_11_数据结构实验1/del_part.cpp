#define _CRT_SECURE_NO_WARNINGS 1

#include"main.h"
//将删除功能进行统一分配
void delete_all(const char* fileName) {
	if (!strcmp(fileName, "firefox.txt"))
		delete_non_visualization(fileName);
	else {
		delete_non_visualization(fileName);
		del_funtion("final_1.txt");
		del_semicolon("final_2.txt");
		blank_line("final_3.txt");
	}
}
//彻底删除<>扩起来的内容
void delete_non_visualization(const char* fileName)
{
	bool flag = false;
	int tmp;
	FILE* fp1 = fopen(fileName, "r");
	FILE* fp2 = fopen("final_1.txt", "w");
	while ((tmp = fgetc(fp1)) != EOF)
	{
		if (tmp == '<')flag = true;
		if (tmp == '>')flag = false;
		if (!flag && tmp != '>')
			fputc(tmp, fp2);
	}
	if (!strcmp(fileName, "firefox.txt")) {
		cout << "删除成功！" << endl;
		cout << "删除超链接后的文件已保存至final_1.txt中" << endl;
	}
	fclose(fp1);
	fclose(fp2);
}
//删除一行内的超链接（已无用）
void hyperlink_delete(const char* fileName)
{
	FILE* pFile1 = fopen(fileName, "r");
	//将修改的内容直接重定向到另一个文件中
	FILE* pFile2 = fopen("_final.txt", "w");
	if (pFile1 == NULL)
	{
		perror("Error opening file");
		return;
	}
	//获取文件的总字节大小
	fseek(pFile1, 0, SEEK_END);
	int fileSize = ftell(pFile1);
	fseek(pFile1, 0, SEEK_SET);
	//开辟足够的空间（之前老是越界，烦死了，摆烂了，你还能越过整个文件？？）
	char* tmp = (char*)malloc(sizeof(char) * fileSize);
	while (fgets(tmp, fileSize, pFile1) != NULL)
	{
		int begin = 0, end = 0;
		if (tmp)
		{
			//超链接的标志即<...>两个尖括号括起来的部分，因此遍历一遍找到起始部分进行覆盖删除即可
			//但是该文件里面大部分都是一行一个超链接，但有各别例外，故做下面的特判进行删除
			while (tmp[begin] != '\n' && tmp[begin] != '\0' && tmp[begin] != '<')
				begin++;
			while (tmp[end] != '\n' && tmp[end] != '\0' && tmp[end] != '>')
				end++;
			int _end = end, _begin = begin;
			//当>右尖括号后面不是换行符即说明该行有不止一个超链接（至少没有到结尾）
			while (tmp[++_end] != '\n' && tmp[_end] != '\0')
			{
				//得到右尖括号后面还有多少个字节内容
				int len = (int)strlen(tmp + _end);
				//将它们往前移动覆盖掉原来的超链接所在的字节内容
				//将换行符以及终止符也拷贝到前面，便于后面从头再次遍历到已经覆盖的字符串结尾
				for (int i = 0; i <= len; i++)
					tmp[_begin++] = tmp[_end++];
				//再从头开始找后面是否还有<...>超链接
				end = 0, begin = 0;
				while (tmp[end] != '\0' && tmp[end] != '>' && tmp[end + 1] != '\n')
					end++;
				while (tmp[begin] != '\0' && tmp[begin] != '<' && tmp[begin + 1] != '\n')
					begin++;
				//如果有超链接，那begin的位置和end位置不可能重合，反之就是没有超链接
				if (begin == end)
					break;
				//子变量为了让原来的变量始终对齐着尖括号，让子变量进行移动覆盖
				_end = end; _begin = begin;
			}
			//如果其右尖括号后面是换行符则说明该行没有超链接了
			if (tmp[end + 1] == '\n')
			{
				//该特判是为了上面有一行有多条超链接的情况
				if (tmp[begin + 1] == '\n')
					tmp[begin + 1] = '\0';
				else
					tmp[begin] = '\0';
			}
			fputs(tmp, pFile2);
		}
	}

	cout << "删除成功！" << endl;
	cout << "删除超链接后的文件已保存至final.txt中" << endl;
	fclose(pFile1);
	fclose(pFile2);
}
//删除函数
void del_funtion(const char* fileName) {
	FILE* pFile1 = fopen(fileName, "r");
	//将修改的内容直接重定向到另一个文件中
	FILE* pFile2 = fopen("final_2.txt", "w");
	if (pFile1 == NULL)
	{
		perror("Error opening file");
		return;
	}
	//获取文件的总字节大小
	fseek(pFile1, 0, SEEK_END);
	int fileSize = ftell(pFile1);
	fseek(pFile1, 0, SEEK_SET);
	//开辟足够空间（其实也没必要，但我就开）
	char* tmp = (char*)malloc(sizeof(char) * fileSize);
	//判定函数体标志
	bool flag = false;
	while (fgets(tmp, fileSize, pFile1) != NULL)
	{
		int len = (int)strlen(tmp);
		for (int i = 0; i < len; i++) {
			if (tmp[i] == '{') {
				flag = true;
			}
		}
		if (flag) {
			for (int i = 0; i < len; i++) {
				if (tmp[i] == '}') {
					flag = false;
				}
			}
		}
		if (!flag) {
			fputs(tmp, pFile2);
		}
	}
	fclose(pFile1);
	fclose(pFile2);
}
//删除分号（代码语句）
void del_semicolon(const char* fileName) {
	FILE* pFile1 = fopen(fileName, "r");
	//将修改的内容直接重定向到另一个文件中
	FILE* pFile2 = fopen("final_3.txt", "w");
	if (pFile1 == NULL)
	{
		perror("Error opening file");
		return;
	}
	//获取文件的总字节大小
	fseek(pFile1, 0, SEEK_END);
	int fileSize = ftell(pFile1);
	fseek(pFile1, 0, SEEK_SET);
	//开辟足够空间（其实也没必要，但我就开）
	char* tmp = (char*)malloc(sizeof(char) * fileSize);
	//判定是否为分号的标志
	bool flag = false;
	while (fgets(tmp, fileSize, pFile1) != NULL)
	{
		int len = (int)strlen(tmp);
		for (int i = 0; i < len; i++) {
			if (tmp[i] == ';' || tmp[i] == '}' || tmp[i] == ']' || tmp[i] == '/') {
				flag = true;
			}
		}
		if (flag) {
			flag = false;
			for (int i = 0; i < len; i++) {
				if (tmp[i] == ';' || tmp[i] == '}' || tmp[i] == ']' || tmp[i] == '/') {
					flag = true;
				}
			}
		}
		if (!flag) {
			fputs(tmp, pFile2);
		}
	}
	fclose(pFile1);
	fclose(pFile2);
}
//删除空行（删除后空行太多了！）
void blank_line(const char* fileName) {
	FILE* pFile1 = fopen(fileName, "r");
	//将修改的内容直接重定向到另一个文件中
	FILE* pFile2 = fopen("chrome_final.txt", "w");
	if (pFile1 == NULL)
	{
		perror("Error opening file");
		return;
	}
	//获取文件的总字节大小
	fseek(pFile1, 0, SEEK_END);
	int fileSize = ftell(pFile1);
	fseek(pFile1, 0, SEEK_SET);
	//开辟足够空间（其实也没必要，但我就开）
	char* tmp = (char*)malloc(sizeof(char) * fileSize);
	//判定是否为分号的标志
	bool flag = false;
	int index = 0;
	while (fgets(tmp, fileSize, pFile1) != NULL)
	{
		int len = (int)strlen(tmp);
		for (int i = 0; i < len; i++) {
			if ((tmp[i] >= 'a' && tmp[i] <= 'z') || (tmp[i] >= '0' && tmp[i] <= '9') || (tmp[i] >= 'A' && tmp[i] <= 'Z')) {
				flag = true;
			}
		}
		if (flag) {
			flag = false;
			for (int i = 0; i < len; i++) {
				if ((tmp[i] >= 'a' && tmp[i] <= 'z') || (tmp[i] >= '0' && tmp[i] <= '9') || (tmp[i] >= 'A' && tmp[i] <= 'Z')) {
					flag = true;
				}
			}
		}
		if (flag)
			fputs(tmp, pFile2);
	}
	cout << "删除成功！" << endl;
	cout << "删除超链接后的文件已保存至chrome_final.txt中" << endl;
	fclose(pFile1);
	fclose(pFile2);
}