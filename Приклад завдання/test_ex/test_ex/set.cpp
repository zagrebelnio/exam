#include "set.h"

bool Set::exists(const int& num)
{
	for (int i = 0; i < data.size(); i++) {
		if (data[i] == num) {
			return true;
		}
	}
	return false;
}

Set::Set()
{
	data = {};
}

Set Set::operator+(Set other)
{
	Set new_set = other;

	for (int i = 0; i < data.size(); i++) {
		if (!new_set.exists(data[i])) {
			new_set.insert(data[i]);
		}
	}

	return new_set;
}

Set Set::operator*(Set other)
{
	Set new_set;

	for (int i = 0; i < data.size(); i++) {
		for (int j = 0; j < other.data.size(); j++) {
			if (data[i] == other.data[j]) {
				new_set.insert(data[i]);
				break;
			}
		}
	}

	return new_set;
}

Set Set::operator/(Set other)
{
	Set new_set;

	for (int i = 0; i < data.size(); i++) {
		if (!other.exists(data[i])) {
			new_set.insert(data[i]);
		}
	}

	return new_set;
}

void Set::insert(const int& num)
{
	if (data.size() == 0) {
		data.push_back(num);
		return;
	}
	if (!exists(num)) {
		for (int i = 0; i < data.size(); i++) {
			if (num < data[i]) {
				data.insert(data.begin() + i, num);
				return;
			}
		}
		data.push_back(num);
	}
}

void Set::pop(const int& num)
{
	for (int i = 0; i < data.size(); i++) {
		if (data[i] == num) {
			for (int j = i; j < data.size() - 1; j++) {
				data[j] = data[j + 1];
			}
			data.pop_back();
			return;
		}
	}
}

void Set::show()
{
	for (int i = 0; i < data.size(); i++) {
		cout << data[i] << " ";
	}
	cout << endl;
}

string Set::line()
{
	string line = "";
	for (int i = 0; i < data.size(); i++) {
		line += to_string(data[i]);
		line += " ";
	}
	return line;
}

File::File(string name) : name(name)
{
}

void File::write(Set set)
{
	ofstream fout(name, ios::app);
	fout << set.line() << endl;
}

void File::read()
{
	ifstream fin(name);
	string line;
	while (getline(fin, line)) {
		cout << line << endl;
	}
}
