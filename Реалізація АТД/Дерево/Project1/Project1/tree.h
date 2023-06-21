#pragma once
#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>

using namespace std;

template <typename T>
class Tree {
	struct Node {
		T data;
		Node* left;
		Node* right;
	};
	Node* root;
	void remove_subtree(Node* node);
	Node* remove(Node* node, const T& value);
	Node* find_min(Node* node);
	void show(Node* node);
public:
	Tree();
	~Tree();
	void add(const T& value);
	void remove(const T& value);
	void clear();
	void show();
};

int generate_number(int min, int max);