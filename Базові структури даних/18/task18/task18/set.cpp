#include "set.h"

void Set::add(const char& c)
{
	if (!is_full()) {
		elements[size] = c;
		size++;
	}
}

void Set::remove(const char& c)
{
	if (!is_empty()) {
		for (int i = 0; i < size; i++) {
			if (elements[i] == c) {
				elements[i] = elements[size - 1];
				size--;
				break;
			}
		}
	}
}

bool Set::contains(const char& c)
{
	for (int i = 0; i < size; i++) {
		if (elements[i] == c) {
			return true;
		}
	}
	return false;
}

void Set::show()
{
	if (!is_empty()) {
		for (int i = 0; i < size; i++) {
			cout << elements[i] << " ";
		}
		cout << endl;
	}
	else {
		cout << "Set is empty!" << endl;
	}
}

bool Set::is_full()
{
	return size == MAX_SIZE;
}

bool Set::is_empty()
{
	return size == 0;
}

Set Set::dublicates()
{
	Set dublicates_set;
	for (int i = 0; i < size; i++) {
		if (check_dublicates(elements[i], i)) {
			dublicates_set.add(elements[i]);
		}
	}
	return dublicates_set;
}

bool Set::check_dublicates(const char& c, int index)
{
	for (int i = 0; i < size; i++) {
		if (i == index) {
			continue;
		}
		if (elements[i] == c) {
			return true;
		}
	}
	return false;
}
