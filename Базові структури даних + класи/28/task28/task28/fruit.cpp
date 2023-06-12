#include "fruit.h"

Fruit::Fruit(string name, string color, double callories) : name(name), color(color), callories(callories)
{
}

double Fruit::get_callories()
{
	return callories;
}

void Fruit::show_info()
{
	cout << "Name: " << name << endl;
	cout << "Color: " << color << endl;
	cout << "Callories: " << callories << endl;
}

List::List() : head(nullptr), size(0)
{
}

void List::push_back(const Fruit& fruit)
{
	if (head == nullptr) {
		head = new Node{ fruit, nullptr };
	}
	else {
		Node* current = head;
		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = new Node{ fruit, nullptr };
	}
	size++;
}

Fruit List::min()
{
	Node* current = head;
	Fruit min = current->data;
	while (current != nullptr) {
		if (current->data.get_callories() < min.get_callories()) {
			min = current->data;
		}
		current = current->next;
	}
	return min;
}

Fruit List::max()
{
	Node* current = head;
	Fruit max = current->data;
	while (current != nullptr) {
		if (current->data.get_callories() > max.get_callories()) {
			max = current->data;
		}
		current = current->next;
	}
	return max;
}

void List::show()
{
	Node* current = head;
	int i = 1;
	while (current != nullptr) {
		cout << "Fruit " << i << endl;
		current->data.show_info();
		current = current->next;
		i++;
	}
}
