#include "stack.h"

int main() {
	Stack stack;
	string line;
	string choice;
	do {
		cout << "Enter line: ";
		getline(cin, line);
		stack.push(line);
		cout << "Continue? (y/n) ";
		getline(cin, choice);
	} while (choice != "n");
	cout << "Stack: ";
	stack.show();
	stack.modify();
	cout << "Modified stack: ";
	stack.show();
	return 0;
}