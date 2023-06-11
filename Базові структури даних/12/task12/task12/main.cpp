#include "queue.h"

int main() {
	Queue myQueue;
	bool enter = true;
	while (enter) {
		string name;
		cout << "Name: ";
		getline(cin, name);
		myQueue.push(name);
		cout << "Continue? y/n ";
		string choice;
		getline(cin, choice);
		if (choice == "n") {
			enter = false;
		}
	}
	cout << "People in the queue: ";
	myQueue.show();
	int minutes;
	cout << "Minutes: ";
	cin >> minutes;
	for (int i = 0; i < minutes / 3; i++) {
		myQueue.pop();
	}
	cout << "People in queue after " << minutes << " minutes: ";
	myQueue.show();
	return 0;
}