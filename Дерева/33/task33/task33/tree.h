#include <iostream>
#include <string>

using namespace std;

class Node {
	char data;
	Node* left;
	Node* right;
public:
	Node() : data(' '), left(nullptr), right(nullptr) {}
	Node(char c) : data(c), left(nullptr), right(nullptr) {}
	void show() {
		cout << data << " ";
		if (left) left->show();
		if (right) right->show();
	}
	friend class Tree;
};

class Tree {
	Node* root;
public:
	static int n;
	Tree() : root(nullptr) {}
	Node* makeTree(string, size_t, size_t);
	int calcTree(Node*);
	Node* getNode() { return root; }
	void print();
	void print(Node*);

};