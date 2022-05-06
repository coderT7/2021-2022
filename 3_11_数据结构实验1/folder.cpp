#define _CRT_SECURE_NO_WARNINGS 1

#include"main.h"

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