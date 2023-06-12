#include "function.h"

Function::Function(double k, double b) : k(k), b(b)
{
}

bool Function::operator==(const Function& other)
{
	if (b == other.b && k == other.k) {
		return true;
	}
	return false;
}

double Function::getK()
{
	return k;
}

double Function::getB()
{
	return b;
}

void Function::moveOY(double value)
{
	b += value;
}

void Function::show_info()
{
	cout << "y = " << k << "*x ";
	if (b > 0) {
		cout << "+ " << b;
	}
	else if (b < 0) {
		cout << "- " << -b;
	}
	cout << endl;
}

void Set::add(const Function& func)
{
	if (!is_full()) {
		elements[size] = func;
		size++;
	}
}

bool Set::contains(const Function& func)
{
	for (int i = 0; i < size; i++) {
		if (elements[i] == func) {
			return true;
		}
	}
	return false;
}

void Set::modify(const Function& func, const double& value)
{
	for (int i = 0; i < size; i++) {
		if (elements[i] == func) {
			elements[i].moveOY(value);
			return;
		}
	}
}

bool Set::is_full()
{
	return size == MAX_SIZE;
}

void Set::show()
{
	for (int i = 0; i < size; i++) {
		cout << "Function " << i + 1 << ": ";
		elements[i].show_info();
	}
}
