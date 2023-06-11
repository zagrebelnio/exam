#include "triangle.h"

Triangle::Triangle(double a, double b, double c) : a(a), b(b), c(c)
{
}

double Triangle::getA()
{
	return a;
}

double Triangle::getB()
{
	return b;
}

double Triangle::getC()
{
	return c;
}

double Triangle::perimeter()
{
	return a + b + c;
}

string Triangle::line()
{
	string line = "(" + to_string(a) + ", " + to_string(b) + ", " + to_string(c) + ")";
	return line;
}

double Triangle::longest_side()
{
	if (a > b && a > c) { return a; }
	else if (b > a && b > c) { return b; }
	else { return c; }
}

List::List() : head(nullptr), size(0)
{
}

void List::push_back(const Triangle& triangle)
{
	if (head == nullptr) {
		head = new Node{ triangle, nullptr };
	}
	else {
		Node* current = head;
		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = new Node{ triangle, nullptr };
	}
	size++;
}

bool List::find_a(const double& a)
{
	Node* current = head;
	while (current != nullptr) {
		if (current->data.getA() == a) {
			return true;
		}
		current = current->next;
	}
	return false;
}

bool List::find_b(const double& b)
{
	Node* current = head;
	while (current != nullptr) {
		if (current->data.getB() == b) {
			return true;
		}
		current = current->next;
	}
	return false;
}

bool List::find_c(const double& c)
{
	Node* current = head;
	while (current != nullptr) {
		if (current->data.getC() == c) {
			return true;
		}
		current = current->next;
	}
	return false;
}

void List::perimeter_sort()
{
	Triangle* triangles = new Triangle[size];
	
	Node* current = head;
	int i = 0;
	while (current != nullptr) {
		triangles[i] = current->data;
		current = current->next;
		i++;
	}

	for (int j = 0; j < size - 1; j++) {
		for (int k = 0; k < size - j - 1; k++) {
			if (triangles[k].perimeter() > triangles[k + 1].perimeter()) {
				Triangle temp = triangles[k];
				triangles[k] = triangles[k + 1];
				triangles[k + 1] = temp;
			}
		}
	}

	current = head;
	i = 0;
	while (current != nullptr) {
		current->data = triangles[i];
		current = current->next;
		i++;
	}
}

void List::show()
{
	Node* current = head;
	int i = 1;
	while (current != nullptr) {
		cout << "Triangle " << i << endl;
		cout << current->data.line() << endl;
		current = current->next;
		i++;
	}
}

Triangle List::end()
{
	Node* current = head;
	while (current->next != nullptr) {
		current = current->next;
	}
	return current->data;
}

void List::check_perimeters(const double& side)
{
	Node* current = head;
	while (current != nullptr) {
		if (current->data.perimeter() == side) {
			cout << "There is an triangle!" << endl;
			cout << current->data.line() << endl;
			return;
		}
		current = current->next;
	}
	cout << "There isn't such a triangle!" << endl;
}
