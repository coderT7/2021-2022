#define _CRT_SECURE_NO_WARNINGS 1

#include"main.h"
//��ɾ�����ܽ���ͳһ����
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
//����ɾ��<>������������
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
		cout << "ɾ���ɹ���" << endl;
		cout << "ɾ�������Ӻ���ļ��ѱ�����final_1.txt��" << endl;
	}
	fclose(fp1);
	fclose(fp2);
}
//ɾ��һ���ڵĳ����ӣ������ã�
void hyperlink_delete(const char* fileName)
{
	FILE* pFile1 = fopen(fileName, "r");
	//���޸ĵ�����ֱ���ض�����һ���ļ���
	FILE* pFile2 = fopen("_final.txt", "w");
	if (pFile1 == NULL)
	{
		perror("Error opening file");
		return;
	}
	//��ȡ�ļ������ֽڴ�С
	fseek(pFile1, 0, SEEK_END);
	int fileSize = ftell(pFile1);
	fseek(pFile1, 0, SEEK_SET);
	//�����㹻�Ŀռ䣨֮ǰ����Խ�磬�����ˣ������ˣ��㻹��Խ�������ļ�������
	char* tmp = (char*)malloc(sizeof(char) * fileSize);
	while (fgets(tmp, fileSize, pFile1) != NULL)
	{
		int begin = 0, end = 0;
		if (tmp)
		{
			//�����ӵı�־��<...>�����������������Ĳ��֣���˱���һ���ҵ���ʼ���ֽ��и���ɾ������
			//���Ǹ��ļ�����󲿷ֶ���һ��һ�������ӣ����и������⣬������������н���ɾ��
			while (tmp[begin] != '\n' && tmp[begin] != '\0' && tmp[begin] != '<')
				begin++;
			while (tmp[end] != '\n' && tmp[end] != '\0' && tmp[end] != '>')
				end++;
			int _end = end, _begin = begin;
			//��>�Ҽ����ź��治�ǻ��з���˵�������в�ֹһ�������ӣ�����û�е���β��
			while (tmp[++_end] != '\n' && tmp[_end] != '\0')
			{
				//�õ��Ҽ����ź��滹�ж��ٸ��ֽ�����
				int len = (int)strlen(tmp + _end);
				//��������ǰ�ƶ����ǵ�ԭ���ĳ��������ڵ��ֽ�����
				//�����з��Լ���ֹ��Ҳ������ǰ�棬���ں����ͷ�ٴα������Ѿ����ǵ��ַ�����β
				for (int i = 0; i <= len; i++)
					tmp[_begin++] = tmp[_end++];
				//�ٴ�ͷ��ʼ�Һ����Ƿ���<...>������
				end = 0, begin = 0;
				while (tmp[end] != '\0' && tmp[end] != '>' && tmp[end + 1] != '\n')
					end++;
				while (tmp[begin] != '\0' && tmp[begin] != '<' && tmp[begin + 1] != '\n')
					begin++;
				//����г����ӣ���begin��λ�ú�endλ�ò������غϣ���֮����û�г�����
				if (begin == end)
					break;
				//�ӱ���Ϊ����ԭ���ı���ʼ�ն����ż����ţ����ӱ��������ƶ�����
				_end = end; _begin = begin;
			}
			//������Ҽ����ź����ǻ��з���˵������û�г�������
			if (tmp[end + 1] == '\n')
			{
				//��������Ϊ��������һ���ж��������ӵ����
				if (tmp[begin + 1] == '\n')
					tmp[begin + 1] = '\0';
				else
					tmp[begin] = '\0';
			}
			fputs(tmp, pFile2);
		}
	}

	cout << "ɾ���ɹ���" << endl;
	cout << "ɾ�������Ӻ���ļ��ѱ�����final.txt��" << endl;
	fclose(pFile1);
	fclose(pFile2);
}
//ɾ������
void del_funtion(const char* fileName) {
	FILE* pFile1 = fopen(fileName, "r");
	//���޸ĵ�����ֱ���ض�����һ���ļ���
	FILE* pFile2 = fopen("final_2.txt", "w");
	if (pFile1 == NULL)
	{
		perror("Error opening file");
		return;
	}
	//��ȡ�ļ������ֽڴ�С
	fseek(pFile1, 0, SEEK_END);
	int fileSize = ftell(pFile1);
	fseek(pFile1, 0, SEEK_SET);
	//�����㹻�ռ䣨��ʵҲû��Ҫ�����ҾͿ���
	char* tmp = (char*)malloc(sizeof(char) * fileSize);
	//�ж��������־
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
//ɾ���ֺţ�������䣩
void del_semicolon(const char* fileName) {
	FILE* pFile1 = fopen(fileName, "r");
	//���޸ĵ�����ֱ���ض�����һ���ļ���
	FILE* pFile2 = fopen("final_3.txt", "w");
	if (pFile1 == NULL)
	{
		perror("Error opening file");
		return;
	}
	//��ȡ�ļ������ֽڴ�С
	fseek(pFile1, 0, SEEK_END);
	int fileSize = ftell(pFile1);
	fseek(pFile1, 0, SEEK_SET);
	//�����㹻�ռ䣨��ʵҲû��Ҫ�����ҾͿ���
	char* tmp = (char*)malloc(sizeof(char) * fileSize);
	//�ж��Ƿ�Ϊ�ֺŵı�־
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
//ɾ�����У�ɾ�������̫���ˣ���
void blank_line(const char* fileName) {
	FILE* pFile1 = fopen(fileName, "r");
	//���޸ĵ�����ֱ���ض�����һ���ļ���
	FILE* pFile2 = fopen("chrome_final.txt", "w");
	if (pFile1 == NULL)
	{
		perror("Error opening file");
		return;
	}
	//��ȡ�ļ������ֽڴ�С
	fseek(pFile1, 0, SEEK_END);
	int fileSize = ftell(pFile1);
	fseek(pFile1, 0, SEEK_SET);
	//�����㹻�ռ䣨��ʵҲû��Ҫ�����ҾͿ���
	char* tmp = (char*)malloc(sizeof(char) * fileSize);
	//�ж��Ƿ�Ϊ�ֺŵı�־
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
	cout << "ɾ���ɹ���" << endl;
	cout << "ɾ�������Ӻ���ļ��ѱ�����chrome_final.txt��" << endl;
	fclose(pFile1);
	fclose(pFile2);
}