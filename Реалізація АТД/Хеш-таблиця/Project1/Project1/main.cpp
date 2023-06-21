#include "hashtable.h"

int main() {

	HashTable table;

	cout << "<---Hash table manager--->" << endl;
	cout << "1. Insert value to the table" << endl;
	cout << "2. Remove element from the table" << endl;
	cout << "3. Search element in the table" << endl;
	cout << "4. Chech if the table is empty" << endl;
	cout << "5. Print the table" << endl;
	cout << "6. Clear the table" << endl;
	cout << "0. Exit" << endl;

	bool go_on = true;

	while (go_on) {
		int choice;
		cout << "Your choice: ";
		cin >> choice;
		cin.ignore();
		int key;
		string value;
		string enter;
		switch (choice) {
		case 1:
			do {
				cout << "Enter key: ";
				cin >> key;
				cin.ignore();
				cout << "Enter value: ";
				getline(cin, value);
				table.insert(key, value);
				cout << "Enter another one? (y/n) ";
				getline(cin, enter);
			} while (enter != "n");
			break;
		case 2:
			cout << "Enter key: ";
			cin >> key;
			cin.ignore();
			table.remove(key);
			break;
		case 3:
			cout << "Enter key: ";
			cin >> key;
			cin.ignore();
			if (table.search(key, value)) {
				cout << "The value is: " << value << endl;
			}
			else {
				cout << "Key not found." << endl;
			}
			break;
		case 4:
			if (table.is_empty()) {
				cout << "Table is empty!" << endl;
			}
			else {
				cout << "Table is not empty!" << endl;
			}
			break;
		case 5:
			cout << "<---HashTable--->" << endl;
			table.print();
			break;
		case 6:
			table.clear();
			cout << "Table was cleared." << endl;
			break;
		default: 
			go_on = false;
			break;
		}
	}

	return 0;
}