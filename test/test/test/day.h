#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Day {
	int day;
	int month;
	int year;
	double wet;
public:
	Day() = default;
	Day(int day, int month, int year, double wet);
	double get_wet();
	string line();
	void show();
};

class Weather {
	int size;
	Day* days = new Day[size];
public:
	Weather(int size, Day* days);
	Day max_wet();
	string text();
	void show_info();
};

class File {
	string name = "output.txt";
public:
	void write(Weather weather);
	void read();
};

bool day_valid(const int& day);

bool month_valid(const int& month);

bool year_valid(const int& year);

bool date_exists(const int& day, const int& year);