#pragma once
#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Stack {
	struct Node {
		T data;
		Node* previous;
		Node* next;
	};
	Node* head;
	Node* tail;
	int size;
public:
	Stack();
	Stack(const Stack& other);
	~Stack();
	void push(const T& value);
	void pop();
	T& end();
	bool is_empty();
	void show();
	void clear();
};

