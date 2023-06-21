#include "stack.h"

template<typename T>
inline Stack<T>::Stack() : head(nullptr), tail(nullptr), size(0)
{
}

template<typename T>
Stack<T>::Stack(const Stack& other)
{
	Node* current = other;
	while (current != nullptr) {
		push(current->data);
	}
}

template<typename T>
Stack<T>::~Stack()
{
	clear();
}

template<typename T>
void Stack<T>::push(const T& value)
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

template<typename T>
void Stack<T>::pop()
{
	if (!is_empty()) {
		if (size == 1) {
			head = tail = nullptr;
		}
		else {
			Node* temp = tail;
			tail = tail->previous;
			delete temp;
			tail->next = nullptr;
		}
		size--;
	}
}

template<typename T>
T& Stack<T>::end()
{
	if (!is_empty()) {
		return tail->data;
	}
}

template<typename T>
bool Stack<T>::is_empty()
{
	return size == 0;
}

template<typename T>
void Stack<T>::show()
{
	if (!is_empty()) {
		Node* current = head;
		while (current != nullptr) {
			cout << current->data << " ";
			current = current->next;
		}
	}
	cout << endl;
}

template<typename T>
void Stack<T>::clear()
{
	while (!is_empty()) {
		pop();
	}
}

template class Stack<int>;