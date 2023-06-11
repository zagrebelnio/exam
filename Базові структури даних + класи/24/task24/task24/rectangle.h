#pragma once
#include <iostream>
#include <string>

using namespace std;

class Rectangle {
	double width;
	double height;
public:
	Rectangle() = default;
	Rectangle(double width, double height);
	double get_width();
	double get_height();
	double area();
	string line();
};

class List {
	struct Node {
		Rectangle data;
		Node* next;
	};
	Node* head;
	int size;
public:
	List();
	void push_back(const Rectangle& rect);
	bool find_width(const double& value);
	bool find_height(const double& value);
	Rectangle min_width();
	Rectangle min_height();
	Rectangle max_width();
	Rectangle max_height();
	void area_sort();
	void show();
	Rectangle end();
	void check_rects(const double& value);
};