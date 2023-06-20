#include "tree.h"

int main() {

	vector<int> vector = { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };

	cout << "Vector before sorting: ";
	for (int i = 0; i < vector.size(); i++) {
		cout << vector[i] << " ";
	}
	cout << endl;
	
	sort(vector.begin(), vector.end());

	cout << "Vector after sorting: ";
	for (int i = 0; i < vector.size(); i++) {
		cout << vector[i] << " ";
	}
	cout << endl;

	Stack<char> stack;

	string line = "hello";

	for (int i = 0; i < 5; i++) {
		stack.push_back(line[i]);
	}
	stack.print();

	for (int i = 0; i < 3; i++) {
		stack.pop_back();
	}
	stack.print();

	return 0;
}