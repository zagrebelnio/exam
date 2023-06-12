#include "tree.h"

int main() {
	srand(time(0));
	Tree tree;
	int n;
	cout << "Enter number of elements of array: ";
	cin >> n;
	cin.ignore();
	int* array = new int[n];
	for (int i = 0; i < n; i++) {
		array[i] = generate_number(-50, 50);
	}
	cout << endl;
	cout << "Generated array: ";
	for (int i = 0; i < n; i++) {
		cout << array[i] << " ";
	}
	cout << endl << endl;;
	
	for (int i = 0; i < n; i++) {
		tree.add(array[i]);
	}

	cout << "Tree: ";
	tree.show();
	cout << endl << endl;

	int counter = 0;
	cout << "Inorder search: ";
	tree.inOrder(counter);
	cout << endl << "Number of negative numbers: " << counter << endl;

	return 0;
}