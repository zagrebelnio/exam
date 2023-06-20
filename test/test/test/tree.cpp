#include "tree.h"

template<typename T>
Stack<T>::Stack() : data(nullptr), size(0)
{
}

template<typename T>
void Stack<T>::push_back(const T& value)
{
	T* temp;
	temp = data;
	data = new T[size + 1];
	
	for (int i = 0; i < size ; i++) {
		data[i] = temp[i];
	}
	data[size] = value;

	size++;

	if (size > 1) {
		delete[] temp;
	}
}

template<typename T>
void Stack<T>::pop_back()
{
	if (!is_empty()) {
		T* temp = data;

		data = new T[size - 1];

		size--;

		for (int i = 0; i < size; i++) {
			data[i] = temp[i];
		}

		delete[] temp;
	}
}

template<typename T>
bool Stack<T>::is_empty()
{
	return size == 0;
}

template<typename T>
void Stack<T>::print()
{
	cout << "Stack: ";
	if (size == 0) {
		cout << "is empty" << endl;
		return;
	}

	for (int i = 0; i < size; i++) {
		cout << data[i] << " ";
	}
	cout << endl;
}

template class Stack<int>;
template class Stack<string>;
template class Stack<char>;
template class Stack<double>;