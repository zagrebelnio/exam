#pragma once
#include <iostream>
#include <string>

using namespace std;

class Book {
	string name;
	string author;
	string year;
public:
	Book(string name = "", string author = "", string year = "");
	string get_name();
	string get_author();
	string get_year();
	void show_info();
};

class List {
	struct Node {
		Book data;
		Node* next;
	};
	Node* head;
	int size;
public:
	List();
	void push_back(Book& book);
	bool find_name(const string& name);
	bool find_author(const string& author);
	bool find_year(const string& year);
	void show();
	List modify();
};