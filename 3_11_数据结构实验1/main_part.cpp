#define _CRT_SECURE_NO_WARNINGS 1

#include"main.h"

//��Ϊ�ļ�������ڵ��ʵ�ת�͵㣬����ȥ��
vector<string> wordArr;
//�˵���ûɶ��˵
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
	cout << "|-----      6. READ FOLDER   ------|" << endl;
	cout << "|-----      7. REMOVE FILE   ------|" << endl;
	cout << "|-----      0. EXIT          ------|" << endl;
	cout << "------------------------------------" << endl;
}

void _menu()
{
	cout << "------------------------------------" << endl;
	cout << "|           �� �� �� ��            |" << endl;
	cout << "|                                  |" << endl;
	cout << "|-----      1. SHOW TXT      ------|" << endl;
	cout << "|-----      2. DEL  HYLINK   ------|" << endl;
	cout << "|-----      3. GET  WORD     ------|" << endl;
	cout << "|-----      4. DEL  DUP WORD ------|" << endl;
	cout << "|-----      0. BACK          ------|" << endl;
	cout << "------------------------------------" << endl;
}


//ͳ��ÿ�е�����ʱ˳������ȥ�ز�������ļ�
//��Ϊ��ŵ��ʵ�������ȫ�ֵģ�����ͳ����һ��ʱ����ȥ��Ҳ�Ǵ����е��ʵ��ʼ��ʼ����
static void del_dup_word(char* text_string)
{

	FILE* pFile2 = fopen("del_word.txt", "a");//����ȥ�غ�ĵ����б�

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
//ȥ���ظ�����
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

//ͳ�Ƶ���
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
//��ȡ���ʸ���
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
//�Ķ��ļ�
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
//ɾ���ļ�
//��Ҫ�������ṩ��ôһ������
void delete_file(const char* fileName)
{
	assert(fileName);
	//��ֹ�û��ڳ�������Դ�ļ�ɾ�����³��������У�ֱ���ֶ�ɾ��Դ�ļ����ҹܲ��ˣ�
	if (!strcmp(fileName, "chrome.txt") || !strcmp(fileName,"firefox.txt"))
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



