#include "stack.h"

int main() {
	Stack stack;
	string line;
	char c;
	cout << "Enter the line: ";
	getline(cin, line);
	cout << "Enter the symbol: ";
	cin >> c;
	for (char symbol : line) {
		if (stack.is_full()) {
			cout << "The stack is full!" << endl;
			break;
		}
		if (c == symbol) {
			stack.push(symbol);
		}
		stack.push(symbol);
	}
	cout << "Stack: ";
	stack.show();
	return 0;
}