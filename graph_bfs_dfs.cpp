#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<list>
#include<stack>
using namespace std;

class Node {
public:
	int value;
	int in;
	int out;
	vector<Node>* nexts;
	vector<Edge>* edges;

	Node(int _value = 0) {
		this->value = _value;
		this->in = 0;
		this->out = 0;
		nexts = new vector<Node>();
		edges = new vector<Edge>();
	}
};

class Edge {
public:
	int weight;
	Node from;
	Node to;
	Edge(int _weight, Node _from, Node _to) : weight(_weight), from(_from), to(_to) {}
};

class Graph {
public:
	unordered_map<int, Node>* nodes;
	unordered_set<Edge>* edges;

	Graph() {
		nodes = new unordered_map<int, Node>();
		edges = new unordered_set<Edge>();
	}
};

class bfs {
public:
	void bfs_solution(Node node) {
		//进行bfs的队列
		queue<Node> bfsNode;
		//保证不重复访问同一个结点
		unordered_set<Node> findNode;
		//直接将结点入队列（随便一个结点）并在set中记录
		bfsNode.push(node);
		findNode.insert(node);
		//栈不为空则继续
		while (!bfsNode.empty()) {
			//取出队首结点进行处理
			Node cur = bfsNode.front();
			bfsNode.pop();
			cout << cur.value << endl;
			//访问所有的邻居结点，如果其在set不存在则加入队列中进行遍历
			for (auto next : *(cur.nexts)) {
				if (!findNode.count(cur)) {
					bfsNode.push(next);
					findNode.insert(next);
				}
			}
		}
	}
};

class dfs {
public:
	void dfs_solution(Node node) {
		//进行dfs的栈
		stack<Node>stack;
		//保证不会重复遍历同一个结点
		unordered_set<Node>set;
		//依旧随便将一个结点入栈并进行记录
		stack.push(node);
		set.insert(node);
		//入栈了则直接处理
		cout << node.value << endl;
		while (!stack.empty()) {
			//先将栈顶的元素取出
			Node cur = stack.top();
			stack.pop();
			//遍历栈顶元素的邻居
			for (Node next : *(cur.nexts)) {
				//找到栈顶元素中的第一个未被记录的邻居
				if (!set.count(next)) {
					//找到后先将原栈顶元素压回栈中（为后续可能进行回溯做准备）
					stack.push(cur);
					//再将第一个未被记录的邻居入栈
					stack.push(next);
					//并将第一个未被记录的邻居进行记录
					set.insert(next);
					//入栈后则直接处理
					cout << next.value << endl;
					//找到一个则直接break出循环不再找邻居，进行下一个结点的处理
					break;
				}
			}
		}
	}
};

class topological_sort {
public:
	void topological_solution(Graph graph) {
		//保存结点及其入度
		unordered_map<Node, int> inMap;
		//入度为零则入队列
		queue<Node>inZeroNode;
		//先将图中每个结点都进行记录
		for (auto node : *(graph.nodes)) {
			inMap.emplace(node.second, node.second.in);
			if (node.second.in == 0) {
				inZeroNode.push(node.second);
			}
		}
		//拓扑排序结果
		list<Node>ret;
		unordered_map<Node, int>::iterator it;
		while (!inZeroNode.empty()) {
			Node cur = inZeroNode.front();
			inZeroNode.pop();
			//将队首的元素取出放入结果链表里
			ret.push_back(cur);
			//消除该结点的其它影响（对其它结点的入度影响）
			for (auto next : *(cur.nexts)) {
				it = inMap.find(next);
				//将其的邻居结点的入度都减一
				inMap.emplace(next, it->second - 1);
				//如果减一后有入度为零的则加入队列中
				if (it->second == 0) {
					inZeroNode.push(next);
				}
			}
		}
	}
};