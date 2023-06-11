#include "queue.h"

int main() {
	Queue queue;
	string name;
	do {
		cout << "Enter name: ";
		getline(cin, name);
		queue.push_back(name);
		cout << "Continue? (y/n) ";
		getline(cin, name);
	} while (name != "n");

	cout << "Queue: ";
	queue.show();
	
	int minutes;
	cout << "Minutes: ";
	cin >> minutes;

	for (int i = 0; i < minutes / 2; i++) {
		queue.pop_front();
	}

	for (int i = 0; i < minutes / 5; i++) {
		queue.pop_back();
	}

	cout << "Queue after " << minutes << " minutes: ";
	queue.show();

	return 0;
}