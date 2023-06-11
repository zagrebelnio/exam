#pragma once
#include <iostream>
#include <string>

using namespace std;

class Auto {
	string mark;
	int year;
	int speed;
public:
	Auto(string mark, int year, int speed);
	string get_mark();
	int get_year();
	int get_speed();
	void show_info();
};

class List {
	struct Node {
		Auto data;
		Node* next;
	};
	Node* head;
	int size;
public:
	List();
	void push_back(const Auto& car);
	Auto max_mark();
	Auto max_year();
	Auto max_speed();
	Auto min_mark();
	Auto min_year();
	Auto min_speed();
	void show();
	List modify(const int& year);
};

void compare_cars(Auto& car1, Auto& car2);