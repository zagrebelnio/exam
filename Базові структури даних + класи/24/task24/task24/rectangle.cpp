#include "rectangle.h"

Rectangle::Rectangle(double width, double height) : width(width), height(height)
{
}

double Rectangle::get_width()
{
	return width;
}

double Rectangle::get_height()
{
	return height;
}

double Rectangle::area()
{
	return width * height;
}

string Rectangle::line()
{
	string line = "(" + to_string(width) + ", " + to_string(height) + ")";
	return line;
}

List::List() : head(nullptr), size(0)
{
}

void List::push_back(const Rectangle& rect)
{
	if (head == nullptr) {
		head = new Node{ rect, nullptr };
	}
	else {
		Node* current = head;
		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = new Node{ rect, nullptr };
	}
	size++;
}

bool List::find_width(const double& value)
{
	Node* current = head;
	while (current != nullptr) {
		if (current->data.get_width() == value) {
			return true;
		}
	}
	return false;
}

bool List::find_height(const double& value)
{
	Node* current = head;
	while (current != nullptr) {
		if (current->data.get_height() == value) {
			return true;
		}
	}
	return false;
}

Rectangle List::min_width()
{
	Node* current = head;
	Rectangle min = current->data;
	while (current != nullptr) {
		if (current->data.get_width() < min.get_width()) {
			min = current->data;
		}
		current = current->next;
	}
	return min;
}

Rectangle List::min_height()
{
	Node* current = head;
	Rectangle min = current->data;
	while (current != nullptr) {
		if (current->data.get_height() < min.get_height()) {
			min = current->data;
		}
		current = current->next;
	}
	return min;
}

Rectangle List::max_width()
{
	Node* current = head;
	Rectangle max = current->data;
	while (current != nullptr) {
		if (current->data.get_width() > max.get_width()) {
			max = current->data;
		}
		current = current->next;
	}
	return max;
}

Rectangle List::max_height()
{
	Node* current = head;
	Rectangle max = current->data;
	while (current != nullptr) {
		if (current->data.get_height() > max.get_height()) {
			max = current->data;
		}
		current = current->next;
	}
	return max;
}

void List::area_sort()
{
	Rectangle* rect = new Rectangle[size];
	Node* current = head;
	int i = 0;
	while (current != nullptr) {
		rect[i] = current->data;
		current = current->next;
		i++;
	}

	for (int j = 0; j < size - 1; j++) {
		for (int k = 0; k < size - j - 1; k++) {
			if (rect[k].area() > rect[k + 1].area()) {
				Rectangle temp = rect[k];
				rect[k] = rect[k + 1];
				rect[k + 1] = temp;
			}
		}
	}

	current = head;
	i = 0;
	while (current != nullptr) {
		current->data = rect[i];
		current = current->next;
		i++;
	}
}

void List::show()
{
	Node* current = head;
	int i = 1;
	while (current != nullptr) {
		cout << "Rectangle " << i << endl;
		cout << current->data.line() << endl;
		current = current->next;
		i++;
	}
}

Rectangle List::end()
{
	Node* current = head;
	while (current->next != nullptr) {
		current = current->next;
	}
	return current->data;
}

void List::check_rects(const double& value)
{
	Node* current = head;
	while (current != nullptr) {
		if (current->data.area() == value) {
			cout << "There is such a rectangle!" << endl;
			return;
		}
		current = current->next;
	}
	cout << "There is not such a rectangle!" << endl;
}
