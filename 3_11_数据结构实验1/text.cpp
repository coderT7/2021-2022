#define _CRT_SECURE_NO_WARNINGS 1

#include"text.h"

vector<string> wordArr;

void menu()
{
	cout << "------------------------------------" << endl;
	cout << "|           请  选  择             |" << endl;
	cout << "|                                  |" << endl;
	cout << "|-----      1. SHOW TXT      ------|" << endl;
	cout << "|-----      2. DEL  HYLINK   ------|" << endl;
	cout << "|-----      3. GET  WORD     ------|" << endl;
	cout << "|-----      4. DEL  DUP WORD ------|" << endl;
	cout << "|-----      5. DEL FILE      ------|" << endl;
	cout << "|-----      0. EXIT          ------|" << endl;
	cout << "------------------------------------" << endl;
}


//统计每行单词数时顺带将它去重并输出到文件
//因为存放单词的容器是全局的，所以统计下一行时进行去重也是从所有单词的最开始开始遍历
static void del_dup_word(char* text_string)
{

	FILE* pFile2 = fopen("delWord.txt", "a");//保存去重后的单词列表

	int count = 0, index = 0, flag = 0;
	while (text_string[index] != '\0')
	{
		string tmp;
		//当前字符不为空格则说明其为单词，则指针往后走，且flag置为1
		while (text_string[index] != ' ' && text_string[index] && (text_string[index] >= 'a'
			&& text_string[index] <= 'z') || (text_string[index] >= 'A' && text_string[index] <= 'Z'))
		{
			tmp += text_string[index];
			index++;
			flag = 1;
		}
		//走到这说明已经碰到空格了，并且flag为1，是第一次碰到空格，也就是说一个单词结束了
		if (flag)
		{
			int wordNum = 0, _workNum = 0;
			//向容器插入单词，用于去重
			wordArr.push_back(tmp);
			//统计单词个数
			wordNum = 0;
			vector<string>::iterator it;
			//str用于临时保存容器内的字符串，与要插入的单词进行比较
			//_tmp为tmp的拷贝，用于解决大小写敏感的问题
			string str, _tmp = tmp;
			for (it = wordArr.begin(); it != wordArr.end(); it++)
			{
				str = *it;
				//如果插入的单词没有重复，那wordNum只会是1，不然肯定大于1
				if (*it == tmp)
					wordNum++;
				//如果进行排查时发现有字符串不相等的情况可能是大小敏感，如：CHINA和China/china
				else if (*it != tmp)
				{
					//先将字符串全部转换成大写，如果和插入的单词相同，wordNum计数
					transform(str.begin(), str.end(), str.begin(), ::toupper);
					if (str == tmp)
						wordNum++;
					//再全部转换成小写，如果相同，计数
					transform(str.begin(), str.end(), str.begin(), ::tolower);
					if (str == tmp)
						wordNum++;
					//此时正在比较的字符串为小写，如果要插入的单词为China与china进行比较
					//将要插入的单词首字母改小写进行比较，若相同则计数
					_tmp[0] = tolower(_tmp[0]);
					if (str == _tmp)
						wordNum++;
				}
			}
			//每个单词之间插入个空格，便于区分
			//fputc(' ', pFile1);
			//遗留bug：一个单词的大小写未进行区分
			//这个bug硬生生搞了三个小时QAQ（记录自己废物时刻）
			//只有计数为1时，说明要插入的单词没有重复，才写入文件
			if (wordNum == 1)
			{
				fputs(tmp.c_str(), pFile2);
				fputc('\n', pFile2);
			}

		}
		//计数后指针继续走，并将flag置为0，这样做是防止如果连续遇到多个空格，count无脑++
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
	//获取文件的总字节大小
	fseek(pFile, 0, SEEK_END);
	int fileSize = ftell(pFile);
	fseek(pFile, 0, SEEK_SET);
	//开辟足够的空间（之前老是越界，烦死了，摆烂了，你还能越过整个文件？？）
	char* tmp = (char*)malloc(sizeof(char) * fileSize);

	while (fgets(tmp, fileSize, pFile) != NULL)
	{
		del_dup_word(tmp);
	}
	cout << "去重完成！保存至文件delWord.txt中" << endl;
}


static int statistics_word(char* text_string)
{
	if (text_string == NULL)
		return 0;

	FILE* pFile1 = fopen("word.txt", "a");
	
	//int len = strlen(text_string);
	//flag用于跳过连续几个空格的情况
	int count = 0, index = 0, flag = 0;
	while (text_string[index] != '\0')
	{
		//当前字符不为空格则说明其为单词，则指针往后走，且flag置为1
		while (text_string[index] != ' ' && text_string[index] && (text_string[index] >= 'a'
			&& text_string[index] <='z') || (text_string[index] >= 'A' && text_string[index] <= 'Z'))
		{
			fputc(text_string[index], pFile1);
			index++;
			flag = 1;
		}
		
		//走到这说明已经碰到空格了，并且flag为1，是第一次碰到空格，也就是说一个单词结束了
		if (flag)
		{
			count++; //count为单词计数
			//每个单词之间插入个空格，便于区分
			fputc('\n', pFile1);
		}
		//计数后指针继续走，并将flag置为0，这样做是防止如果连续遇到多个空格，count无脑++
		if (text_string[index])
			index++;
		flag = 0;	
	}

	fclose(pFile1);
	//返回该行字符串里有几个单词
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
	//获取文件的总字节大小
	fseek(pFile, 0, SEEK_END);
	int fileSize = ftell(pFile);
	fseek(pFile, 0, SEEK_SET);
	//开辟足够的空间（之前老是越界，烦死了，摆烂了，你还能越过整个文件？？）
	char* tmp = (char*)malloc(sizeof(char) * fileSize);

	while (fgets(tmp, fileSize, pFile) != NULL)
	{
		//先对每行单词计数
		int count = statistics_word(tmp);
		//所有行加起来即总单词数量
		sum += count;
	}
	//remove("delWord.txt");
	//del_duplicate_word(wordArr);
	cout << "捕获的单词列表已保存至word.txt中" << endl;
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
	cout << "删除成功！" << endl;
	cout << "删除超链接后的文件已保存至final.txt中" << endl;
	fclose(fp1);
	fclose(fp2);
}
//删除一行内的超链接
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
	char* tmp = (char*)malloc(sizeof(char)*fileSize);
	while(fgets(tmp, fileSize, pFile1) != NULL)
	{
		int begin = 0, end = 0;
		if(tmp)
		{
			//超链接的标志即<...>两个尖括号括起来的部分，因此遍历一遍找到起始部分进行覆盖删除即可
			//但是该文件里面大部分都是一行一个超链接，但有各别例外，故做下面的特判进行删除
			while (tmp[begin] != '\n' && tmp[begin] != '\0' && tmp[begin] != '<')
				begin++;
			while (tmp[end] != '\n' && tmp[end] != '\0' && tmp[end] != '>')
				end++;
			int _end = end, _begin = begin;
			//当>右尖括号后面不是换行符即说明该行有不止一个超链接（至少没有到结尾）
			while(tmp[++_end] != '\n' && tmp[_end] != '\0')
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
	cout << "删除成功！" << endl;
	cout << "删除超链接后的文件已保存至final_2.txt中" << endl;
	fclose(pFile1);
	fclose(pFile2);
}
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
	cout << "删除成功！" << endl;
	cout << "删除超链接后的文件已保存至final_3.txt中" << endl;
	fclose(pFile1);
	fclose(pFile2);
}
void blank_line(const char* fileName) {
	FILE* pFile1 = fopen(fileName, "r");
	//将修改的内容直接重定向到另一个文件中
	FILE* pFile2 = fopen("final_4.txt", "w");
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
	cout << "删除成功！" << endl;
	cout << "删除超链接后的文件已保存至final_4.txt中" << endl;
	fclose(pFile1);
	fclose(pFile2);
}
void delete_file(const char* fileName)
{
	assert(fileName);
	if (!strcmp(fileName, "text.txt"))
	{
		cout << "你无权删除该文件！" << endl;
		return;
	}
	else
	{
		remove(fileName);
		cout << "删除成功！" << endl;
	}
}

