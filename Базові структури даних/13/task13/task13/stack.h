#pragma once
#include <iostream>
#include <string>

using namespace std;

class Stack {
	static const size_t MAX_SIZE = 10;
	char stack[MAX_SIZE] = {};
	int top = -1;
public:
	void push(const char& value);
	char pop();
	bool is_full();
	bool is_empty();
	void show();
	int size();
};