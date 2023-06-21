#pragma once
#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Set {
	static const int MAX_SIZE = 10;
	T data[MAX_SIZE] = {};
	int top = -1;
public:
	Set() = default;
	int size();
	void add(const T& value);
	void pop(const T& value);
	bool is_empty();
	bool is_full();
	void clear();
	void print();
};