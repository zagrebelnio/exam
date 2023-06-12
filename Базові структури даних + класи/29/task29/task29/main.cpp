#include "abitur.h"

int main() {
	List list;
	int num;
	cout << "Enter number of abitur: ";
	cin >> num;
	cin.ignore();
	string lname, fname;
	double rating;
	for (int i = 0; i < num; i++) {
		cout << "Abitur " << i + 1 << endl;
		cout << "Enter last name: ";
		getline(cin, lname);
		cout << "Enter first name: ";
		getline(cin, fname);
		cout << "Enter rating: ";
		cin >> rating;
		cin.ignore();
		Abitur abitur(lname, fname, rating);
		list.push_back(abitur);
	}

	cout << endl;

	cout << "List: " << endl;
	list.show();

	List modified = list.modify();

	cout << endl;
	
	cout << "Modified list: " << endl;
	modified.show();

	cout << endl;
	
	cout << "Sorted modified list: " << endl;
	modified.lname_sort();
	modified.show();

	return 0;
}