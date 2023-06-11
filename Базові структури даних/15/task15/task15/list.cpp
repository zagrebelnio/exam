#include "list.h"

List::List() : head(nullptr), tail(nullptr), size(0)
{
}

void List::push_back(const char& value)
{
	if (head == nullptr) {
		head = new Node{ value, nullptr, nullptr };
		tail = head;
	}
	else {
		tail->next = new Node{ value, tail, nullptr };
		tail = tail->next;
	}
	size++;
}

void List::pop_back()
{
	if (size != 0) {
		Node* current = tail;
		tail = tail->previous;
		tail->next = nullptr;
		delete current;
	}
}

void List::show()
{
	if (head == nullptr) {
		cout << "List is empty!" << endl;
	}
	else {
		Node* current = head;
		while (current != nullptr) {
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl;
	}
}

void List::sort()
{
	char* line = new char[size];
	Node* current = head;
	int i = 0;
	while (current != nullptr) {
		line[i] = current->data;
		current = current->next;
		i++;
	}

	for (int j = 0; j < size - 1; j++) {
		for (int k = 0; k < size - j - 1; k++) {
			if (line[k] > line[k + 1]) {
				char temp = line[k];
				line[k] = line[k + 1];
				line[k + 1] = temp;
			}
		}
	}

	current = head;
	i = 0;
	while (current != nullptr) {
		current->data = line[i];
		current = current->next;
		i++;
	}
}

string List::odd_elements()
{
	string line = "";
	Node* current = head;
	int i = 1;
	while (current != nullptr) {
		if (i % 2 == 1) {
			line += current->data;
		}
		current = current->next;
		i++;
	}
	return line;
}
