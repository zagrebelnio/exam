#include "stack.h"

int main() {
	int type;

	cout << "Choose the data type of stack: " << endl;
	cout << "1. int" << endl;
	cout << "2. double" << endl;
	cout << "3. char" << endl;
	cout << "4. string" << endl;

	cin >> type;
	cin.ignore();

	switch (type) {
	case 1:
		processStack<int>();
		break;
	case 2:
		processStack<double>();
		break;
	case 3:
		processStack<char>();
		break;
	case 4:
		processStack<string>();
		break;
	}
	return 0;
}