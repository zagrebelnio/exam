#include "tree.h"

int main() {
	Tree tree;
	int num;
	cout << "Enter number of numbers: ";
	cin >> num;
	cin.ignore();
	int element;
	int* array = new int[num];
	for (int i = 0; i < num; i++) {
		cout << "Enter number " << i + 1 << ": ";
		cin >> element;
		cin.ignore();
		array[i] = element;
	}

	cout << endl;

	cout << "Array: ";
	for (int i = 0; i < num; i++) {
		cout << array[i] << " ";
	}

	cout << endl << endl;

	for (int i = 0; i < num; i++) {
		tree.add(array[i]);
	}

	cout << "Tree: ";
	tree.show();
	cout << endl << endl;

	int left_sum = tree.left_sum();
	int right_sum = tree.right_sum();

	cout << "Tree left sum: " << left_sum << endl;
	cout << "Tree right sum: " << right_sum << endl;

	if (left_sum < right_sum) {
		cout << left_sum << " < " << right_sum << endl;
	}
	else if (left_sum == right_sum) {
		cout << left_sum << " = " << right_sum << endl;
	}
	else {
		cout << left_sum << " > " << right_sum << endl;
	}

	return 0;
}