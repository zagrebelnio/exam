#include "student.h"

Student::Student(string last, string first, double rating) : last_name(last), first_name(first), rating(rating)
{
}

string Student::get_lname()
{
	return last_name;
}

string Student::get_fname()
{
	return first_name;
}

double Student::get_rating()
{
	return rating;
}

void Student::show_info()
{
	cout << "Last name: " << last_name << endl;
	cout << "First name: " << first_name << endl;
	cout << "Rating: " << rating << endl;
}

List::List() : head(nullptr), size(0)
{
}

void List::push_back(const Student& value)
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

bool List::find_lname(Student value)
{
	Node* current = head;
	while (current != nullptr) {
		if (current->data.get_lname() == value.get_lname()) {
			return true;
		}
		current = current->next;
	}
	return false;
}

bool List::find_fname(Student value)
{
	Node* current = head;
	while (current != nullptr) {
		if (current->data.get_fname() == value.get_fname()) {
			return true;
		}
		current = current->next;
	}
	return false;
}

bool List::find_rating(Student value)
{
	Node* current = head;
	while (current != nullptr) {
		if (current->data.get_rating() == value.get_rating()) {
			return true;
		}
		current = current->next;
	}
	return false;
}

void List::sort_lname()
{
	Student* students = new Student[size];
	Node* current = head;
	int i = 0;
	while (current != nullptr) {
		students[i] = current->data;
		current = current->next;
		i++;
	}

	for (int j = 0; j < size - 1; j++) {
		for (int k = 0; k < size - j - 1; k++) {
			if (students[k].get_lname() > students[k + 1].get_lname()) {
				Student temp = students[k];
				students[k] = students[k + 1];
				students[k + 1] = temp;
			}
		}
	}

	current = head;
	i = 0;
	while (current != nullptr) {
		current->data = students[i];
		current = current->next;
		i++;
	}
}

void List::sort_fname()
{
	Student* students = new Student[size];
	Node* current = head;
	int i = 0;
	while (current != nullptr) {
		students[i] = current->data;
		current = current->next;
		i++;
	}

	for (int j = 0; j < size - 1; j++) {
		for (int k = 0; k < size - j - 1; k++) {
			if (students[k].get_fname() > students[k + 1].get_fname()) {
				Student temp = students[k];
				students[k] = students[k + 1];
				students[k + 1] = temp;
			}
		}
	}

	current = head;
	i = 0;
	while (current != nullptr) {
		current->data = students[i];
		current = current->next;
		i++;
	}
}

void List::sort_rating()
{
	Student* students = new Student[size];
	Node* current = head;
	int i = 0;
	while (current != nullptr) {
		students[i] = current->data;
		current = current->next;
		i++;
	}

	for (int j = 0; j < size - 1; j++) {
		for (int k = 0; k < size - j - 1; k++) {
			if (students[k].get_rating() > students[k + 1].get_rating()) {
				Student temp = students[k];
				students[k] = students[k + 1];
				students[k + 1] = temp;
			}
		}
	}

	current = head;
	i = 0;
	while (current != nullptr) {
		current->data = students[i];
		current = current->next;
		i++;
	}
}

void List::show()
{
	Node* current = head;
	int i = 1;
	while (current != nullptr) {
		cout << "Student " << i << endl;
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
		if (current->data.get_rating() > 85) {
			modified.push_back(current->data);
		}
		current = current->next;
	}
	return modified;
}
