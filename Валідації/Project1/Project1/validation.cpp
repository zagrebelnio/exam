#include "validation.h"

int valid_int()
{
	string line;
	getline(cin, line);
	for (char c : line) {
		if (!isdigit(c)) {
			throw exception("Wrong int input!");
		}
	}
	return stoi(line);
}

double valid_double()
{
	string line;
	getline(cin, line);
	size_t pos;
	double value = stod(line, &pos);
	if (pos != line.length()) {
		throw invalid_argument("Invalid input. Extra characters found after the number.");
	}
	return value;
}
