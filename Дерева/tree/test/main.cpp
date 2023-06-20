#include "tree.h"

int main() {
	srand(time(0));
	Tree tree;
	int size;
	cout << "Enter number of elements to add into the tree: ";
	cin >> size;
	cin.ignore();

	cout << endl << "Generated numbers: ";

	for (int i = 0; i < size; i++) {
		int num = generate_number(1, 20);
		cout << num << " ";
		tree.add(num);
	}

	cout << endl << "Tree: ";
	tree.show();

	int value;
	cout << endl << "Enter element to delete: ";
	cin >> value;
	cin.ignore();

	tree.pop(value);

	cout << endl << "Tree: ";
	tree.show();

	return 0;
}