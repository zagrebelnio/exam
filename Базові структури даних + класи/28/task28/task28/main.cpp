#include "fruit.h"

int main() {
	List list;
	int num;
	cout << "Enter number of fruits: ";
	cin >> num;
	cin.ignore();
	string name, color;
	double callories;
	for (int i = 0; i < num; i++) {
		cout << "Fruit " << i + 1 << endl;
		cout << "Enter name: ";
		getline(cin, name);
		cout << "Enter color: ";
		getline(cin, color);
		cout << "Enter callories: ";
		cin >> callories;
		cin.ignore();
		Fruit fruit(name, color, callories);
		list.push_back(fruit);
	}

	cout << endl;

	cout << "List: " << endl;
	list.show();

	cout << endl;

	cout << "Fruit with the minimum callories: " << endl;
	list.min().show_info();

	cout << endl;

	cout << "Fruit with the maximum callories: " << endl;
	list.max().show_info();

	return 0;
}