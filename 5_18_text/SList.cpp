#include "SList.h"

//���쵥����

//���캯��
SList::SList()
{
	//��ʼ��
	head = new Node;
	head->word = "   ";
	head->next = nullptr;
}

//���
SList::SList(const SList& p)
{
	//���·���ռ�
	head = new Node;
	head->next = nullptr;
	Node* p1 = head;
	Node* p2 = p.head->next;
	while (p2 != nullptr)
	{
		p1->next = new Node;
		p1 = p1->next;
		p1->word = p2->word;
		p1->next = nullptr;
		p2 = p2->next;
	}
}


//����������
void SList::CreateSList(string filename)
{
	Node* ps=new Node;
	head->next = ps;
	ifstream ifs;
	ifs.open(filename, ios::in);
	if (!ifs.is_open())
	{
		cout << "���ļ�ʧ�ܣ�" << endl;
		exit(0);
	}
	string buf;//���ļ��еĵ���������ɵ�����
	while (ifs >> buf)
	{
		Node* p = new Node;
		p->word = buf;
		ps->next = p;
		ps = ps->next;
		p->next = p;
	}	
	ps->next = nullptr;
	ifs.close();
}

//��ӡ������
void SList::PrintSList()
{
	while (head != nullptr)
	{
		cout << head->word << endl;
		head = head->next;
	}
	cout<<"�ļ����ʽ�����"<<endl;
	
}



//ɾ���������ظ��ĵ���
void SList::DeleteRepeat()
{
	Node* p;
	p = head->next;
	int flag = 0;//�Ƿ��ظ��ı�־
	while (p != nullptr)
	{
		Node* cur, *q;
		cur = p->next;
		q = p;
		while (cur != nullptr)
		{			
			if (p->word == cur->word)//��p֮��������p��ͬ�ģ����ظ�
			{
				q->next = cur->next;
				delete cur;//ɾ���ظ����
				cur = q;
			}
			q = cur;//cur�İ���ָ��
			cur = cur->next;
		}
		p = p->next;
	}
}
 

//��������
SList::~SList()
{
	
	while (head != nullptr)
	{
		Node* delnode = head;
		head = head->next;
		delete delnode;
	}
	delete head;
}
