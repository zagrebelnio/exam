#include "queue.h"

Queue::Queue() : head(nullptr), tail(nullptr), size(0)
{
}

void Queue::push(const int& value)
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

void Queue::pop()
{
	if (head != nullptr) {
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}

void Queue::show()
{
	if (head == nullptr) {
		cout << "Queue is empty!" << endl;
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

int Queue::modify(const int& num)
{
	int counter = 0;
	Node* current = head;
	while (current != nullptr) {
		if (current->data == num) {
			Node* temp = current;
			while (temp->next != nullptr) {
				temp->data = temp->next->data;
				temp = temp->next;
			}
			tail = temp->previous;
			tail->next = nullptr;
			size--;
			counter++;
		}
		current = current->next;
	}
	return counter;
}
