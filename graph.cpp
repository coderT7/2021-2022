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
//	int in;//入度（有多少个结点指向当前结点）
//	int out;//出度（当前结点指向的结点有多少个）
//	vector<Node>* nexts;//当前结点直接指向的邻居
//	vector<Edge>* edges;//当前结点有多少条指向其它结点的边
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
//	int weight;//权值
//	//表示的为有向边，无向边即两个有向边拼一块儿即可
//	Node from;//该边属于哪个结点
//	Node to;//该边指向哪个结点
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
//	unordered_map<int, Node>* nodes;//点集
//	unordered_set<Edge>* edges;//边集
//
//	Graph() {
//		nodes = new unordered_map<int, Node>();
//		edges = new unordered_set<Edge>();
//	}
//};


//前后指针法
int part_sort_3(int* arr, int left, int right)
{
	int cur = left + 1, prev = left;
	int keyi = left;
	while (cur <= right)
	{
		//++prev与cur相等时，就相当于自己与自己交换，没有意义，故加上该条件
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
	//当区间不存在时，即不需要再继续进行递归
	if (left > right)
		return;

	int keyIndex = part_sort_3(arr, left, right);

	my_quick_sort(arr, left, keyIndex - 1);//递归左区间

	my_quick_sort(arr, keyIndex + 1, right);//递归右区间

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