#pragma once
#include <iostream>
#include <string>

using namespace std;

class Queue {
	struct Node {
		string data;
		Node* previous;
		Node* next;
	};
	Node* head;
	Node* tail;
	int size;
public:
	Queue();
	~Queue();
	void push_back(const string& s);
	void push_front(const string& s);
	void pop_back();
	void pop_front();
	void show();
	bool is_empty();
};