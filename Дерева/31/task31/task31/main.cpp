#include "tree.h"

int main() {
	Tree tree;
	string line;
	cout << "Enter line: ";
	getline(cin, line);
	for (char c : line) {
		tree.add(c);
	}
	cout << "Tree: ";
	tree.show();
	cout << endl;

	string new_line = "";
	tree.preOrder(new_line);

	cout << "Pre-order search: " << new_line << endl;

	new_line = "";
	tree.inOrder(new_line);

	cout << "In-order search: " << new_line << endl;

	return 0;
}