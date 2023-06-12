#include "tree.h"

int main() {
	Tree tree;
	int num;
	cout << "Enter number: ";
	cin >> num;
	cin.ignore();

	for (int i = 1; i <= num; i++) {
		if (num % i == 0) {
			tree.add(i);
		}
	}
	
	cout << "Tree: ";
	tree.show();

	cout << endl << endl;

	cout << "Enter another number: ";
	cin >> num;
	cin.ignore();

	if (tree.postOrder(num)) {
		cout << "The number " << num << " is a divider." << endl;
	}
	else {
		cout << "The number " << num << " is not a divider." << endl;
	}


	return 0;
}