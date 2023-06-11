#include "product.h"

int main() {
	List list;
	int num;
	cout << "Enter number of products: ";
	cin >> num;
	cin.ignore();
	string name;
	int year;
	for (int i = 0; i < num; i++) {
		cout << "Product " << i + 1 << endl;
		cout << "Enter name: ";
		getline(cin, name);
		cout << "Enter year: ";
		cin >> year;
		cin.ignore();
		Product product(name, year);
		list.push_back(product);
	}
	cout << "List: " << endl;
	list.show();
	cout << "Enter name: ";
	getline(cin, name);

	List modified = list.modify(name);

	cout << "Modified list: " << endl;
	modified.show();

	cout << "Year sorted modified list: " << endl;
	modified.year_sort();
	modified.show();

	return 0;
}