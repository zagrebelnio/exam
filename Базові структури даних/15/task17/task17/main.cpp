#include "queue.h"

int main() {
	Queue queue;
	string num;
	string choice;
	do {
		cout << "Enter a number: ";
		getline(cin, num);
		queue.push(stoi(num));
		cout << "Continue? (y/n) ";
		getline(cin, choice);
	} while (choice != "n");
	cout << "Queue: ";
	queue.show();
	cout << "Enter mark: ";
	getline(cin, num);
	int counter = queue.modify(stoi(num));
	cout << "Modified queue: ";
	queue.show();
	cout << "Number of students with mark " << num << " is " << counter << endl;

	return 0;
}