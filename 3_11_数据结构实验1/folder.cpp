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
	cout << "|           �� �� �� ��            |" << endl;
	cout << "|                                  |" << endl;
	cout << "|-----      1. SHOW TXT      ------|" << endl;
	cout << "|-----      2. DEL  HYLINK   ------|" << endl;
	cout << "|-----      3. GET  WORD     ------|" << endl;
	cout << "|-----      4. DEL  DUP WORD ------|" << endl;
	cout << "|-----      5. ˳ �� �� �� ��------|" << endl;
	cout << "|-----      6. �� �� �� �� ��------|" << endl;
	cout << "|-----      7. �� ʽ ջ �� ��------|" << endl;
	cout << "|-----      0. BACK          ------|" << endl;
	cout << "------------------------------------" << endl;
}
void _menu_4() {
	cout << "�������ݽṹ�ϻ�ʵ���ĵ�˳���Ĳ˵�" << endl;
	cout << "���ڲ�����֮ǰȥ������ļ��ظ����ʲ����㽫��д��ó������岿�֣����Զ������ò˵�" << endl;
	cout << "------------------------------------" << endl;
	cout << "|          ˳ �� �� �� ��          |" << endl;
	cout << "|                                  |" << endl;
	cout << "|-----      1. FIND WORD     ------|" << endl;
	cout << "|-----      2. SAVE WORD     ------|" << endl;
	cout << "|-----      3. PRINT WORD    ------|" << endl;
	cout << "|-----      4. DEL  DUP WORD ------|" << endl;
	cout << "|-----      0. BACK          ------|" << endl;
	cout << "------------------------------------" << endl;
}
//�ļ��п�����ǰ���ڣ�Ŀǰ��Ŀû˵�����ԣ����Ͳ��鷳�����ļ�����
//�����´���
void create_floder()
{
	const char* curPath = _getcwd(nullptr, 0);
	if (curPath == nullptr) {
		cout << "��ȡ��ǰ·��ʧ�ܣ�" << endl;
		return;
	}
	else {
		string folderPath = (string)curPath + string("\\unionDir");
		if (_mkdir(folderPath.c_str()) == -1) {
			cout << "�ļ����Ѵ��ڻ��ߴ����ļ���ʧ�ܣ����飡" << endl;
			return;
		};
	}
}

void remove_file(const char* fileName)
{
	assert(fileName);

	FILE* pf = fopen(fileName, "r");
	if (pf == NULL) {
		cout << "���ļ������ڣ����飡" << endl;
		return;
	}
	else {
		const char* curPath = _getcwd(nullptr, 0);
		if (curPath == nullptr) {
			cout << "��ȡ��ǰ·��ʧ�ܣ�" << endl;
			return;
		}
		string newPath = (string)curPath + string("\\unionDir") + string("\\") + string(fileName);
		string oldPath = (string)curPath + string("\\") + string(fileName);
		CString _old = oldPath.c_str();
		CString _new = newPath.c_str();
		bool get = CopyFile(_old, _new, FALSE);
		if (get == false)
			cout << "�����룺" << GetLastError() << endl;
		cout << "�ѽ�" << fileName << "�ƶ���" << newPath << endl;
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
		cout << "�ļ��в����ڻ�����Ȩ�޷��ʣ�" << endl;
		return;
	}
	//�����뱣��·���ģ�������������Ǻ���Ҫ
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
		cout << "���ļ������ļ���" << endl;
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
			cout << "�ѽ����ݱ�����˳���L1��" << endl;
			system("pause");
		}
			break;
		case PRINT: {
			//PrintSList(&seqList);
			for (auto val : tmpWord) {
				cout << val << endl;
			}
			cout << "��ӡ���" << endl;
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
			cout << "ȥ�����" << endl;
			cout << "ʣ�൥�ʣ�" << count << endl;
			system("pause");
		}
			break;
		case BACK:
			cout << "������һ��" << endl;
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
	cout << "|          ˳ �� �� �� ��          |" << endl;
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
			cout << "�ѽ����ݱ�����������L2��" << endl;
			system("pause");
		}
				 break;
		case PRINT: {
			//PrintSList(&seqList);
			for (auto val : tmpWord) {
				cout << val << endl;
			}
			cout << "��ӡ���" << endl;
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
			cout << "ȥ�����" << endl;
			cout << "ʣ�൥�ʣ�" << count << endl;
			system("pause");
		}
				   break;
		case BACK:
			cout << "������һ��" << endl;
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
	cout << "|          �� �� �� �� ��          |" << endl;
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
	cout << "|          �� ʽ ջ �� ��          |" << endl;
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
	//multimap<char, int> checkMap;//��¼
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
							cout << "��" << row << "��" << ",��" << i << "�в�ƥ��" << endl;
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
								cout << "��" << row << "��" << ",��" << i << "�в�ƥ��" << endl;
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
			//				cout << "��" << row << "��" << ",��" << i << "�в�ƥ��" << endl;
			//				cout << tmp << endl;
			//			}
			//		}
			//		checkStack.pop();
			//	}
			}

			if (flag && checkStack.empty()) {
				cout << "ȫ������ƥ��" << endl;
			}
			//if (!checkStack.empty()) {
			//	for (auto it : checkMap) {
			//		cout << "��" << it.second << "����" << it.first << "��ƥ��" << endl;
			//	}
			//}
			while (!checkStack.empty()) {
				int row = checkStackEmpty.top();
				char res = checkStack.top();
				checkStack.pop();
				checkStackEmpty.pop();
				cout << "��" << row << "����" << res << "��ƥ��" << endl;
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
			cout << "������һ��" << endl;
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
	cout << "��������Ҫ�鿴���ļ��У�" << endl;
	cout << "��Ŀǰֻ��һ���ļ��У������ļ�����unionDir" << endl;
	cout << "��Ȼ���㻹�е�ǰ����������ڵ��ļ��У��鿴��ǰ�ļ��У�����һ��С���㼴�ɣ�." << endl;
	cout << "���ˣ�����������ɣ�";
	cin >> str;
	get_all_file_name(str);
	//�´�������һ������д��ô�õĽṹ�ˣ������÷�װ���̳кͶ�̬������Զ��󣡣�����
	cout << "��������Ҫ������ļ���";
	cin >> str;
	do {
		system("cls");
		_menu();
		cout << "��������Ҫ���ļ����еĲ�����" << endl;
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
				cout << "��ѡ���Ƿ�Ҫ��ɾ����ҳ�����ӵ����ݺ�����ݴ�ӡ����Ļ�ϣ�0 or 1" << endl;
				cout << "�����룺";
				cin >> tmp;
				if (tmp == 1) {
					read_text("chrome_final.txt");
				}
				else
					;
			}
			else {
				cout << "��ѡ���Ƿ�Ҫ��ɾ�������Ӻ�����ݴ�ӡ����Ļ�ϣ�0 or 1" << endl;
				cout << "�����룺";
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
			//��ȡ����Ӧ�Ƕ�ɾ�������Ӻ���ļ����в���
			//�����ļ�����׷�ӷ�ʽ���еģ�Ϊ����߸����ԣ�ÿ�λ�ȡǰ�Ƚ�ԭ���ļ�ɾ��
			remove("word.txt");
			int ret = 0;
			if (str.compare("chrome.txt")) {
				ret = get_word_num("chrome_final.txt");
			}
			else if (str.compare("firefox.txt")) {
				ret = get_word_num("final_1.txt");
			}
			else {
				cout << "���ļ�������" << endl;
				return;
			}				
			cout << "������" << ret << "������" << endl;
			system("pause");
		}
		break;
		case delDup:
		{
			//ȥ��ͬͳ�Ƶ���ͬ��
			remove("del_word.txt");
			remove_duplicates(str.c_str());
			cout << "��ѡ���Ƿ�Ҫ�������б��ӡ����Ļ�ϣ�0 or 1" << endl;
			cout << "�����룺";
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
			cout << "�ѷ�����һ��" << endl;
			system("pause");
			break;
		default:
			cout << "�����������������룡" << endl;
			break;
		}
	} while (_input);
}