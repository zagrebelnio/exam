#pragma once
#include <iostream>
#include <string>

using namespace std;

class Tree {
	struct Node {
		char data;
		Node* left;
		Node* right;
	};
	Node* root;
public:
	Tree();
	void add(const char& value);
	void preOrder(Node* node, string &result);
	void preOrder(string& result);
	void inOrder(Node* node, string& result);
	void inOrder(string& result);
	void show(Node* node);
	void show();
};