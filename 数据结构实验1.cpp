#define _CRT_SECURE_NO_WARNINGS 1

#include<cstdio>
#include<iostream>
#include<cstring>
#include<unordered_map>
#include<string>
using namespace std;
unordered_map<int, string> wordMap;
int key = 0;
void del_duplicate_word(unordered_map<int, string>& wordSet)
{
	//FILE* pFile = fopen("delWord.txt", "a");
	//char tmp[50];
	//unordered_map<int, string>::iterator hash;
	//for (auto i : wordMap)
	//{
	//	strcpy(tmp, i.second.c_str());
	//	fputs(tmp, pFile);
	//}
	//fclose(pFile);
}

static int statistics_word(char* text_string)
{
	FILE* pFile = fopen("word.txt", "a");
	

	//int len = strlen(text_string);
	
	int count = 0, index = 0, flag = 0;
	string tmp;
	while (text_string[index] != '\n')
	{
		//当前字符不为空格则说明其为单词，则指针往后走，且flag置为1
		while (text_string[index] != ' ' && text_string[index] && (text_string[index] >= 'a'
			&& text_string[index] <='z') || (text_string[index] >= 'A' && text_string[index] <= 'Z'))
		{
			tmp += text_string[index];
			fputc(text_string[index], pFile);
			index++;
			flag = 1;
		}
		//走到这说明已经碰到空格了，也就是说一个单词结束了，此时count计数
		if (flag)
		{
			count++;
			fputc(' ', pFile);
		}
		//计数后指针继续走，并将flag置为0，这样做是防止如果连续遇到多个空格，count无脑++
		if (text_string[index])
			index++;
		flag = 0;
		//进行遍历哈希表时单词的计数
		int wordNum = 0;
		//插入单词
		wordMap.insert(make_pair(key++, tmp));
		unordered_map<int, string>::iterator hash;
		for (auto i : wordMap)
		{
			if (i.second == tmp)
				wordNum++;
			if (wordNum > 1)
				wordMap.erase(i.first);
		}
	}

	fclose(pFile);
	//返回改行字符串里有几个单词
	return count;
}

int get_word_num(const char* fileName)
{
	int sum = 0;
	FILE* pFile = fopen(fileName, "r");
	if (pFile == NULL)
	{
		perror("Error opening file");
		exit(-1);
	}
	//获取文件的总字节大小
	fseek(pFile, 0, SEEK_END);
	int fileSize = ftell(pFile);
	fseek(pFile, 0, SEEK_SET);
	//开辟足够的空间（之前老是越界，烦死了，摆烂了，你还能越过整个文件？？）
	char* tmp = (char*)malloc(sizeof(char) * fileSize);

	while (fgets(tmp, fileSize, pFile) != NULL)
	{
		int count = statistics_word(tmp);
		sum += count;
	}
	del_duplicate_word(wordMap);
	return sum;
}

void read_text(const char* fileName)
{
	FILE* pFile = fopen(fileName, "r");
	if (pFile == NULL)
	{
		perror("Error opening file");
		exit(-1);
	}
	//fseek(pFile, 0, SEEK_END);
	//size_t fileSize = ftell(pFile);
	char tmp[200] = { 0 };
	while (fgets(tmp, 200, pFile) != NULL)
		cout << tmp;
	fclose(pFile);
}

void bulk_delete()
{
	FILE* pFile1 = fopen("text.txt", "r");
	//将修改的内容直接重定向到另一个文件中
	FILE* pFile2 = fopen("index.txt", "w");
	if (pFile1 == NULL)
	{
		perror("Error opening file");
		exit(-1);
	}
	//获取文件的总字节大小
	fseek(pFile1, 0, SEEK_END);
	int fileSize = ftell(pFile1);
	fseek(pFile1, 0, SEEK_SET);
	//开辟足够的空间（之前老是越界，烦死了，摆烂了，你还能越过整个文件？？）
	char* tmp = (char*)malloc(sizeof(char)*fileSize);
	while(fgets(tmp, fileSize, pFile1) != NULL)
	{
		int begin = 0, end = 0;
		if(tmp)
		{
			//超链接的标志即<...>两个尖括号括起来的部分，因此遍历一遍找到起始部分进行覆盖删除即可
			while (begin < fileSize && tmp[begin] != '<')
				begin++;
			while (end < fileSize && tmp[end] != '>')
				end++;
			int _end = end, _begin = begin;

			tmp[begin] = '\0';
			fputs(tmp, pFile2);
		}
	}
	fclose(pFile1);
	fclose(pFile2);
}
int main()
{
	//read_text("text.txt");
	//cout << "---------------------------------" << endl;
	//bulk_delete();
	//cout << "---------------------------------" << endl;
	//read_text("index.txt");
	int ret = get_word_num("index.txt");
	
	cout << ret;
	return 0;
}
