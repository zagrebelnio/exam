#pragma once
#include <iostream>
#include <string>

using namespace std;

class Student {
	string last_name;
	string first_name;
	double rating;
public:
	Student() = default;
	Student(string last, string first, double rating);
	string get_lname();
	string get_fname();
	double get_rating();
	void show_info();
};

class List {
	struct Node {
		Student data;
		Node* next;
	};
	Node* head;
	int size;
public:
	List();
	void push_back(const Student& value);
	bool find_lname(Student value);
	bool find_fname(Student value);
	bool find_rating(Student value);
	void sort_lname();
	void sort_fname();
	void sort_rating();
	void show();
	List modify();
};