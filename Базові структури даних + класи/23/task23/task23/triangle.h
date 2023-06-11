#pragma once
#include <iostream>
#include <string>

using namespace std;

class Triangle {
	double a, b, c;
public:
	Triangle() = default;
	Triangle(double a, double b, double c);
	double getA();
	double getB();
	double getC();
	double perimeter();
	string line();
	double longest_side();
};

class List {
	struct Node {
		Triangle data;
		Node* next;
	};
	Node* head;
	int size;
public:
	List();
	void push_back(const Triangle& triangle);
	bool find_a(const double& a);
	bool find_b(const double& b);
	bool find_c(const double& c);
	void perimeter_sort();
	void show();
	Triangle end();
	void check_perimeters(const double& side);
};