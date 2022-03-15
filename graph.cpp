#define _CRT_SECURE_NO_WARNINGS 1

#include<unordered_map>
#include<unordered_set>
#include<iostream>
#include<algorithm>
#include<ctime>

using namespace std;

//using namespace std;
//class Node {
//public:
//	int value;
//	int in;//��ȣ��ж��ٸ����ָ��ǰ��㣩
//	int out;//���ȣ���ǰ���ָ��Ľ���ж��ٸ���
//	vector<Node>* nexts;//��ǰ���ֱ��ָ����ھ�
//	vector<Edge>* edges;//��ǰ����ж�����ָ���������ı�
//
//	Node() {
//		
//	}
//
//	Node(int value) {
//		this->value = value;
//		in = 0;
//		out = 0;
//		nexts = new vector<Node>();
//		edges = new vector<Edge>();
//	}
//};
//
//class Edge {
//public:
//	int weight;//Ȩֵ
//	//��ʾ��Ϊ����ߣ�����߼����������ƴһ�������
//	Node from;//�ñ������ĸ����
//	Node to;//�ñ�ָ���ĸ����
//
//	Edge(int weight, Node from, Node to) {
//		this->weight = weight;
//		this->from = from;
//		this->to = to;
//	}
//};
//
//class Graph {
//public:
//	unordered_map<int, Node>* nodes;//�㼯
//	unordered_set<Edge>* edges;//�߼�
//
//	Graph() {
//		nodes = new unordered_map<int, Node>();
//		edges = new unordered_set<Edge>();
//	}
//};


//ǰ��ָ�뷨
int part_sort_3(int* arr, int left, int right)
{
	int cur = left + 1, prev = left;
	int keyi = left;
	while (cur <= right)
	{
		//++prev��cur���ʱ�����൱���Լ����Լ�������û�����壬�ʼ��ϸ�����
		if (arr[cur] < arr[keyi]) {
			prev++;
			swap(arr[prev], arr[cur]);
		}
			
		cur++;
	}
	swap(arr[prev], arr[keyi]);
	return prev;
}

void my_quick_sort(int* arr, int left, int right)
{
	//�����䲻����ʱ��������Ҫ�ټ������еݹ�
	if (left > right)
		return;

	int keyIndex = part_sort_3(arr, left, right);

	my_quick_sort(arr, left, keyIndex - 1);//�ݹ�������

	my_quick_sort(arr, keyIndex + 1, right);//�ݹ�������

}
int main()
{
	srand((unsigned int)time(NULL));
	int arr[10];
	for (int i = 0; i < 10; i++) {
		arr[i] = rand() % 20;
	}
	int len = sizeof(arr) / sizeof(int);
	my_quick_sort(arr, 0, len-1);
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}