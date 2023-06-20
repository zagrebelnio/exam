#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
class Stack {
	T* data;
	int size;
public:
	Stack();
	void push_back(const T& value);
	void pop_back();
	bool is_empty();
	void print();
};