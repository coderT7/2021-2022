#define _CRT_SECURE_NO_WARNINGS 1

#include"main.h"

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