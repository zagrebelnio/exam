#pragma once
#include <iostream>
#include <string>

using namespace std;

class Abitur {
	string lname;
	string fname;
	double rating;
public:
	Abitur() = default;
	Abitur(string lname, string fname, double rating);
	bool operator==(const Abitur& other);
	string get_lname();
	string get_fname();
	double get_rating();
	void show_info();
};

class List {
	struct Node {
		Abitur data;
		Node* next;
	};
	Node* head;
	int size;
public:
	List();
	void push_back(const Abitur& value);
	void pop(const Abitur& value);
	void lname_sort();
	void fname_sort();
	void rating_sort();
	void show();
	List modify();
};