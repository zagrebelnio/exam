#include "function.h"

int main() {
	Set set;
	int num;
	cout << "Enter number of functions: ";
	cin >> num;
	double k, b;
	for (int i = 0; i < num; i++) {
		cout << "Function " << i + 1 << endl;
		cout << "Enter coef k: ";
		cin >> k;
		cin.ignore();
		cout << "Enter coef b: ";
		cin >> b;
		cin.ignore();
		Function func(k, b);
		set.add(func);
	}

	cout << endl;

	cout << "Set: " << endl;
	set.show();

	cout << endl;

	cout << "Enter function to modify: " << endl;
	cout << "Enter coef k: ";
	cin >> k;
	cin.ignore();
	cout << "Enter coef b: ";
	cin >> b;
	cin.ignore();
	Function func(k, b);

	cout << "Enter value to move function by OY: ";
	cin >> b;
	cin.ignore();

	if (set.contains(func)) {
		set.modify(func, b);
	}

	cout << endl;
	cout << "Modified set: " << endl;
	set.show();

	return 0;
}