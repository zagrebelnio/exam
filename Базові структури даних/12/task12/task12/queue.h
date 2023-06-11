#pragma once
#include <iostream>
#include <string>

using namespace std;

class List {
	struct Node {
		string data;
		Node* previous;
		Node* next;
	};
	Node* head;
	Node* tail;
	int size;

public:
	List();
	~List();

	void push_back(const string& value);
	void pop_front();
	void clear();
	int get_size() const;
	void show() const;
};

class Queue {
	List list;
public:
	Queue() = default;
	void push(const string& value);
	void pop();
	void show();
};