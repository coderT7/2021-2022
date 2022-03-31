#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

class Node {
public:
	int value;
	int in;
	int out;
	vector<Node>* nexts;
	vector<Edge>* edges;

	Node(int _value) {
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
		queue<Node> bfsNode;
		unordered_set<Node> findNode;
		bfsNode.push(node);
		findNode.insert(node);
		while (!bfsNode.empty()) {
			Node cur = bfsNode.front();
			bfsNode.pop();
			cout << cur.value << endl;
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
		stack<Node>stack;
		unordered_set<Node>set;
		stack.push(node);
		set.insert(node);
		cout << node.value << endl;
		while (!stack.empty()) {
			Node cur = stack.top();
			stack.pop();
			for (Node next : *(cur.nexts)) {
				if (!set.count(next)) {
					stack.push(cur);
					stack.push(next);
					set.insert(next);
					cout << next.value << endl;
					break;
				}
			}
		}

	}
};