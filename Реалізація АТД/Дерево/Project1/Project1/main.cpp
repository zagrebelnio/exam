#include "tree.h"

int main() {
	srand(time(0));

	Tree<int> tree;
	int array[10];

	for (int i = 0; i < 10; i++) {
		array[i] = generate_number(1, 99);
	}

	cout << "Generated array: ";
	for (int i = 0; i < 10; i++) {
		cout << array[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < 10; i++) {
		tree.add(array[i]);
	}

	cout << "Tree: ";
	tree.show();
	cout << endl;

	cout << "<---Tree manager--->" << endl;
	cout << "1. Add element to tree" << endl;
	cout << "2. Remove element to tree" << endl;
	cout << "3. Clear the tree" << endl;
	cout << "4. Print the tree" << endl;
	cout << "0. Exit" << endl;

	bool go_on = true;

	while (go_on) {
		int choice, value;
		cout << "Your choice: ";
		cin >> choice;
		cin.ignore();
		switch (choice) {
		case 1:
			cout << "Enter value: ";
			cin >> value;
			cin.ignore();
			tree.add(value);
			cout << "Element was added." << endl;
			break;
		case 2:
			cout << "Enter value: ";
			cin >> value;
			cin.ignore();
			tree.remove(value);
			cout << "Element was removed." << endl;
			break;
		case 3:
			tree.clear();
			cout << "Tree was cleared." << endl;
			break;
		case 4:
			cout << "Tree: ";
			tree.show();
			cout << endl;
			break;
		default:
			go_on = false;
			break;
		}
	}

	return 0;
}