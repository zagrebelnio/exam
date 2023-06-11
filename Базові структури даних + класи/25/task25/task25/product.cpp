#include "product.h"

Product::Product(string name, int year) : name(name), year(year)
{
}

string Product::get_name()
{
	return name;
}

int Product::get_year()
{
	return year;
}

List::List() : head(nullptr), size(0)
{
}

void List::push_back(const Product& product)
{
	if (head == nullptr) {
		head = new Node{ product, nullptr };
	}
	else {
		Node* current = head;
		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = new Node{ product, nullptr };
	}
	size++;
}

bool List::find_name(const string& name)
{
	Node* current = head;
	while (current != nullptr) {
		if (current->data.get_name() == name) {
			return true;
		}
		current = current->next;
	}
	return false;
}

bool List::find_year(const int& year)
{
	Node* current = head;
	while (current != nullptr) {
		if (current->data.get_year() == year) {
			return true;
		}
		current = current->next;
	}
	return false;
}

void List::name_sort()
{
	Product* product = new Product[size];
	Node* current = head;
	int i = 0;
	while (current != nullptr) {
		product[i] = current->data;
		current = current->next;
		i++;
	}

	for (int j = 0; j < size - 1; j++) {
		for (int k = 0; k < size - j - 1; k++) {
			if (product[k].get_name() > product[k + 1].get_name()) {
				Product temp = product[k];
				product[k] = product[k + 1];
				product[k + 1] = temp;
			}
		}
	}

	current = head;
	i = 0;
	while (current != nullptr) {
		current->data = product[i];
		current = current->next;
		i++;
	}
}

void List::year_sort()
{
	Product* product = new Product[size];
	Node* current = head;
	int i = 0;
	while (current != nullptr) {
		product[i] = current->data;
		current = current->next;
		i++;
	}

	for (int j = 0; j < size - 1; j++) {
		for (int k = 0; k < size - j - 1; k++) {
			if (product[k].get_year() > product[k + 1].get_year()) {
				Product temp = product[k];
				product[k] = product[k + 1];
				product[k + 1] = temp;
			}
		}
	}

	current = head;
	i = 0;
	while (current != nullptr) {
		current->data = product[i];
		current = current->next;
		i++;
	}
}

void List::show()
{
	Node* current = head;
	int i = 1;
	while (current != nullptr) {
		cout << "Product " << i << endl;
		cout << "Name: " << current->data.get_name() << endl;
		cout << "Year: " << current->data.get_year() << endl;
		current = current->next;
		i++;
	}
}

List List::modify(const string& value)
{
	List modified;
	Node* current = head;
	while (current != nullptr) {
		if (current->data.get_name() == value) {
			modified.push_back(current->data);
		}
		current = current->next;
	}
	return modified;
}
