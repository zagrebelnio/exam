#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>

using namespace std;

class Set;

class DataStructure {
public:
	DataStructure() = default;
	virtual Set operation(Set other) = 0;
};

class Set : public DataStructure {
	static const int MAX_SIZE = 10;
	char data[MAX_SIZE] = {};
	int size = 0;
public:
	Set() = default;
	char operator[](int i);
	int get_size();
	void add(const char& value);
	void remove(const char& value);
	Set operation(Set other) override;
	bool is_full();
	string line();
	void show();
};

class File {
	string name = "output.txt";
public:
	File() = default;
	void write(Set& set1, Set& set2, Set& set3);
	void show();
};