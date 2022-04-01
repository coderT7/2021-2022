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
		//����bfs�Ķ���
		queue<Node> bfsNode;
		//��֤���ظ�����ͬһ�����
		unordered_set<Node> findNode;
		//ֱ�ӽ��������У����һ����㣩����set�м�¼
		bfsNode.push(node);
		findNode.insert(node);
		//ջ��Ϊ�������
		while (!bfsNode.empty()) {
			//ȡ�����׽����д���
			Node cur = bfsNode.front();
			bfsNode.pop();
			cout << cur.value << endl;
			//�������е��ھӽ�㣬�������set���������������н��б���
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
		//����dfs��ջ
		stack<Node>stack;
		//��֤�����ظ�����ͬһ�����
		unordered_set<Node>set;
		//������㽫һ�������ջ�����м�¼
		stack.push(node);
		set.insert(node);
		//��ջ����ֱ�Ӵ���
		cout << node.value << endl;
		while (!stack.empty()) {
			//�Ƚ�ջ����Ԫ��ȡ��
			Node cur = stack.top();
			stack.pop();
			//����ջ��Ԫ�ص��ھ�
			for (Node next : *(cur.nexts)) {
				//�ҵ�ջ��Ԫ���еĵ�һ��δ����¼���ھ�
				if (!set.count(next)) {
					//�ҵ����Ƚ�ԭջ��Ԫ��ѹ��ջ�У�Ϊ�������ܽ��л�����׼����
					stack.push(cur);
					//�ٽ���һ��δ����¼���ھ���ջ
					stack.push(next);
					//������һ��δ����¼���ھӽ��м�¼
					set.insert(next);
					//��ջ����ֱ�Ӵ���
					cout << next.value << endl;
					//�ҵ�һ����ֱ��break��ѭ���������ھӣ�������һ�����Ĵ���
					break;
				}
			}
		}
	}
};

class topological_sort {
public:
	void topological_solution(Graph graph) {
		//�����㼰�����
		unordered_map<Node, int> inMap;
		//���Ϊ���������
		queue<Node>inZeroNode;
		//�Ƚ�ͼ��ÿ����㶼���м�¼
		for (auto node : *(graph.nodes)) {
			inMap.emplace(node.second, node.second.in);
			if (node.second.in == 0) {
				inZeroNode.push(node.second);
			}
		}
		//����������
		list<Node>ret;
		unordered_map<Node, int>::iterator it;
		while (!inZeroNode.empty()) {
			Node cur = inZeroNode.front();
			inZeroNode.pop();
			//�����׵�Ԫ��ȡ��������������
			ret.push_back(cur);
			//�����ý�������Ӱ�죨�������������Ӱ�죩
			for (auto next : *(cur.nexts)) {
				it = inMap.find(next);
				//������ھӽ�����ȶ���һ
				inMap.emplace(next, it->second - 1);
				//�����һ�������Ϊ�������������
				if (it->second == 0) {
					inZeroNode.push(next);
				}
			}
		}
	}
};