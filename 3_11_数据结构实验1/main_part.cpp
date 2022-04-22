#define _CRT_SECURE_NO_WARNINGS 1

#include"main.h"
#include"SeqList.h"


//作为文件与程序内单词的转送点，用于去重
//vector容器与顺序表相类似，故沿用之前的容器，顺序表代码已实现（已进行一定程度的测试）
vector<string> wordArr;
//菜单，没啥好说
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
	cout << "|-----      6. READ FOLDER   ------|" << endl;
	cout << "|-----      7. REMOVE FILE   ------|" << endl;
	cout << "|-----      0. EXIT          ------|" << endl;
	cout << "------------------------------------" << endl;
}
void _menu()
{
	cout << "------------------------------------" << endl;
	cout << "|           文 件 处 理            |" << endl;
	cout << "|                                  |" << endl;
	cout << "|-----      1. SHOW TXT      ------|" << endl;
	cout << "|-----      2. DEL  HYLINK   ------|" << endl;
	cout << "|-----      3. GET  WORD     ------|" << endl;
	cout << "|-----      4. DEL  DUP WORD ------|" << endl;
	cout << "|-----      0. BACK          ------|" << endl;
	cout << "------------------------------------" << endl;
}
void _menu_4() {
	cout << "这是数据结构上机实验四的顺序表的菜单" << endl;
	cout << "由于步骤与之前去重输出文件重复，故不打算将其写入该程序主体部分，所以独立出该菜单" << endl;
	cout << "------------------------------------" << endl;
	cout << "|          顺 序 表 相 关          |" << endl;
	cout << "|                                  |" << endl;
	cout << "|-----      1. FIND WORD     ------|" << endl;
	cout << "|-----      2. SAVE WORD     ------|" << endl;
	cout << "|-----      3. PRINT WORD    ------|" << endl;
	cout << "|-----      4. DEL  DUP WORD ------|" << endl;
	cout << "|-----      0. BACK          ------|" << endl;
	cout << "------------------------------------" << endl;
}
static enum _Option {
	Back,
	FindWord,
	SaveWord,
	PrintWord,
	DelDupWord
};
//寻找最长的单词
static string find_maxChar_word() {
	int max = 0;;
	string maxWord = "";
	for (auto it : wordArr) {
		if (it.size() > max) {
			max = (int)it.size();
			maxWord = it;
		}
	}
	return maxWord;
}
//打印单词列表
static void print_wordArr() {
	for (auto it : wordArr) {
		cout << it << endl;
	}
}
//删除重复的单词
static void delDup_wordArr() {
	int count = 0;
	vector<string>::iterator it1, it2;
	for (it1 = wordArr.begin(); it1 != wordArr.end(); it1++) {
		for (it2 = it1 + 1; it2 != wordArr.end();) {
			if (!(*it1).compare(*it2)) {
				it2 = wordArr.erase(it2);
			}
			else {
				it2++;
			}
		}
	}
	print_wordArr();
}
//顺序表相关的操作
void about_seqList() {
	int input = 0;
	string word;
	do {
		system("cls");
		_menu_4();
		cout << "请输入你要进行的操作" << endl;
		cin >> input;
		switch (input) {
		case Back:
			cout << "返回上一层" << endl;
			system("pause");
			break;
		case FindWord:
			cout << "最长的单词是：" << find_maxChar_word() << endl;
			system("pause");
			break;
		case SaveWord:
			cout << "保存成功" << endl;
			system("pause");
			break;
		case PrintWord:
			print_wordArr();
			system("pause");
			break;
		case DelDupWord:
			delDup_wordArr();
			system("pause");
			break;
		default:
			break;
		}
	} while (input);
}

//统计每行单词数时顺带将它去重并输出到文件
//因为存放单词的容器是全局的，所以统计下一行时进行去重也是从所有单词的最开始开始遍历
static void del_dup_word(char* text_string)
{

	FILE* pFile2 = fopen("del_word.txt", "a");//保存去重后的单词列表

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
//去除重复单词
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
#if 0
	for (auto it : wordArr) {
		cout << it << endl;
	}
#endif
	cout << "去重完成！保存至文件delWord.txt中" << endl;
}

//统计单词
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
//获取单词个数
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
	//添加的关于单词进行的顺序表操作
	int choose = 0;
	cout << "请选择是否对栈中的单词列表进行操作：> “0”否/“1”是" << endl;
	cin >> choose;
	if (choose == 1) {
		remove_duplicates("word.txt");
		about_seqList();
	}
	else {
		cout << "输入错误！" << endl;
	}
	return sum;
}
//阅读文件
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
//删除文件
//主要就是想提供这么一个功能
void delete_file(const char* fileName)
{
	assert(fileName);
	//防止用户在程序中误将源文件删除导致程序不能运行（直接手动删除源文件那我管不了）
	if (!strcmp(fileName, "chrome.txt") || !strcmp(fileName,"firefox.txt"))
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



