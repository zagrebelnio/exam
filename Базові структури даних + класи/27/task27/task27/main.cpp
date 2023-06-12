#include "student.h"

int main() {
	List list;
	int num;
	cout << "Enter number of students: ";
	cin >> num;
	cin.ignore();

	string lname, fname;
	double rating;

	for (int i = 0; i < num; i++) {
		cout << "Student " << i + 1 << endl;
		cout << "Enter last name: ";
		getline(cin, lname);
		cout << "Enter first name: ";
		getline(cin, fname);
		cout << "Enter rating: ";
		cin >> rating;
		cin.ignore();
		Student student(lname, fname, rating);
		list.push_back(student);
	}

	cout << endl;

	cout << "List: " << endl;
	list.show();

	List modified = list.modify();

	cout << endl;

	cout << "Modified list: " << endl;
	modified.show();

	modified.sort_lname();

	cout << endl;

	cout << "Modified list sorted by last name: " << endl;
	modified.show();

	return 0;
}