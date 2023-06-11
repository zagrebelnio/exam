#pragma once
#include <iostream>
#include <string>

using namespace std;

class List {
	struct Node {
		int data;
		Node* next;
	};
	Node* head;
	int size;
public:
	List();
	void push_back(const int& num);
	bool find(const int& value);
	int min();
	int max();
	double median();
	void sort();
	void show();
};