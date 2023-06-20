#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Set {
	vector<int> data;
	bool exists(const int& num);
public:
	Set();
	Set operator+(Set other);
	Set operator*(Set other);
	Set operator/(Set other);
	void insert(const int& num);
	void pop(const int& num);
	void show();
	string line();
};

class File {
	string name;
public:
	File(string name);
	void write(Set set);
	void read();
};