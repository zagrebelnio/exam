#pragma once
#include <iostream>
#include <string>

using namespace std;

class Tree {
	struct Node {
		int data;
		Node* left;
		Node* right;
	};
	Node* root;
public:
	Tree();
	void add(const int& value);
	bool postOrder(Node* node, int& value);
	bool postOrder(int& value);
	void show(Node* node);
	void show();
};