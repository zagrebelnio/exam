#include "day.h"

Day::Day(int day, int month, int year, double wet) : day(day), month(month), year(year), wet(wet)
{
}

double Day::get_wet()
{
	return wet;
}

string Day::line()
{
	string line = "";
	line += to_string(day) + "/" + to_string(month) + "/" + to_string(year) + ": " + to_string(wet);
	return line;
}

void Day::show()
{
	cout << day << "/" << month << "/" << year << ": " << wet << endl;
}

Weather::Weather(int size, Day* days) : size(size)
{
	for (int i = 0; i < size; i++) {
		this->days[i] = days[i];
	}
}

Day Weather::max_wet()
{
	Day max(days[0]);
	for (int i = 1; i < size; i++) {
		if (days[i].get_wet() > max.get_wet()) {
			max = days[i];
		}
	}
	return max;
}

string Weather::text()
{
	string text = "";
	for (int i = 0; i < size; i++) {
		text += days[i].line() + "\n";
	}
	return text;
}

void Weather::show_info()
{
	for (int i = 0; i < size; i++) {
		days[i].show();
	}
}

void File::write(Weather weather)
{
	ofstream fout(name);
	fout << weather.text();
	fout << "\n";
	fout << weather.max_wet().line();
	fout.close();
}

void File::read()
{
	ifstream fin(name);
	string line;
	while (getline(fin, line)) {
		cout << line << endl;
	}
	fin.close();
}

bool day_valid(const int& day)
{
	if (day < 1 || day > 31) {
		return false;
	}
	return true;
}

bool month_valid(const int& month) {
	if (month < 1 || month > 12) {
		return false;
	}
	return true;
}

bool year_valid(const int& year) {
	if (year < 1 || year > 9999) {
		return false;
	}
	return true;
}

bool date_exists(const int& day, const int& month)
{
	if (((day > 30) && (month == 4 || month == 6 || month == 9 || month == 11)) || (day > 29 && month == 2)) {
		return false;
	}
	return true;
}
