#include "abitur.h"

Abitur::Abitur(string lname, string fname, double rating) : lname(lname), fname(fname), rating(rating)
{
}

bool Abitur::operator==(const Abitur& other)
{
	if (lname == other.lname && fname == other.fname && rating == other.rating) {
		return true;
	}
	return false;
}

string Abitur::get_lname()
{
	return lname;
}

string Abitur::get_fname()
{
	return fname;
}

double Abitur::get_rating()
{
	return rating;
}

void Abitur::show_info()
{
	cout << "Last name: " << lname << endl;
	cout << "First name: " << fname << endl;
	cout << "Rating: " << rating << endl;
}

List::List() : head(nullptr), size(0)
{
}

void List::push_back(const Abitur& value)
{
	if (head == nullptr) {
		head = new Node{ value, nullptr };
	}
	else {
		Node* current = head;
		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = new Node{ value, nullptr };
	}
	size++;
}

void List::pop(const Abitur& value)
{
	Node* current = head;
	while (current != nullptr) {
		if (current->data == value) {
			Node* temp = current;
			current = head;
			while (current->next != temp) {
				current = current->next;
			}
			current->next = temp->next;
			delete temp;
			return;
		}
		current = current->next;
	}
}

void List::lname_sort()
{
	Abitur* abitur = new Abitur[size];
	Node* current = head;
	int i = 0;
	while (current != nullptr) {
		abitur[i] = current->data;
		current = current->next;
		i++;
	}

	for (int j = 0; j < size - 1; j++) {
		for (int k = 0; k < size - j - 1; k++) {
			if (abitur[k].get_lname() > abitur[k + 1].get_lname()) {
				Abitur temp = abitur[k];
				abitur[k] = abitur[k + 1];
				abitur[k + 1] = temp;
			}
		}
	}

	current = head;
	i = 0;
	while (current != nullptr) {
		current->data = abitur[i];
		current = current->next;
		i++;
	}
}

void List::fname_sort()
{
	Abitur* abitur = new Abitur[size];
	Node* current = head;
	int i = 0;
	while (current != nullptr) {
		abitur[i] = current->data;
		current = current->next;
		i++;
	}

	for (int j = 0; j < size - 1; j++) {
		for (int k = 0; k < size - j - 1; k++) {
			if (abitur[k].get_fname() > abitur[k + 1].get_fname()) {
				Abitur temp = abitur[k];
				abitur[k] = abitur[k + 1];
				abitur[k + 1] = temp;
			}
		}
	}

	current = head;
	i = 0;
	while (current != nullptr) {
		current->data = abitur[i];
		current = current->next;
		i++;
	}
}

void List::rating_sort()
{
	Abitur* abitur = new Abitur[size];
	Node* current = head;
	int i = 0;
	while (current != nullptr) {
		abitur[i] = current->data;
		current = current->next;
		i++;
	}

	for (int j = 0; j < size - 1; j++) {
		for (int k = 0; k < size - j - 1; k++) {
			if (abitur[k].get_rating() > abitur[k + 1].get_rating()) {
				Abitur temp = abitur[k];
				abitur[k] = abitur[k + 1];
				abitur[k + 1] = temp;
			}
		}
	}

	current = head;
	i = 0;
	while (current != nullptr) {
		current->data = abitur[i];
		current = current->next;
		i++;
	}
}

void List::show()
{
	Node* current = head;
	int i = 1;
	while (current != nullptr) {
		cout << "Abitur " << i << endl;
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
		if (current->data.get_rating() >= 50) {
			modified.push_back(current->data);
		}
		current = current->next;
	}
	return modified;
}
