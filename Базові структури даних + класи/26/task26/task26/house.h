#pragma once
#include <iostream>
#include <string>

using namespace std;

class House {
	string city;
	string street;
	int number;
public:
	House() = default;
	House(string city, string street, int number);
	bool operator==(const House& other);
	string get_city();
	string get_street();
	int get_number();
	void show_info();
};

class Set {
	static const int MAX_SIZE = 100;
	House elements[MAX_SIZE] = {};
	int size = 0;
public:
	void add(const House& value);
	void remove(const House& value);
	bool contains(const House& value);
	bool is_full();
	bool is_empty();
	int get_size();
	void show();
};