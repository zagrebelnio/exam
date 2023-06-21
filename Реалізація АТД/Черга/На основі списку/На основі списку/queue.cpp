#include "queue.h"

template<typename T>
inline Queue<T>::Queue() : head(nullptr), tail(nullptr), size(0)
{
}

template<typename T>
Queue<T>::~Queue()
{
	clear();
}

template<typename T>
void Queue<T>::push(const T& value)
{
	Node* node = new Node{ value, nullptr, nullptr };
	if (tail == nullptr) {
		head = tail = node;
	}
	else {
		tail->next = node;
		tail = tail->next;
	}
	size++;
}

template<typename T>
void Queue<T>::pop()
{
	if (!is_empty()) {
		if (size == 1) {
			delete head;
			head = tail = nullptr;
		}
		else {
			Node* temp = head;
			head = head->next;
			delete temp;
		}
		size--;
	}
}

template<typename T>
bool Queue<T>::is_empty()
{
	return size == 0;
}

template<typename T>
void Queue<T>::clear()
{
	while (!is_empty()) {
		pop();
	}
}

template<typename T>
void Queue<T>::show()
{
	Node* current = head;
	while (current != nullptr) {
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}

template<typename T>
void process_queue()
{
	Queue<T> queue;

	cout << "<---Queue manager--->" << endl;
	cout << "1. Push element to queue" << endl;
	cout << "2. Pop element from queue" << endl;
	cout << "3. Check if the queue is empty" << endl;
	cout << "4. Clear queue" << endl;
	cout << "5. Print queue" << endl;
	cout << "0. Exit" << endl;

	bool go_on = true;
	string enter;

	while(go_on) {
		int choice;
		cout << "Your choice: ";
		cin >> choice;
		cin.ignore();
		switch (choice) {
		case 1:
			do {
				T value;
				cout << "Enter value: ";
				cin >> value;
				cin.ignore();
				queue.push(value);
				cout << "One more? (y/n) ";
				getline(cin, enter);
			} while (enter != "n");
			break;
		case 2:
			queue.pop();
			cout << "Element removed." << endl;
			break;
		case 3:
			if (queue.is_empty()) {
				cout << "Queue is empty!" << endl;
			}
			else {
				cout << "Queue is not empty!" << endl;
			}
			break;
		case 4:
			queue.clear();
			cout << "Queue was cleared." << endl;
			break;
		case 5:
			cout << "Queue: ";
			queue.show();
			break;
		default:
			go_on = false;
			break;
		}
	}
}

template class Queue<int>;
template class Queue<double>;
template class Queue<char>;
template class Queue<string>;
template void process_queue<int>();
template void process_queue<double>();
template void process_queue<char>();
template void process_queue<string>();
