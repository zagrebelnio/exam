#pragma once
#include <iostream>
#include <string>

using namespace std;

class Fruit {
	string name;
	string color;
	double callories;
public:
	Fruit() = default;
	Fruit(string name, string color, double callories);
	double get_callories();
	void show_info();
};

class List {
	struct Node {
		Fruit data;
		Node* next;
	};
	Node* head;
	int size;
public:
	List();
	void push_back(const Fruit& fruit);
	Fruit min();
	Fruit max();
	void show();
};