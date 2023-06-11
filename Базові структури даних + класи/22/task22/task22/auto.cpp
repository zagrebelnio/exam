#include "auto.h"

Auto::Auto(string mark, int year, int speed) : mark(mark), year(year), speed(speed)
{
}

string Auto::get_mark()
{
	return mark;
}

int Auto::get_year()
{
	return year;
}

int Auto::get_speed()
{
	return speed;
}

void Auto::show_info()
{
	cout << "Mark: " << mark << endl;
	cout << "Year: " << year << endl;
	cout << "Max Speed: " << speed << endl;
}

List::List() : head(nullptr), size(0)
{
}

void List::push_back(const Auto& car)
{
	if (head == nullptr) {
		head = new Node{ car, nullptr };
	}
	else {
		Node* current = head;
		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = new Node{ car, nullptr };
	}
	size++;
}

Auto List::max_mark()
{
	Node* current = head;
	Auto car = current->data;
	while (current != nullptr) {
		if (current->data.get_mark() > car.get_mark()) {
			car = current->data;
		}
		current = current->next;
	}
	return car;
}

Auto List::max_year()
{
	Node* current = head;
	Auto car = current->data;
	while (current != nullptr) {
		if (current->data.get_year() > car.get_year()) {
			car = current->data;
		}
		current = current->next;
	}
	return car;
}

Auto List::max_speed()
{
	Node* current = head;
	Auto car = current->data;
	while (current != nullptr) {
		if (current->data.get_speed() > car.get_speed()) {
			car = current->data;
		}
		current = current->next;
	}
	return car;
}

Auto List::min_mark()
{
	Node* current = head;
	Auto car = current->data;
	while (current != nullptr) {
		if (current->data.get_mark() < car.get_mark()) {
			car = current->data;
		}
		current = current->next;
	}
	return car;
}

Auto List::min_year()
{
	Node* current = head;
	Auto car = current->data;
	while (current != nullptr) {
		if (current->data.get_year() < car.get_year()) {
			car = current->data;
		}
		current = current->next;
	}
	return car;
}

Auto List::min_speed()
{
	Node* current = head;
	Auto car = current->data;
	while (current != nullptr) {
		if (current->data.get_speed() < car.get_speed()) {
			car = current->data;
		}
		current = current->next;
	}
	return car;
}

void List::show()
{
	Node* current = head;
	int i = 1;
	while (current != nullptr) {
		cout << "Car " << i << ":" << endl;
		current->data.show_info();
		current = current->next;
		i++;
	}
}

List List::modify(const int& year)
{
	List modified;

	Node* current = head;
	while (current != nullptr) {
		if (current->data.get_year() == year) {
			modified.push_back(current->data);
		}
		current = current->next;
	}

	return modified;
}

void compare_cars(Auto& car1, Auto& car2)
{
	if (car1.get_mark() > car2.get_mark()) {
		cout << car1.get_mark() << " > " << car2.get_mark() << endl;
	}
	else if (car1.get_mark() == car2.get_mark()) {
		cout << car1.get_mark() << " = " << car2.get_mark() << endl;
	}
	else {
		cout << car1.get_mark() << " < " << car2.get_mark() << endl;
	}
	if (car1.get_year() > car2.get_year()) {
		cout << car1.get_year() << " > " << car2.get_year() << endl;
	}
	else if (car1.get_year() == car2.get_year()) {
		cout << car1.get_year() << " = " << car2.get_year() << endl;
	}
	else {
		cout << car1.get_year() << " < " << car2.get_year() << endl;
	}
	if (car1.get_speed() > car2.get_speed()) {
		cout << car1.get_speed() << " > " << car2.get_speed() << endl;
	}
	else if (car1.get_speed() == car2.get_speed()) {
		cout << car1.get_speed() << " = " << car2.get_speed() << endl;
	}
	else {
		cout << car1.get_speed() << " < " << car2.get_speed() << endl;
	}
}