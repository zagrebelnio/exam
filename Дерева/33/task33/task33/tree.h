/*#pragma once
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
	void construct(string expression);
	bool isOperator(char c);
	void prefix(Node* node);
	void prefix();
	int evaluate(Node* node);
	int evaluate();
};*/