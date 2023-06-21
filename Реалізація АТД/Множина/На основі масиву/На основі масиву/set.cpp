#include "set.h"

template<typename T>
int Set<T>::size()
{
	return top + 1;
}

template<typename T>
void Set<T>::add(const T& value)
{
	if (!is_full()) {
		top++;
		data[top] = value;
	}
}

template<typename T>
void Set<T>::pop(const T& value)
{
	for (int i = 0; i < size(); i++) {
		if (data[i] == value) {
			data[i] = data[top];
			top--;
		}
	}
}

template<typename T>
bool Set<T>::is_empty()
{
	return size() == 0;
}

template<typename T>
bool Set<T>::is_full()
{
	return size() == MAX_SIZE;
}

template<typename T>
void Set<T>::clear()
{
	top = -1;
}

template<typename T>
void Set<T>::print()
{
	for (int i = 0; i < size(); i++) {
		cout << data[i] << " ";
	}
	cout << endl;
}

template class Set<int>;