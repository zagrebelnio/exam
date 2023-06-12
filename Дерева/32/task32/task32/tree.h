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
	void show(Node* node);
	void inOrder(Node* node, int& sum);
	int left_sum();
	int right_sum();
	void show();
};