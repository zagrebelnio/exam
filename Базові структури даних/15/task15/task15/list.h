#pragma once
#include <iostream>
#include <string>

using namespace std;

class List {
	struct Node {
		char data;
		Node* previous;
		Node* next;
	};
	Node* head;
	Node* tail;
	int size;
public:
	List();
	void push_back(const char& value);
	void pop_back();
	void show();
	void sort();
	string odd_elements();
};