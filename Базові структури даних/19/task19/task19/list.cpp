#include "list.h"

List::List()
{
	head = nullptr;
	size = 0;
}

void List::push_back(const int& num)
{
	if (head == nullptr) {
		head = new Node{ num, nullptr };
	}
	else {
		Node* current = head;
		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = new Node{ num, nullptr };
	}
	size++;
}

bool List::find(const int& value)
{
	Node* current = head;
	while (current != nullptr) {
		if (current->data == value) {
			return true;
		}
		current = current->next;
	}
	return false;
}

int List::min()
{
	Node* current = head;
	int min = current->data;
	while (current != nullptr) {
		if (current->data < min) {
			min = current->data;
		}
		current = current->next;
	}
	return min;
}

int List::max()
{
	Node* current = head;
	int max = current->data;
	while (current != nullptr) {
		if (current->data > max) {
			max = current->data;
		}
		current = current->next;
	}
	return max;
}

double List::median()
{
	double median;
	int* values = new int[size];
	Node* current = head;
	int i = 0;
	while (current != nullptr) {
		values[i] = current->data;
		current = current->next;
		i++;
	}

	for (int j = 0; j < size - 1; j++) {
		for (int k = 0; k < size - j - 1; k++) {
			if (values[k] > values[k + 1]) {
				int temp = values[k + 1];
				values[k + 1] = values[k];
				values[k] = temp;
			}
		}
	}

	if (size % 2 == 1) {
		median = double(values[size / 2]);
	}
	else {
		median = (double(values[size / 2]) + double(values[size / 2 - 1])) / 2;
	}
	return median;
}

void List::sort()
{
	int* values = new int[size];
	Node* current = head;
	int i = 0;
	while (current != nullptr) {
		values[i] = current->data;
		current = current->next;
		i++;
	}

	for (int j = 0; j < size - 1; j++) {
		for (int k = 0; k < size - j - 1; k++) {
			if (values[k] > values[k + 1]) {
				int temp = values[k + 1];
				values[k + 1] = values[k];
				values[k] = temp;
			}
		}
	}

	current = head;
	i = 0;
	while (current != nullptr) {
		current->data = values[i];
		current = current->next;
		i++;
	}
}

void List::show()
{
	Node* current = head;
	while (current != nullptr) {
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}
