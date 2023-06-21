#pragma once
#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Queue {
	struct Node {
		T data;
		Node* prev;
		Node* next;
	};
	Node* head;
	Node* tail;
	int size;
public:
	Queue();
	~Queue();
	void push(const T& value);
	void pop();
	bool is_empty();
	void clear();
	void show();
};

template <typename T>
void process_queue();