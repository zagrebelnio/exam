#pragma once
#include <iostream>
#include <string>

using namespace std;

class Stack {
	static const int MAX_SIZE = 10;
	string stack[MAX_SIZE];
	int top = -1;
public:
	void push(const string& value);
	string pop();
	void show();
	int size();
	bool is_full();
	bool is_empty();
	void modify();
};