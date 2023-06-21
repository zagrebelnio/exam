#include "set.h"

int main() {

	Set<int> set;

	cout << "<---Set manager--->" << endl;
	cout << "1. Add element to set" << endl;
	cout << "2. Remove element from set" << endl;
	cout << "3. Check if set is empty" << endl;
	cout << "4. Check if set is full" << endl;
	cout << "5. Clear set" << endl;
	cout << "6. Print set" << endl;
	cout << "0. Exit" << endl;

	bool go_on = true;
	int choice, value;
	while (go_on) {
		
		cout << "Your choice: ";
		cin >> choice;
		cin.ignore();
		switch (choice) {
		case 1:
			int value;
			cout << "Enter element: ";
			cin >> value;
			cin.ignore();
			set.add(value);
			break;
		case 2:
			cout << "Enter element: ";
			cin >> value;
			cin.ignore();
			set.pop(value);
			break;
		case 3:
			if (set.is_empty()) {
				cout << "Set is empty!" << endl;
			}
			else {
				cout << "Set is not empty!" << endl;
			}
			break;
		case 4:
			if (set.is_full()) {
				cout << "Set is full!" << endl;
			}
			else {
				cout << "Set is not full!" << endl;
			}
			break;
		case 5:
			set.clear();
			cout << "Set was cleared." << endl;
			break;
		case 6:
			cout << "Set: ";
			set.print();
			break;
		default:
			go_on = false;
			break;
		}
	}

	return 0;
}