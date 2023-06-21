#include "validation.h"

int main() {

	cout << "<---Validation manager--->" << endl;
	cout << "1. Int validation" << endl;
	cout << "2. Double validation" << endl;
	cout << "3. Exit" << endl;

	bool go_on = true;

	while (go_on) {
		try {
			int choice;
			cout << "Your choice: ";
			cin >> choice;
			cin.ignore();
			switch (choice) {
			case 1:
				cout << "Enter int value: ";
				valid_int();
				break;
			case 2:
				cout << "Enter double value: ";
				valid_double();
				break;
			default:
				go_on = false;
				break;
			}
		}
		catch (const exception& e) {
			cerr << "Error! " << e.what() << endl;
		}
	}

	return 0;
}