#include "stack.h"

void Stack::push(const string& value)
{
	if (!is_full()) {
		top++;
		stack[top] = value;
	}
}

string Stack::pop()
{
	if (!is_empty()) {
		return stack[top--];
	}
}

int Stack::size()
{
	return top + 1;
}

bool Stack::is_full()
{
	return size() == MAX_SIZE;
}

bool Stack::is_empty()
{
	return top == -1;
}

void Stack::modify()
{
	string temp[MAX_SIZE];
	int j = 0;
	for (int i = 0; i < size() - 1; i++) {
		if (stack[i] == stack[i + 1]) {
			i++;
		}
		else {
			temp[j] = stack[i];
			j++;
		}
	}
	top = j;
	for (int i = 0; i < size(); i++) {
		stack[i] = temp[i];
	}
}

void Stack::show()
{
	for (int i = 0; i < size(); i++) {
		cout << stack[i] << " ";
	}
	cout << endl;
}