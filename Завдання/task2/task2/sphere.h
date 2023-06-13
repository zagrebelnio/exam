#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#define PI 3.14159

using namespace std;

class Point {
public:
	Point() = default;
	virtual double area() = 0;
};

class Sphere : public Point {
	double radius;
public:
	Sphere() = default;
	Sphere(double radius);
	double area();
	void show();
	string line();
};

class File {
	string name = "output.txt";
public:
	void write(Sphere* spheres, int num);
	void read();
};