#include "list.h"

int main() {
	List list;
	string line;
	cout << "Enter the line: ";
	getline(cin, line);

	for (char c : line) {
		list.push_back(c);
	}
	cout << "List: ";
	list.show();

	list.sort();
	cout << "Sorted list: ";
	list.show();

	cout << "Line of odd elements: " << list.odd_elements();

	return 0;
}