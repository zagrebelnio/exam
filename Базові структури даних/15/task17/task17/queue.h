#pragma once
#include <iostream>
#include <string>

using namespace std;

class Queue {
	struct Node {
		int data;
		Node* previous;
		Node* next;
	};
	Node* head;
	Node* tail;
	int size;
public:
	Queue();
	void push(const int& value);
	void pop();
	void show();
	int modify(const int& num);
};