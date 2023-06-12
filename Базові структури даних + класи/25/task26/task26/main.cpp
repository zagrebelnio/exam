#include "house.h"

int main() {
	Set set, dublicates;
	string city, street;
	int number;
	int num;
	cout << "Enter number of houses: ";
	cin >> num;
	cin.ignore();
	for (int i = 0; i < num; i++) {
		cout << "House " << i + 1 << endl;
		cout << "Enter city: ";
		getline(cin, city);
		cout << "Enter street: ";
		getline(cin, street);
		cout << "Enter number: ";
		cin >> number;
		cin.ignore();
		House house(city, street, number);
		if (set.contains(house)) {
			dublicates.add(house);
		}
		else {
			set.add(house);
		}
	}

	cout << endl;

	cout << "Set: " << endl;
	set.show();

	cout << endl;

	cout << "Dublicates: " << endl;
	dublicates.show();

	cout << endl;

	cout << "Please change the dublicates: " << endl;

	for (int i = 0; i < dublicates.get_size(); i++) {
		cout << "House " << i + 1 << endl;
		cout << "Enter city: ";
		getline(cin, city);
		cout << "Enter street: ";
		getline(cin, street);
		cout << "Enter number: ";
		cin >> number;
		cin.ignore();
		House house(city, street, number);
		set.add(house);
	}

	cout << endl;
	
	cout << "New set: " << endl;
	set.show();

	return 0;
}