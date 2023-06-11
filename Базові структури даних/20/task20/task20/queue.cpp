#include "queue.h"

Queue::Queue() : head(nullptr), tail(nullptr), size(0)
{
}

Queue::~Queue()
{
	Node* current = head;
	while (current != nullptr) {
		Node* temp = current;
		current = current->next;
		delete temp;
	}
}

void Queue::push_back(const string& s)
{
	if (tail == nullptr) {
		head = new Node{ s, nullptr, nullptr };
		tail = head;
	}
	else {
		tail->next = new Node{ s, tail, nullptr };
		tail = tail->next;
	}
	size++;
}

void Queue::push_front(const string& s)
{
	if (head == nullptr) {
		head = new Node{ s, nullptr, nullptr };
		tail = head;
	}
	else {
		head->previous = new Node{ s, nullptr, head };
		head = head->previous;
	}
	size++;
}

void Queue::pop_back()
{
	if (!is_empty()) {
		Node* temp = tail;
		tail = tail->previous;
		if (tail != nullptr) {
			tail->next = nullptr;
		}
		delete temp;
		size--;
	}
}

void Queue::pop_front()
{
	if (!is_empty()) {
		Node* temp = head;
		head = head->next;
		delete temp;
		size--;
	}
}

void Queue::show()
{
	if (!is_empty()) {
		Node* current = head;
		while (current != nullptr) {
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl;
	}
	else {
		cout << "Queue is empty!" << endl;
	}
}

bool Queue::is_empty()
{
	return size == 0;
}
