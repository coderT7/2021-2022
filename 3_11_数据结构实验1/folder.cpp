#define _CRT_SECURE_NO_WARNINGS 1

#include"main.h"
#include"folder.h"
#include"SeqList.h"
#include"singleList.h"
#include<unordered_map>
#include<stack>
#include<map>
using namespace std;
void _menu()
{
	cout << "------------------------------------" << endl;
	cout << "|           文 件 处 理            |" << endl;
	cout << "|                                  |" << endl;
	cout << "|-----      1. SHOW TXT      ------|" << endl;
	cout << "|-----      2. DEL  HYLINK   ------|" << endl;
	cout << "|-----      3. GET  WORD     ------|" << endl;
	cout << "|-----      4. DEL  DUP WORD ------|" << endl;
	cout << "|-----      5. 顺 序 表 相 关------|" << endl;
	cout << "|-----      6. 单 链 表 相 关------|" << endl;
	cout << "|-----      7. 链 式 栈 相 关------|" << endl;
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
//文件夹可以提前存在（目前题目没说不可以），就不麻烦创建文件夹了
//留着下次用
void create_floder()
{
	const char* curPath = _getcwd(nullptr, 0);
	if (curPath == nullptr) {
		cout << "获取当前路径失败！" << endl;
		return;
	}
	else {
		string folderPath = (string)curPath + string("\\unionDir");
		if (_mkdir(folderPath.c_str()) == -1) {
			cout << "文件夹已存在或者创建文件夹失败！请检查！" << endl;
			return;
		};
	}
}

void remove_file(const char* fileName)
{
	assert(fileName);

	FILE* pf = fopen(fileName, "r");
	if (pf == NULL) {
		cout << "该文件不存在，请检查！" << endl;
		return;
	}
	else {
		const char* curPath = _getcwd(nullptr, 0);
		if (curPath == nullptr) {
			cout << "获取当前路径失败！" << endl;
			return;
		}
		string newPath = (string)curPath + string("\\unionDir") + string("\\") + string(fileName);
		string oldPath = (string)curPath + string("\\") + string(fileName);
		CString _old = oldPath.c_str();
		CString _new = newPath.c_str();
		bool get = CopyFile(_old, _new, FALSE);
		if (get == false)
			cout << "错误码：" << GetLastError() << endl;
		cout << "已将" << fileName << "移动至" << newPath << endl;
	}
}

static bool dirExists(const std::string& dirName_in)
{
	DWORD ftyp = GetFileAttributesA(dirName_in.c_str());
	if (ftyp == INVALID_FILE_ATTRIBUTES)
		return false;  //something is wrong with your path!  

	if (ftyp & FILE_ATTRIBUTE_DIRECTORY)
		return true;   // this is a directory!  

	return false;    // this is not a directory!  
}

void get_all_file_name(const string& dirPath)
{
	if (dirExists(dirPath) == false) {
		cout << "文件夹不存在或者无权限访问！" << endl;
		return;
	}
	//本来想保存路径的，后面想想好像不是很需要
	vector<string> vecFilePath;
	regex fileSuffix(".*\\.txt");
	bool flag = true;
	namespace fs = std::filesystem;
	for (auto& itr : fs::directory_iterator(dirPath))
	{
		auto filePath = itr.path();

		auto fileName = filePath.filename().string();//filename.string() <=> "1.txt"
		vecFilePath.push_back(filePath.string());
		if (regex_match(fileName, fileSuffix)) {
			cout << fileName << endl;
			flag = false;
		}
	}
	if (flag) {
		cout << "该文件夹无文件！" << endl;
	}
}
extern vector<string> wordArr;

void seqList_work()
{
	FILE* pWord = fopen("word.txt", "r");
	vector<string> tmpWord;
	//Seqlist seqList;
	//InitList(&seqList);
	
	int input = 0;
	do {
		system("cls");
		seqList_menu();
		cin >> input;
		switch (input)
		{
		case SAVE: {
			char tmp[1024] = { 0 };
			while (fgets(tmp, 1024, pWord) != nullptr) {
				tmpWord.push_back(tmp);
			}
			cout << "已将数据保存至顺序表L1中" << endl;
			system("pause");
		}
			break;
		case PRINT: {
			//PrintSList(&seqList);
			for (auto val : tmpWord) {
				cout << val << endl;
			}
			cout << "打印完毕" << endl;
			system("pause");
		}
			break;
		case DELDUP: {
			int count = 0;
			set<string> del;
			for (auto val : tmpWord) {
				del.insert(val);
			}
			tmpWord.clear();
			for (auto val : del) {
				cout << val << endl;
				tmpWord.push_back(val);
				count++;
			}
			cout << "去重完毕" << endl;
			cout << "剩余单词：" << count << endl;
			system("pause");
		}
			break;
		case BACK:
			cout << "返回上一级" << endl;
			system("pause");
			return;
			break;
		default:
			break;
		}
	} while (input);
}

void seqList_menu()
{
	cout << "------------------------------------" << endl;
	cout << "|          顺 序 表 相 关          |" << endl;
	cout << "|                                  |" << endl;
	cout << "|-----      1. SAVE          ------|" << endl;
	cout << "|-----      2. PRINT         ------|" << endl;
	cout << "|-----      3. DEL  DUP WORD ------|" << endl;
	cout << "|-----      0. BACK          ------|" << endl;
	cout << "------------------------------------" << endl;
}

void singleList_work()
{
	FILE* pWord = fopen("word.txt", "r");
	list<string> tmpWord;

	int input = 0;
	do {
		system("cls");
		singleList_menu();
		cin >> input;
		switch (input)
		{
		case SAVE: {
			char tmp[1024] = { 0 };
			while (fgets(tmp, 1024, pWord) != nullptr) {
				tmpWord.push_back(tmp);
			}
			cout << "已将数据保存至单链表L2中" << endl;
			system("pause");
		}
				 break;
		case PRINT: {
			//PrintSList(&seqList);
			for (auto val : tmpWord) {
				cout << val << endl;
			}
			cout << "打印完毕" << endl;
			system("pause");
		}
				  break;
		case DELDUP: {
			int count = 0;
			set<string> del;
			for (auto val : tmpWord) {
				del.insert(val);
			}
			tmpWord.clear();
			for (auto val : del) {
				cout << val << endl;
				tmpWord.push_back(val);
				count++;
			}
			cout << "去重完毕" << endl;
			cout << "剩余单词：" << count << endl;
			system("pause");
		}
				   break;
		case BACK:
			cout << "返回上一级" << endl;
			system("pause");
			return;
			break;
		default:
			break;
		}
	} while (input);
}

void singleList_menu()
{
	cout << "------------------------------------" << endl;
	cout << "|          单 链 表 相 关          |" << endl;
	cout << "|                                  |" << endl;
	cout << "|-----      1. SAVE          ------|" << endl;
	cout << "|-----      2. PRINT         ------|" << endl;
	cout << "|-----      3. DEL  DUP WORD ------|" << endl;
	cout << "|-----      0. BACK          ------|" << endl;
	cout << "------------------------------------" << endl;
}

void stackList_menu()
{
	cout << "------------------------------------" << endl;
	cout << "|          链 式 栈 相 关          |" << endl;
	cout << "|                                  |" << endl;
	cout << "|-----      1. CHECK         ------|" << endl;
	cout << "|-----      2. PRINT         ------|" << endl;
	cout << "|-----      0. BACK          ------|" << endl;
	cout << "------------------------------------" << endl;
}

static void stack_clear(stack<char>& checkStack) {
	while (!checkStack.empty()) {
		checkStack.pop();
	}
}
void stackList_work(const char* fileName)
{
	FILE* pFile = fopen(fileName, "r");
	//multimap<char, int> checkMap;//记录
	stack<char> checkStack;
	stack<int> checkStackEmpty;
	int row = 0, col = 0;
	bool flag = true;
	int input = 0;
	do {
		system("cls");
		stackList_menu();
		cin >> input;
		switch (input)
		{
		case 1: {
			rewind(pFile);
			char tmp[2048] = { 0 };
			while (fgets(tmp, 2048, pFile)) {
				//stack_clear(checkStack);
				row++;
				if((tmp[0] != '\n') && (tmp[0] != '\0'))
				for (int i = 0; i < strlen(tmp); i++) {
					switch (tmp[i]) {
					case '<':
						if (tmp[i + 1] - '0' >= 0 && tmp[i + 1] - '0' <= 9)
							break;
						else
							;
					case '[':
					case '(':
					case '{':
						//checkMap.insert(make_pair(tmp[i], row));
						checkStackEmpty.push(row);
						checkStack.push(tmp[i]);
						break;
					case '>':
					case ']':
					case ')':
					case '}': {
						if (checkStack.empty()) {
							flag = false;
							cout << "第" << row << "行" << ",第" << i << "列不匹配" << endl;
							cout << tmp << endl;
						}
						else {
							char res = checkStack.top();
							checkStackEmpty.pop();
							//auto it = checkMap.find(res);
							//checkMap.erase(it);
							checkStack.pop();
							if (tmp[i] == '>' && res != '<'
								|| tmp[i] == ']' && res != '['
								|| tmp[i] == '(' && res != '('
								|| tmp[i] == '}' && res != '{') {
								flag = false;
								cout << "第" << row << "行" << ",第" << i << "列不匹配" << endl;
								cout << tmp << endl;
							}
						}
						break;
					}
					default:
						break;
					}
				}
			//	while (!checkStack.empty()) {
			//		flag = false;
			//		for (int i = 0; i < strlen(tmp); i++) {
			//			char res = checkStack.top();
			//			if (res == tmp[i]) {
			//				cout << "第" << row << "行" << ",第" << i << "列不匹配" << endl;
			//				cout << tmp << endl;
			//			}
			//		}
			//		checkStack.pop();
			//	}
			}

			if (flag && checkStack.empty()) {
				cout << "全部括号匹配" << endl;
			}
			//if (!checkStack.empty()) {
			//	for (auto it : checkMap) {
			//		cout << "第" << it.second << "行有" << it.first << "不匹配" << endl;
			//	}
			//}
			while (!checkStack.empty()) {
				int row = checkStackEmpty.top();
				char res = checkStack.top();
				checkStack.pop();
				checkStackEmpty.pop();
				cout << "第" << row << "行有" << res << "不匹配" << endl;
			}
			system("pause");
		}
				 break;
		case 2: {
			//...
			system("pause");
		}
				  break;
		case BACK:
			cout << "返回上一级" << endl;
			system("pause");
			return;
			break;
		default:
			break;
		}
	} while (input);
}



void inside_floder() {
	string str;
	int _input = 0,tmp = 0;
	cout << "请输入你要查看的文件夹：" << endl;
	cout << "你目前只有一个文件夹！！！文件名：unionDir" << endl;
	cout << "当然，你还有当前解决方案所在的文件夹，查看当前文件夹，输入一个小数点即可：." << endl;
	cout << "好了，现在你输入吧：";
	cin >> str;
	get_all_file_name(str);
	//下次做程序一定不能写这么烂的结构了，多利用封装！继承和多态！万物皆对象！！！！
	cout << "请输入你要处理的文件：";
	cin >> str;
	do {
		system("cls");
		_menu();
		cout << "请输入你要对文件进行的操作：" << endl;
		cin >> _input;
		switch (_input) {
		case readTxt:
		{
			read_text(str.c_str());
			system("pause");
		}
		break;
		case delHyink:
		{
			//hyperlink_delete(str.c_str());
			delete_all(str.c_str());
			if (!str.compare("chrome.txt")) {
				cout << "请选择是否要将删除网页不可视的内容后的内容打印在屏幕上：0 or 1" << endl;
				cout << "请输入：";
				cin >> tmp;
				if (tmp == 1) {
					read_text("chrome_final.txt");
				}
				else
					;
			}
			else {
				cout << "请选择是否要将删除超链接后的内容打印在屏幕上：0 or 1" << endl;
				cout << "请输入：";
				cin >> tmp;
				if (tmp == 1) {
					read_text("final_1.txt");
				}
				else
					;
			}
			system("pause");
		}
		break;
		case getWord:
		{
			//获取单词应是对删除超链接后的文件进行操作
			//单词文件是以追加方式进行的，为了提高复用性，每次获取前先将原有文件删除
			remove("word.txt");
			int ret = 0;
			if (str.compare("chrome.txt")) {
				ret = get_word_num("chrome_final.txt");
			}
			else if (str.compare("firefox.txt")) {
				ret = get_word_num("final_1.txt");
			}
			else {
				cout << "该文件不存在" << endl;
				return;
			}				
			cout << "共捕获到" << ret << "个单词" << endl;
			system("pause");
		}
		break;
		case delDup:
		{
			//去重同统计单词同理
			remove("del_word.txt");
			remove_duplicates(str.c_str());
			cout << "请选择是否要将单词列表打印在屏幕上：0 or 1" << endl;
			cout << "请输入：";
			cin >> tmp;
			if (tmp == 1) {
				read_text("delWord.txt");
			}
			else
				;
			system("pause");
			break;
		}
		case seqListWork:
			seqList_work();
			break;
		case singleListWork:
			singleList_work();
			break;
		case stackListWork:
			stackList_work(str.c_str());
			break;
		case Exit:
			cout << "已返回上一层" << endl;
			system("pause");
			break;
		default:
			cout << "输入有误，请重新输入！" << endl;
			break;
		}
	} while (_input);
}