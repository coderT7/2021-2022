#define _CRT_SECURE_NO_WARNINGS
#include"workManager.h"

//��ְ������ϵͳ�ĳ�ʼ��
workManager::workManager()
{
	//1���ļ�������ʱ
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
	/*	cout << "�ļ�������" << endl;*/
		this->m_Empnum = 0;//��ʼ��ְ������Ϊ��
		this->m_EmpArray = NULL;//��ʼ��ָ������Ϊ��
		this->m_FileIsEmpty = true;//�ļ�Ϊ��
		ifs.close();
		return;
	}
	//2���ļ�����������Ϊ��
	char ch;
	ifs >> ch;//��һ���ַ����������֮���������EOF���ļ�Ϊ��
	if (ifs.eof())//�ж���Ϊ���򷵻�ֵ���棬����Ϊ��
	{
		//cout << "�ļ�Ϊ��" << endl;
		this->m_Empnum = 0;//��ʼ��ְ������Ϊ��
		this->m_EmpArray = NULL;//��ʼ��ָ������Ϊ��
		this->m_FileIsEmpty = true;//�ļ�Ϊ��
		ifs.close();
		return;
	}
	//3�����ļ����������ݲ�Ϊ��
	this->m_FileIsEmpty = false;
	int num = this->get_Empnum();
	cout << "ְ������Ϊ��" << num << endl;
	this->m_Empnum = num;
	//������Ӧ��С�Ŀռ�
	this->m_EmpArray = new worker*[this->m_Empnum];
	//���ļ��е����ݳ�ʼ����������
	this->Init_Emp();
}

void workManager::showMenu()
{
	cout << "********************************************" << endl;
	cout << "*********  ��ӭʹ��ְ������ϵͳ�� **********" << endl;
	cout << "*************  0.�˳��������  *************" << endl;
	cout << "*************  1.����ְ����Ϣ  *************" << endl;
	cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
	cout << "*************  3.ɾ����ְְ��  *************" << endl;
	cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
	cout << "*************  5.����ְ����Ϣ  *************" << endl;
	cout << "*************  6.���ձ������  *************" << endl;
	cout << "*************  7.��������ĵ�  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void workManager::ExitSystem()
{
	cout << "��л����ʹ�ã�ף��������죡" << endl;
	exit(0);
}

void workManager::AddEmp()
{
	cout << "������Ҫ��Ӽ���Ա����" << endl;
	int addSize = 0;
	cin >> addSize;
	if (addSize > 0)
	{
		//���Ա��
		//���������Ա�����Ա������
		int newSize = this->m_Empnum + addSize;//ԭ�е�Ա������������ӵ�Ա������
		worker **newSpace = new worker*[newSize];
		//���ԭ����������ԭ�������ݸ��Ƶ��¿��ٵĿռ���
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_Empnum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//����µ�ְ������
		for (int i = 0; i < addSize; i++)
		{
			int id;
			string name;
			int dSelect;
			cout << "�������" << i + 1 << "��Ա�����" << endl;
			cin >> id;
			for (int j = 0; j < this->m_Empnum; j++)
			{
				while(this->m_EmpArray[j]->m_ID == id)
				{
					cout << "�ñ���Ѵ��ڣ������������µı��" << endl;
					cin >> id;
				}
			}
			cout << "�������" << i + 1 << "��Ա������" << endl;
			cin >> name;
			//���ж�̬��ѡ����д��
			//���벻ͬ��ѡ���ò�ͬ�������ຯ����д���ຯ��
			cout << "��ѡ���Ա���ĸ�λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> dSelect;
			//����(���)�µĻ���(Ա��)ָ��
			worker *worker = NULL;
			//�û���ָ��ָ��ͬ�����������
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
				cout << "��������" << endl;
				break;
			}
			newSpace[this->m_Empnum + i] = worker;
		}
		//�ͷ�ԭ��������
		delete[]this->m_EmpArray;
		//���¿ռ����ԭ����ָ����й���
		this->m_EmpArray = newSpace;
		//����Ա��������
		this->m_Empnum = newSize;
		//��������ݺ���洢���ļ���Ϊ��
		this->m_FileIsEmpty = false;
		//��ʾ�ɹ�
		cout << "�ɹ����" << addSize << "����ְ����" << endl;
		this->Save();
	}
	else
	{
		cout << "��������" << endl;
	}
	//��ֹ���򣬵�����������
	system("pause");
	//��������
	system("cls");
}

void workManager::Save()
{
	ofstream ofs;
	//д�ļ�
	ofs.open(FILENAME, ios::out);
	//��ÿһ���˵�����д�뵽�ļ�
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
	ifs.open(FILENAME, ios::in);//���ļ�
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
	//�ж��ļ��Ƿ�Ϊ��
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��ļ�Ϊ��" << endl;
		return;
	}
	else
	{
		for (int i = 0; i < this->m_Empnum; i++)
		{
			//���ö�̬���ò�ͬ�ĺ����Ľӿ�
			this->m_EmpArray[i]->showInfo();
		}
	}
	//�������������
	system("pause");
	system("cls");
}
void workManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
		return;
	}
	else
	{
		cout << "������Ҫɾ����ְ�����" << endl;
		int id = 0;;
		cin >> id;
		//�жϸ�ְ��id�Ƿ����
		int Index = this->Exist(id);
		if (Index != -1)
		{
			for (int i = Index; i < this->m_Empnum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_Empnum--;
			this->Save();
			cout << "ɾ���ɹ�" << endl;
		}
		else
		{
			cout << "��ְ�������ڣ����ʵ����" << endl;
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
//�޸�ְ��
void workManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		cout << "�������޸�ְ���ı�ţ�" << endl;
		int id;
		cin >> id;

		int ret = this->Exist(id);
		if (ret != -1)
		{
			cout << "���ҵ���ְ��" << endl;
			this->m_EmpArray[ret]->showInfo();
			cout << "�Ƿ�ȷ��Ҫ�޸ĸ�ְ����Ϣ" << endl << "1--->ȷ��" << endl << "0--->ȡ��" << endl;
			int enter = 0;
			cin >> enter;
			if (!enter) return;
			delete this->m_EmpArray[ret];

			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "�鵽�� " << id << "��ְ������������ְ���ţ� " << endl;
			cin >> newId;

			cout << "�������������� " << endl;
			cin >> newName;

			cout << "�������λ�� " << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
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

			//�������� ��������
			this->m_EmpArray[ret] = worker;

			cout << "�޸ĳɹ���" << endl;

			//���浽�ļ���
			this->Save();
		}
		else
		{
			cout << "�޸�ʧ�ܣ����޴���" << endl;
		}
	}

	//������� ����
	system("pause");
	system("cls");
}
void workManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
		return;
	}
	else
	{
		cout << "1������ְ����Ų���" << endl << "2������������" << endl;
		int Select = 0;
		cin >> Select;
		if (Select == 1)
		{
			int id = 0;
			cout << "������Ҫ���ҵ�ְ����ţ�" << endl;
			cin >> id;
			int ret = this->Exist(id);
			if (ret != -1)
			{
				cout << "���ҵ����Ϊ" << id << "��Ա��,������£�" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
				cout << "����ʧ�ܣ���ְ��������" << endl;
		}
		else if (Select == 2)
		{
			string name;
			cout << "������Ҫ���ҵ�ְ��������" << endl;
			cin >> name;
			//Ĭ��δ�ҵ���Ա��
			bool flag = false;
			for (int i = 0; i < m_Empnum; i++)
			{
				if (this->m_EmpArray[i]->m_name == name)
				{
					cout << "���ҳɹ���ְ�����Ϊ��"
						<< this->m_EmpArray[i]->m_ID
						<< "�ŵ�ְ����Ϣ���£�" << endl;
					this->m_EmpArray[i]->showInfo();
					//�ҵ����ӦԱ��
					flag = true;
				}
			}
			if (flag == false)
				cout << "����ʧ�ܣ���ְ��������" << endl;
		}
		else
		{
			cout << "����ѡ������" << endl;
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
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
		return;
	}
	cout << "��ѡ������ʽ��" << endl<<"1--->��ְ�������������"<<endl<<"2--->��ְ����Ž�������"<<endl;
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
		cout << "����������" << endl;
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
		cout << "�ѽ�������" << endl;
	}
	else
		cout << "��������" << endl;
	system("pause");
	system("cls");
}
void workManager::Clean_File()
{
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//��ģʽ ios::trunc���ļ��������ɾ���ļ������´���
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			//ɾ��������ÿ��ְ������
			for (int i = 0; i < this->m_Empnum; i++)
			{
				if (this->m_EmpArray[i] != NULL)
				{
					delete this->m_EmpArray[i];
					m_EmpArray[i] = NULL;
				}
			}
			this->m_Empnum = 0;
			//ɾ���ڲ�ά��ְ�������ָ��
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			//�ж�Ϊ��
			this->m_FileIsEmpty = true;
		}
		cout << "��ճɹ���" << endl;
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