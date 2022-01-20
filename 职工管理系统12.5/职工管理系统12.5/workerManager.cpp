#define _CRT_SECURE_NO_WARNINGS
#include"workManager.h"

//对职工管理系统的初始化
workManager::workManager()
{
	//1、文件不存在时
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
	/*	cout << "文件不存在" << endl;*/
		this->m_Empnum = 0;//初始化职工人数为空
		this->m_EmpArray = NULL;//初始化指针数组为空
		this->m_FileIsEmpty = true;//文件为空
		ifs.close();
		return;
	}
	//2、文件存在且数据为空
	char ch;
	ifs >> ch;//读一个字符，如果读完之后读到的是EOF则文件为空
	if (ifs.eof())//判断其为空则返回值是真，否则为假
	{
		//cout << "文件为空" << endl;
		this->m_Empnum = 0;//初始化职工人数为空
		this->m_EmpArray = NULL;//初始化指针数组为空
		this->m_FileIsEmpty = true;//文件为空
		ifs.close();
		return;
	}
	//3、当文件存在且数据不为空
	this->m_FileIsEmpty = false;
	int num = this->get_Empnum();
	cout << "职工人数为：" << num << endl;
	this->m_Empnum = num;
	//开辟相应大小的空间
	this->m_EmpArray = new worker*[this->m_Empnum];
	//将文件中的数据初始化到数组中
	this->Init_Emp();
}

void workManager::showMenu()
{
	cout << "********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void workManager::ExitSystem()
{
	cout << "感谢您的使用，祝您生活愉快！" << endl;
	exit(0);
}

void workManager::AddEmp()
{
	cout << "请输入要添加几名员工：" << endl;
	int addSize = 0;
	cin >> addSize;
	if (addSize > 0)
	{
		//添加员工
		//计算添加新员工后的员工数量
		int newSize = this->m_Empnum + addSize;//原有的员工数量加上添加的员工数量
		worker **newSpace = new worker*[newSize];
		//如果原来有数据则将原来的数据复制到新开辟的空间中
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_Empnum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//添加新的职工数据
		for (int i = 0; i < addSize; i++)
		{
			int id;
			string name;
			int dSelect;
			cout << "请输入第" << i + 1 << "个员工编号" << endl;
			cin >> id;
			for (int j = 0; j < this->m_Empnum; j++)
			{
				while(this->m_EmpArray[j]->m_ID == id)
				{
					cout << "该编号已存在，请重新输入新的编号" << endl;
					cin >> id;
				}
			}
			cout << "请输入第" << i + 1 << "个员工姓名" << endl;
			cin >> name;
			//进行多态的选择（重写）
			//输入不同的选择即用不同的派生类函数重写基类函数
			cout << "请选择该员工的岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;
			//创建(添加)新的基类(员工)指针
			worker *worker = NULL;
			//用基类指针指向不同的派生类对象
			switch (dSelect)
			{
			case m_Empoyee:
				worker = new Empoyee(id, name, dSelect);
				break;
			case m_Manager:
				worker = new Manager(id, name, dSelect);
				break;
			case m_Boss:
				worker = new Boss(id, name, dSelect);
				break;
			default:
				cout << "输入有误" << endl;
				break;
			}
			newSpace[this->m_Empnum + i] = worker;
		}
		//释放原来的数组
		delete[]this->m_EmpArray;
		//将新空间给到原来的指针进行管理
		this->m_EmpArray = newSpace;
		//更新员工的人数
		this->m_Empnum = newSize;
		//添加了数据后则存储的文件不为空
		this->m_FileIsEmpty = false;
		//提示成功
		cout << "成功添加" << addSize << "名新职工！" << endl;
		this->Save();
	}
	else
	{
		cout << "输入有误" << endl;
	}
	//终止程序，点击任意键继续
	system("pause");
	//清屏操作
	system("cls");
}

void workManager::Save()
{
	ofstream ofs;
	//写文件
	ofs.open(FILENAME, ios::out);
	//将每一个人的数据写入到文件
	for (int i = 0; i < this->m_Empnum; i++)
	{
		ofs << this->m_EmpArray[i]->m_ID << " "
			<< this->m_EmpArray[i]->m_name << " "
			<< this->m_EmpArray[i]->m_DeptID << endl;
	}
	ofs.close();
}

int workManager::get_Empnum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//读文件
	int ID;
	string name;
	int dID;
	int num = 0;
	while (ifs >> ID&&ifs >> name&&ifs >> dID)
		num++;
	return num;
}

void workManager::Init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int ID;
	string name;
	int dID;
	int Index = 0;
	while (ifs >> ID&&ifs >> name&&ifs >> dID)
	{
		worker *worker = NULL;
		switch (dID)
		{
		case m_Empoyee:
			worker = new Empoyee(ID, name, dID);
			break;
		case m_Manager:
			worker = new Manager(ID, name, dID);
			break;
		case m_Boss:
			worker = new Boss(ID, name, dID);
			break;
		}
		this->m_EmpArray[Index] = worker;
		Index++;
	}
	ifs.close();
}
void workManager::Show_Emp()
{
	//判断文件是否为空
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或文件为空" << endl;
		return;
	}
	else
	{
		for (int i = 0; i < this->m_Empnum; i++)
		{
			//利用多态调用不同的函数的接口
			this->m_EmpArray[i]->showInfo();
		}
	}
	//按任意键后清屏
	system("pause");
	system("cls");
}
void workManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
		return;
	}
	else
	{
		cout << "请输入要删除的职工编号" << endl;
		int id = 0;;
		cin >> id;
		//判断该职工id是否存在
		int Index = this->Exist(id);
		if (Index != -1)
		{
			for (int i = Index; i < this->m_Empnum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_Empnum--;
			this->Save();
			cout << "删除成功" << endl;
		}
		else
		{
			cout << "该职工不存在，请核实输入" << endl;
			return;
		}
	}
	system("pause");
	system("cls");
}
int workManager::Exist(int dID)
{
	int Index = -1;
	for (int i = 0; i < this->m_Empnum; i++)
	{
		if (this->m_EmpArray[i]->m_DeptID == dID)
			return i;
	}
	return Index;
}
//修改职工
void workManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		cout << "请输入修改职工的编号：" << endl;
		int id;
		cin >> id;

		int ret = this->Exist(id);
		if (ret != -1)
		{
			cout << "查找到该职工" << endl;
			this->m_EmpArray[ret]->showInfo();
			cout << "是否确认要修改该职工信息" << endl << "1--->确认" << endl << "0--->取消" << endl;
			int enter = 0;
			cin >> enter;
			if (!enter) return;
			delete this->m_EmpArray[ret];

			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "查到： " << id << "号职工，请输入新职工号： " << endl;
			cin >> newId;

			cout << "请输入新姓名： " << endl;
			cin >> newName;

			cout << "请输入岗位： " << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;

			worker * worker = NULL;
			switch (dSelect)
			{
			case m_Empoyee:
				worker = new Empoyee(newId, newName, dSelect);
				break;
			case m_Manager:
				worker = new Manager(newId, newName, dSelect);
				break;
			case m_Boss:
				worker = new Boss(newId, newName, dSelect);
				break;
			default:
				break;
			}

			//更改数据 到数组中
			this->m_EmpArray[ret] = worker;

			cout << "修改成功！" << endl;

			//保存到文件中
			this->Save();
		}
		else
		{
			cout << "修改失败，查无此人" << endl;
		}
	}

	//按任意键 清屏
	system("pause");
	system("cls");
}
void workManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
		return;
	}
	else
	{
		cout << "1、按照职工编号查找" << endl << "2、按姓名查找" << endl;
		int Select = 0;
		cin >> Select;
		if (Select == 1)
		{
			int id = 0;
			cout << "请输入要查找的职工编号：" << endl;
			cin >> id;
			int ret = this->Exist(id);
			if (ret != -1)
			{
				cout << "查找到编号为" << id << "的员工,结果如下：" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
				cout << "查找失败，该职工不存在" << endl;
		}
		else if (Select == 2)
		{
			string name;
			cout << "请输入要查找的职工姓名：" << endl;
			cin >> name;
			//默认未找到该员工
			bool flag = false;
			for (int i = 0; i < m_Empnum; i++)
			{
				if (this->m_EmpArray[i]->m_name == name)
				{
					cout << "查找成功，职工编号为："
						<< this->m_EmpArray[i]->m_ID
						<< "号的职工信息如下：" << endl;
					this->m_EmpArray[i]->showInfo();
					//找到相对应员工
					flag = true;
				}
			}
			if (flag == false)
				cout << "查找失败，该职工不存在" << endl;
		}
		else
		{
			cout << "输入选项有误" << endl;
		}
	}
	
	system("pause");
	system("cls");

}
static void Swap(worker** a1,worker** a2)
{
	worker* tmp = *a1;
	*a1 = *a2;
	*a2 = tmp;
}
void workManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
		return;
	}
	cout << "请选择排序方式：" << endl<<"1--->按职工编号升序排序"<<endl<<"2--->按职工编号降序排序"<<endl;
	int Select = 0;
	cin >> Select;
	if (Select == 2)
	{
		for (int i = 0; i < m_Empnum - 1; i++)
		{
			int flag = 1;
			for (int j = 0; j < m_Empnum - i - 1; j++)
			{
				if (this->m_EmpArray[j]->m_ID > this->m_EmpArray[j + 1]->m_ID)
					Swap(&m_EmpArray[j], &m_EmpArray[j + 1]);
				flag = 0;
			}
			if (flag)
				break;
		}
		cout << "已升序排序" << endl;
	}
	else if (Select == 1)
	{
		for (int i = 0; i < m_Empnum - 1; i++)
		{
			int flag = 1;
			for (int j = 0; j < m_Empnum - i - 1; j++)
			{
				if (this->m_EmpArray[j]->m_ID < this->m_EmpArray[j + 1]->m_ID)
					Swap(&m_EmpArray[j], &m_EmpArray[j + 1]);
				flag = 0;
			}
			if (flag)
				break;
		}
		cout << "已降序排序" << endl;
	}
	else
		cout << "输入有误" << endl;
	system("pause");
	system("cls");
}
void workManager::Clean_File()
{
	cout << "确认清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//打开模式 ios::trunc即文件如果存在删除文件并重新创建
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			//删除堆区的每个职工对象
			for (int i = 0; i < this->m_Empnum; i++)
			{
				if (this->m_EmpArray[i] != NULL)
				{
					delete this->m_EmpArray[i];
					m_EmpArray[i] = NULL;
				}
			}
			this->m_Empnum = 0;
			//删除内部维护职工对象的指针
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			//判断为空
			this->m_FileIsEmpty = true;
		}
		cout << "清空成功！" << endl;
	}

	system("pause");
	system("cls");
}
workManager::~workManager()
{
	if (this->m_EmpArray != NULL)
	{
		for (int i = 0; i < m_Empnum; i++)
		{
			if (this->m_EmpArray[i] != NULL)
			{
				delete[]m_EmpArray[i];
				m_EmpArray[i] = NULL;
			}
		}
		delete[]this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}