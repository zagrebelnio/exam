#include "queue.h"

List::List() : head(nullptr), tail(nullptr), size(0) {}

List::~List()
{
	clear();
}

void List::push_back(const string& value)
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

void List::pop_front()
{
	if (size == 0) {
		return;
	}
	if (size == 1) {
		delete head;
		head = nullptr;
		tail = nullptr;
	}
	else {
		Node* temp = head;
		head = head->next;
		head->previous = nullptr;
		delete temp;
	}
	size--;
}

void List::clear()
{
	while (head != nullptr) {
		Node* temp = head;
		head = head->next;
		delete temp;
	}
	tail = nullptr;
	size = 0;
}

int List::get_size() const
{
	return size;
}

void List::show() const
{
	if (size == 0) {
		cout << "List is empty!" << endl;
		return;
	}
	Node* current = head;

	while (current != nullptr) {
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}

void Queue::push(const string& value)
{
	list.push_back(value);
}

void Queue::pop()
{
	list.pop_front();
}

void Queue::show()
{
	list.show();
}