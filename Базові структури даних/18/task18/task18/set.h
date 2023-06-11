#pragma once
#include <iostream>
#include <string>

using namespace std;

class Set {
	static const int MAX_SIZE = 100;
	char elements[MAX_SIZE] = {};
	int size = 0;
public:
	void add(const char& c);
	void remove(const char& c);
	bool contains(const char& c);
	void show();
	bool is_full();
	bool is_empty();
	Set dublicates();
	bool check_dublicates(const char& c, int index);
};

