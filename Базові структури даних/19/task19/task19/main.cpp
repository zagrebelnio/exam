#include "list.h"

int main() {
	List list;
	int num;
	string choice;
	do {
		cout << "Enter number: ";
		cin >> num;
		list.push_back(num);
		cin.ignore();
		cout << "Continue? (y/n) ";
		getline(cin, choice);
	} while (choice != "n");

	int min = list.min();
	int max = list.max();

	double average = double((min + max)) / 2;
	double median = list.median();

	list.show();
	cout << "Min: " << min << endl;
	cout << "Max: " << max << endl;
	cout << "Average between min and max: " << average << endl;
	cout << "Median: " << median << endl;

	if (average > median) {
		cout << average << " > " << median << endl;
	}
	else if (average == median) {
		cout << average << " = " << median << endl;
	}
	else {
		cout << average << " < " << median << endl;
	}
	
	return 0;
}