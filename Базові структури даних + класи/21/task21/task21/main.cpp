#include "book.h"

int main() {
	List list;
	int num;
	cout << "Enter number of books: ";
	cin >> num;
	cin.ignore();
	string name, author, year;
	for (int i = 0; i < num; i++) {
		cout << "Book " << i + 1 << endl;
		cout << "Enter name: ";
		getline(cin, name);
		cout << "Enter author: ";
		getline(cin, author);
		cout << "Enter year: ";
		getline(cin, year);
		Book book(name, author, year);
		list.push_back(book);
	}
	cout << "List: " << endl;
	list.show();

	List modified = list.modify();

	cout << "Modified list: " << endl;
	modified.show();

	return 0;
}