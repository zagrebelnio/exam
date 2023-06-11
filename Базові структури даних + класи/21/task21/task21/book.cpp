#include "book.h"

Book::Book(string name, string author, string year) : name(name), author(author), year(year)
{
}

string Book::get_name()
{
	return name;
}

string Book::get_author()
{
	return author;
}

string Book::get_year()
{
	return year;
}

void Book::show_info()
{
	cout << "Name: " << name << endl;
	cout << "Author: " << author << endl;
	cout << "Year: " << year << endl;
}

List::List() : head(nullptr), size(0)
{
}

void List::push_back(Book& book)
{
	if (head == nullptr) {
		head = new Node{ book, nullptr };
	}
	else {
		Node* current = head;
		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = new Node{ book, nullptr };
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

bool List::find_author(const string& author)
{
	Node* current = head;
	while (current != nullptr) {
		if (current->data.get_author() == author) {
			return true;
		}
		current = current->next;
	}
	return false;
}

bool List::find_year(const string& year)
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

void List::show()
{
	Node* current = head;
	int i = 1;
	while (current != nullptr) {
		cout << "Book " << i << ": " << endl;
		current->data.show_info();
		current = current->next;
		i++;
	}
}

List List::modify()
{
	List modified;
	Node* current = head;
	while (current != nullptr) {
		if (current->data.get_name().empty()) {
			if (current->data.get_author().empty() && !current->data.get_year().empty()) {
				modified.push_back(current->data);
			}
			else if (!current->data.get_author().empty() && current->data.get_year().empty()) {
				modified.push_back(current->data);
			}
		}
		current = current->next;
	}
	return modified;
}
