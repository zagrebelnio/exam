#pragma once
#include <iostream>
#include <string>

using namespace std;

class Function {
	double k;
	double b;
public:
	Function() = default;
	Function(double k, double b);
	bool operator==(const Function& other);
	double getK();
	double getB();
	void moveOY(double value);
	void show_info();
};

class Set {
	static const int MAX_SIZE = 100;
	Function elements[MAX_SIZE] = {};
	int size = 0;
public:
	void add(const Function& func);
	bool contains(const Function& func);
	void modify(const Function& func, const double& value);
	bool is_full();
	void show();
};
