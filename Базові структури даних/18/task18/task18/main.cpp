#include "set.h"

int main() {
	Set set;
	string line;
	cout << "Enter the line: ";
	getline(cin, line);
	for (char c : line) {
		set.add(c);
	}
	cout << "Set: ";
	set.show();
	Set new_set;
	new_set = set.dublicates();
	cout << "Dublicates set: ";
	new_set.show();
	char c;
	cout << "Enter the char: ";
	cin >> c;
	if (new_set.contains(c)) {
		cout << "The new set contains char '" << c << "'." << endl;
	}
	else {
		cout << "The new set doesn't contain char '" << c << "'." << endl;
	}

	return 0;
}