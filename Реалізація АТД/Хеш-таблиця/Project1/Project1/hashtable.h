#pragma once
#include <iostream>
#include <string>
#include <list>
#include <cstring>

using namespace std;

class HashTable {
	static const int size = 10;
	list <pair<int, string>> table[size];
	int hash_function(int key);
public:
	bool is_empty() const;
	void insert(int key, string value);
	void remove(int key);
	bool search(int key, string& value);
	void clear();
	void print();
};