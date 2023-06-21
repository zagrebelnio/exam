#pragma once
#include <iostream>
#include <string>

using namespace std;

template <typename T, size_t MAX_SIZE>
class Stack {
	T stack[MAX_SIZE];
	int top = -1;
public:
	Stack();
	bool push(const T& value);
	void pop();
	T& end();
	bool is_full() const;
	bool is_empty() const;
	size_t max_size() const;
	size_t size() const;
	void show();
};

template <typename T>
void processStack();
