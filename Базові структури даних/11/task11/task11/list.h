#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;

class List {
	struct Node {
		int data;
		Node* pNext;
	};
	Node* head;
	int size;
public:
	List();
	int get_size();
	void push_back(int num);
	bool find(int num);
	int min();
	int max();
	void sort();
	void show();
};