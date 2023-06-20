#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
};

class Tree {
	Node* root;
	Node* find_minimum(Node* node);
public:
	Tree();
	void add(const int& value);
	Node* pop(Node* node, const int& value);
	void pop(const int& value);
	void show(Node* node);
	void show();
};

int generate_number(const int& min, const int& max);