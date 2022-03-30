#define _CRT_SECURE_NO_WARNINGS 1

#include"text.h"

vector<string> wordArr;

void menu()
{
	cout << "------------------------------------" << endl;
	cout << "|           ��  ѡ  ��             |" << endl;
	cout << "|                                  |" << endl;
	cout << "|-----      1. SHOW TXT      ------|" << endl;
	cout << "|-----      2. DEL  HYLINK   ------|" << endl;
	cout << "|-----      3. GET  WORD     ------|" << endl;
	cout << "|-----      4. DEL  DUP WORD ------|" << endl;
	cout << "|-----      5. DEL FILE      ------|" << endl;
	cout << "|-----      0. EXIT          ------|" << endl;
	cout << "------------------------------------" << endl;
}


//ͳ��ÿ�е�����ʱ˳������ȥ�ز�������ļ�
//��Ϊ��ŵ��ʵ�������ȫ�ֵģ�����ͳ����һ��ʱ����ȥ��Ҳ�Ǵ����е��ʵ��ʼ��ʼ����
static void del_dup_word(char* text_string)
{

	FILE* pFile2 = fopen("delWord.txt", "a");//����ȥ�غ�ĵ����б�

	int count = 0, index = 0, flag = 0;
	while (text_string[index] != '\0')
	{
		string tmp;
		//��ǰ�ַ���Ϊ�ո���˵����Ϊ���ʣ���ָ�������ߣ���flag��Ϊ1
		while (text_string[index] != ' ' && text_string[index] && (text_string[index] >= 'a'
			&& text_string[index] <= 'z') || (text_string[index] >= 'A' && text_string[index] <= 'Z'))
		{
			tmp += text_string[index];
			index++;
			flag = 1;
		}
		//�ߵ���˵���Ѿ������ո��ˣ�����flagΪ1���ǵ�һ�������ո�Ҳ����˵һ�����ʽ�����
		if (flag)
		{
			int wordNum = 0, _workNum = 0;
			//���������뵥�ʣ�����ȥ��
			wordArr.push_back(tmp);
			//ͳ�Ƶ��ʸ���
			wordNum = 0;
			vector<string>::iterator it;
			//str������ʱ���������ڵ��ַ�������Ҫ����ĵ��ʽ��бȽ�
			//_tmpΪtmp�Ŀ��������ڽ����Сд���е�����
			string str, _tmp = tmp;
			for (it = wordArr.begin(); it != wordArr.end(); it++)
			{
				str = *it;
				//�������ĵ���û���ظ�����wordNumֻ����1����Ȼ�϶�����1
				if (*it == tmp)
					wordNum++;
				//��������Ų�ʱ�������ַ�������ȵ���������Ǵ�С���У��磺CHINA��China/china
				else if (*it != tmp)
				{
					//�Ƚ��ַ���ȫ��ת���ɴ�д������Ͳ���ĵ�����ͬ��wordNum����
					transform(str.begin(), str.end(), str.begin(), ::toupper);
					if (str == tmp)
						wordNum++;
					//��ȫ��ת����Сд�������ͬ������
					transform(str.begin(), str.end(), str.begin(), ::tolower);
					if (str == tmp)
						wordNum++;
					//��ʱ���ڱȽϵ��ַ���ΪСд�����Ҫ����ĵ���ΪChina��china���бȽ�
					//��Ҫ����ĵ�������ĸ��Сд���бȽϣ�����ͬ�����
					_tmp[0] = tolower(_tmp[0]);
					if (str == _tmp)
						wordNum++;
				}
			}
			//ÿ������֮�������ո񣬱�������
			//fputc(' ', pFile1);
			//����bug��һ�����ʵĴ�Сдδ��������
			//���bugӲ������������СʱQAQ����¼�Լ�����ʱ�̣�
			//ֻ�м���Ϊ1ʱ��˵��Ҫ����ĵ���û���ظ�����д���ļ�
			if (wordNum == 1)
			{
				fputs(tmp.c_str(), pFile2);
				fputc('\n', pFile2);
			}

		}
		//������ָ������ߣ�����flag��Ϊ0���������Ƿ�ֹ���������������ո�count����++
		if (text_string[index])
			index++;
		flag = 0;
	}

	fclose(pFile2);
}

void remove_duplicates(const char* fileName)
{
	FILE* pFile = fopen(fileName, "r");
	if (pFile == NULL)
	{
		perror("Error opening file");
		return;
	}
	//��ȡ�ļ������ֽڴ�С
	fseek(pFile, 0, SEEK_END);
	int fileSize = ftell(pFile);
	fseek(pFile, 0, SEEK_SET);
	//�����㹻�Ŀռ䣨֮ǰ����Խ�磬�����ˣ������ˣ��㻹��Խ�������ļ�������
	char* tmp = (char*)malloc(sizeof(char) * fileSize);

	while (fgets(tmp, fileSize, pFile) != NULL)
	{
		del_dup_word(tmp);
	}
	cout << "ȥ����ɣ��������ļ�delWord.txt��" << endl;
}


static int statistics_word(char* text_string)
{
	if (text_string == NULL)
		return 0;

	FILE* pFile1 = fopen("word.txt", "a");
	
	//int len = strlen(text_string);
	//flag�����������������ո�����
	int count = 0, index = 0, flag = 0;
	while (text_string[index] != '\0')
	{
		//��ǰ�ַ���Ϊ�ո���˵����Ϊ���ʣ���ָ�������ߣ���flag��Ϊ1
		while (text_string[index] != ' ' && text_string[index] && (text_string[index] >= 'a'
			&& text_string[index] <='z') || (text_string[index] >= 'A' && text_string[index] <= 'Z'))
		{
			fputc(text_string[index], pFile1);
			index++;
			flag = 1;
		}
		
		//�ߵ���˵���Ѿ������ո��ˣ�����flagΪ1���ǵ�һ�������ո�Ҳ����˵һ�����ʽ�����
		if (flag)
		{
			count++; //countΪ���ʼ���
			//ÿ������֮�������ո񣬱�������
			fputc('\n', pFile1);
		}
		//������ָ������ߣ�����flag��Ϊ0���������Ƿ�ֹ���������������ո�count����++
		if (text_string[index])
			index++;
		flag = 0;	
	}

	fclose(pFile1);
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
		return 0;
	}
	//��ȡ�ļ������ֽڴ�С
	fseek(pFile, 0, SEEK_END);
	int fileSize = ftell(pFile);
	fseek(pFile, 0, SEEK_SET);
	//�����㹻�Ŀռ䣨֮ǰ����Խ�磬�����ˣ������ˣ��㻹��Խ�������ļ�������
	char* tmp = (char*)malloc(sizeof(char) * fileSize);

	while (fgets(tmp, fileSize, pFile) != NULL)
	{
		//�ȶ�ÿ�е��ʼ���
		int count = statistics_word(tmp);
		//�����м��������ܵ�������
		sum += count;
	}
	//remove("delWord.txt");
	//del_duplicate_word(wordArr);
	cout << "����ĵ����б��ѱ�����word.txt��" << endl;
	return sum;
}

void read_text(const char* fileName)
{
	FILE* pFile = fopen(fileName, "r");
	if (pFile == NULL)
	{
		perror("Error opening file");
		return ;
	}
	//fseek(pFile, 0, SEEK_END);
	//size_t fileSize = ftell(pFile);
	char tmp[200] = { 0 };
	while (fgets(tmp, 200, pFile) != NULL)
		cout << tmp;
	fclose(pFile);
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
	cout << "ɾ���ɹ���" << endl;
	cout << "ɾ�������Ӻ���ļ��ѱ�����final.txt��" << endl;
	fclose(fp1);
	fclose(fp2);
}
//ɾ��һ���ڵĳ�����
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
	char* tmp = (char*)malloc(sizeof(char)*fileSize);
	while(fgets(tmp, fileSize, pFile1) != NULL)
	{
		int begin = 0, end = 0;
		if(tmp)
		{
			//�����ӵı�־��<...>�����������������Ĳ��֣���˱���һ���ҵ���ʼ���ֽ��и���ɾ������
			//���Ǹ��ļ�����󲿷ֶ���һ��һ�������ӣ����и������⣬������������н���ɾ��
			while (tmp[begin] != '\n' && tmp[begin] != '\0' && tmp[begin] != '<')
				begin++;
			while (tmp[end] != '\n' && tmp[end] != '\0' && tmp[end] != '>')
				end++;
			int _end = end, _begin = begin;
			//��>�Ҽ����ź��治�ǻ��з���˵�������в�ֹһ�������ӣ�����û�е���β��
			while(tmp[++_end] != '\n' && tmp[_end] != '\0')
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
	cout << "ɾ���ɹ���" << endl;
	cout << "ɾ�������Ӻ���ļ��ѱ�����final_2.txt��" << endl;
	fclose(pFile1);
	fclose(pFile2);
}
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
			if (tmp[i] == ';'  || tmp[i] == '}' || tmp[i] == ']' || tmp[i] == '/') {
				flag = true;
			}
		}
		if (flag) {
			flag = false;
			for (int i = 0; i < len; i++) {
				if (tmp[i] == ';'  || tmp[i] == '}' || tmp[i] == ']' || tmp[i] == '/' ) {
					flag = true;
				}
			}
		}
		if (!flag) {
			fputs(tmp, pFile2);
		}
	}
	cout << "ɾ���ɹ���" << endl;
	cout << "ɾ�������Ӻ���ļ��ѱ�����final_3.txt��" << endl;
	fclose(pFile1);
	fclose(pFile2);
}
void blank_line(const char* fileName) {
	FILE* pFile1 = fopen(fileName, "r");
	//���޸ĵ�����ֱ���ض�����һ���ļ���
	FILE* pFile2 = fopen("final_4.txt", "w");
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
		int len = strlen(tmp);
		for (int i = 0; i < len; i++) {
			if ((tmp[i] >= 'a' && tmp[i] <= 'z') || (tmp[i] >= '0' && tmp[i] <= '9') || (tmp[i] >= 'A' && tmp[i] <= 'Z')) {
				flag = true;
			}
		}
		if (flag) {
			flag = false;
			for (int i = 0; i < len; i++) {
				if ((tmp[i] >= 'a' && tmp[i] <= 'z') || (tmp[i] >= '0' && tmp[i] <= '9') || (tmp[i] >= 'A' && tmp[i] <= 'Z')){
					flag = true;
				}
			}
		}
		if(flag)
			fputs(tmp, pFile2);
	}
	cout << "ɾ���ɹ���" << endl;
	cout << "ɾ�������Ӻ���ļ��ѱ�����final_4.txt��" << endl;
	fclose(pFile1);
	fclose(pFile2);
}
void delete_file(const char* fileName)
{
	assert(fileName);
	if (!strcmp(fileName, "text.txt"))
	{
		cout << "����Ȩɾ�����ļ���" << endl;
		return;
	}
	else
	{
		remove(fileName);
		cout << "ɾ���ɹ���" << endl;
	}
}

