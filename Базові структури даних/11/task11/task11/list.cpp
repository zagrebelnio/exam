#include "list.h"

List::List()
{
	head = nullptr;
	size = 0;
}

int List::get_size()
{
	return size;
}

void List::push_back(int num)
{
	if (num <= 4) { return; }
	if (head == nullptr) {
		head = new Node;
		head->data = num;
		head->pNext = nullptr;
	}
	else {
		Node* current = head;
		while (current->pNext != nullptr) {
			current = current->pNext;
		}
		current->pNext = new Node;
		current = current->pNext;
		current->data = num;
		current->pNext = nullptr;
	}
	size++;
}

bool List::find(int num)
{
	Node* current = head;
	while (current != nullptr) {
		if (current->data == num) {
			return true;
		}
		current = current->pNext;
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
		current = current->pNext;
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
		current = current->pNext;
	}
	return max;
}

void List::sort()
{
	int* marks = new int[size];
	Node* current = head;
	int i = 0;
	while (current != nullptr) {
		marks[i] = current->data;
		current = current->pNext;
		i++;
	}

	for (int j = 0; j < size - 1; j++) {
		for (int k = 0; k < size - j - 1; k++) {
			if (marks[k] > marks[k + 1]) {
				int temp = marks[k];
				marks[k] = marks[k + 1];
				marks[k + 1] = temp;
			}
		}
	}

	current = head;
	i = 0;
	while (current != nullptr) {
		current->data = marks[i];
		current = current->pNext;
		i++;
	}
}

void List::show()
{
	Node* current = head;
	while (current != nullptr) {
		cout << current->data << " ";
		current = current->pNext;
	}
	cout << endl;
}
