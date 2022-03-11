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
		//��ǰ�ַ���Ϊ�ո���˵����Ϊ���ʣ���ָ�������ߣ���flag��Ϊ1
		while (text_string[index] != ' ' && text_string[index] && (text_string[index] >= 'a'
			&& text_string[index] <='z') || (text_string[index] >= 'A' && text_string[index] <= 'Z'))
		{
			tmp += text_string[index];
			fputc(text_string[index], pFile);
			index++;
			flag = 1;
		}
		//�ߵ���˵���Ѿ������ո��ˣ�Ҳ����˵һ�����ʽ����ˣ���ʱcount����
		if (flag)
		{
			count++;
			fputc(' ', pFile);
		}
		//������ָ������ߣ�����flag��Ϊ0���������Ƿ�ֹ���������������ո�count����++
		if (text_string[index])
			index++;
		flag = 0;
		//���б�����ϣ��ʱ���ʵļ���
		int wordNum = 0;
		//���뵥��
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
	//���ظ����ַ������м�������
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
	//��ȡ�ļ������ֽڴ�С
	fseek(pFile, 0, SEEK_END);
	int fileSize = ftell(pFile);
	fseek(pFile, 0, SEEK_SET);
	//�����㹻�Ŀռ䣨֮ǰ����Խ�磬�����ˣ������ˣ��㻹��Խ�������ļ�������
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
	//���޸ĵ�����ֱ���ض�����һ���ļ���
	FILE* pFile2 = fopen("index.txt", "w");
	if (pFile1 == NULL)
	{
		perror("Error opening file");
		exit(-1);
	}
	//��ȡ�ļ������ֽڴ�С
	fseek(pFile1, 0, SEEK_END);
	int fileSize = ftell(pFile1);
	fseek(pFile1, 0, SEEK_SET);
	//�����㹻�Ŀռ䣨֮ǰ����Խ�磬�����ˣ������ˣ��㻹��Խ�������ļ�������
	char* tmp = (char*)malloc(sizeof(char)*fileSize);
	while(fgets(tmp, fileSize, pFile1) != NULL)
	{
		int begin = 0, end = 0;
		if(tmp)
		{
			//�����ӵı�־��<...>�����������������Ĳ��֣���˱���һ���ҵ���ʼ���ֽ��и���ɾ������
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
