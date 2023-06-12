#pragma once
#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>

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
	void inOrder(Node* node, int& counter);
	void inOrder(int& counter);
	void show(Node* node);
	void show();
};

int generate_number(int min, int max);