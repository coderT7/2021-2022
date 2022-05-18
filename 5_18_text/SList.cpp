#include "SList.h"

//构造单链表

//构造函数
SList::SList()
{
	//初始化
	head = new Node;
	head->word = "   ";
	head->next = nullptr;
}

//深拷贝
SList::SList(const SList& p)
{
	//重新分配空间
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


//创建单链表
void SList::CreateSList(string filename)
{
	Node* ps=new Node;
	head->next = ps;
	ifstream ifs;
	ifs.open(filename, ios::in);
	if (!ifs.is_open())
	{
		cout << "打开文件失败！" << endl;
		exit(0);
	}
	string buf;//将文件中的单词逐个串成单链表
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

//打印单链表
void SList::PrintSList()
{
	while (head != nullptr)
	{
		cout << head->word << endl;
		head = head->next;
	}
	cout<<"文件单词结束！"<<endl;
	
}



//删除链表中重复的单词
void SList::DeleteRepeat()
{
	Node* p;
	p = head->next;
	int flag = 0;//是否重复的标志
	while (p != nullptr)
	{
		Node* cur, *q;
		cur = p->next;
		q = p;
		while (cur != nullptr)
		{			
			if (p->word == cur->word)//在p之后遇到与p相同的，即重复
			{
				q->next = cur->next;
				delete cur;//删除重复结点
				cur = q;
			}
			q = cur;//cur的伴随指针
			cur = cur->next;
		}
		p = p->next;
	}
}
 

//析构函数
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
