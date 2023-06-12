#include "house.h"

House::House(string city, string street, int number) : city(city), street(street), number(number)
{
}

bool House::operator==(const House& other)
{
	if (city == other.city && street == other.street && number == other.number) {
		return true;
	}
	return false;
}

string House::get_city()
{
	return city;
}

string House::get_street()
{
	return street;
}

int House::get_number()
{
	return number;
}

void House::show_info()
{
	cout << "City: " << city << endl;
	cout << "Street: " << street << endl;
	cout << "Number: " << number << endl;
}

void Set::add(const House& value)
{
	if (!is_full()) {
		elements[size] = value;
		size++;
	}
}

void Set::remove(const House& value)
{
	if (!is_empty()) {
		for (int i = 0; i < size; i++) {
			if (elements[i] == value) {
				elements[i] = elements[size - 1];
				size--;
				break;
			}
		}
	}
}

bool Set::contains(const House& value)
{
	for (int i = 0; i < size; i++) {
		if (elements[i] == value) {
			return true;
		}
	}
	return false;
}

bool Set::is_full()
{
	return size == MAX_SIZE;
}

bool Set::is_empty()
{
	return size == 0;
}

int Set::get_size()
{
	return size;
}

void Set::show()
{
	if (is_empty()) {
		cout << "The set is empty!" << endl;
	}
	else {
		for (int i = 0; i < size; i++) {
			cout << "House " << i + 1 << endl;
			elements[i].show_info();
		}
	}
}
