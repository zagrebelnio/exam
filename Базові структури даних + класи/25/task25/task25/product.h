#pragma once
#include <iostream>
#include <string>

using namespace std;

class Product {
	string name;
	int year;
public:
	Product() = default;
	Product(string name, int year);
	string get_name();
	int get_year();
};

class List {
	struct Node {
		Product data;
		Node* next;
	};
	Node* head;
	int size;
public:
	List();
	void push_back(const Product& product);
	bool find_name(const string& name);
	bool find_year(const int& year);
	void name_sort();
	void year_sort();
	void show();
	List modify(const string& value);
};