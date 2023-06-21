#include "stack.h"

template <typename T, size_t MAX_SIZE>
Stack<T, MAX_SIZE>::Stack()
{
	stack[MAX_SIZE] = {};
	top = -1;
}

template <typename T, size_t MAX_SIZE>
bool Stack<T, MAX_SIZE>::push(const T& value)
{
	if (!is_full()) {
		top++;
		stack[top] = value;
		return true;
	}
	return false;
}

template <typename T, size_t MAX_SIZE>
void Stack<T, MAX_SIZE>::pop()
{
	if (!is_empty()) {
		top--;
	}
}

template <typename T, size_t MAX_SIZE>
T& Stack<T, MAX_SIZE>::end()
{
	return stack[top];
}

template <typename T, size_t MAX_SIZE>
bool Stack<T, MAX_SIZE>::is_full() const
{
	return size() == MAX_SIZE;
}

template <typename T, size_t MAX_SIZE>
bool Stack<T, MAX_SIZE>::is_empty() const
{
	return top == -1;
}

template <typename T, size_t MAX_SIZE>
size_t Stack<T, MAX_SIZE>::max_size() const
{
	return MAX_SIZE;
}

template <typename T, size_t MAX_SIZE>
size_t Stack<T, MAX_SIZE>::size() const
{
	return top + 1;
}

template <typename T, size_t MAX_SIZE>
void Stack<T, MAX_SIZE>::show()
{
	for (int i = 0; i < size(); i++) {
		cout << stack[i] << " ";
	}
	cout << endl;
}

template<typename T>
void processStack()
{
	Stack<int, 10> stack;

	cout << "<---Stack handler--->" << endl;
	cout << "1. Push value to stack" << endl;
	cout << "2. Pop value from stack" << endl;
	cout << "3. Get top element from stack" << endl;
	cout << "4. Check if stack is full" << endl;
	cout << "5. Check if stack is empty" << endl;
	cout << "6. Get max size of stack" << endl;
	cout << "7. Get size of stack" << endl;
	cout << "8. Show stack" << endl;
	cout << "0. Exit" << endl;

	bool work = true;

	while (work) {
		int choice;

		cout << "Your choice: ";
		cin >> choice;
		cin.ignore();

		string exit;

		switch (choice) {
		case 1:
			while (true) {
				int value;
				cout << "Enter value to push: ";
				cin >> value;
				cin.ignore();
				if (stack.push(value)) {
					cout << "Value was pushed." << endl;
				}
				else {
					cout << "The stack is full." << endl;
					break;
				}
				cout << "Push one more? (y/n) ";
				getline(cin, exit);
				if (exit == "n") {
					break;
				}
			}
			break;
		case 2:
			stack.pop();
			break;
		case 3:
			cout << "Top element of the stack is: " << stack.end() << endl;
			break;
		case 4:
			if (stack.is_full()) {
				cout << "The stack is full!" << endl;
			}
			else {
				cout << "The stack is not full!" << endl;
			}
			break;
		case 5:
			if (stack.is_empty()) {
				cout << "The stack is empty!" << endl;
			}
			else {
				cout << "The stack is not empty!" << endl;
			}
			break;
		case 6:
			cout << "Max size of the stack is: " << stack.max_size() << endl;
			break;
		case 7:
			cout << "Size of the stack is: " << stack.size() << endl;
			break;
		case 8:
			cout << "Stack: ";
			stack.show();
			break;
		default:
			work = false;
			break;
		}
	}
}

template class Stack<int, 10>;
template class Stack<double, 10>;
template class Stack<char, 10>;
template class Stack<string, 10>;
template void processStack<int>();
template void processStack<double>();
template void processStack<char>();
template void processStack<string>();