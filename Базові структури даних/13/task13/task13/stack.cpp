#include "stack.h"

void Stack::push(const char& value)
{
	if (!is_full()) {
		top++;
		stack[top] = value;
	}
}

char Stack::pop()
{
	if (!is_empty()) {
		return stack[top--]; 
	}
}

bool Stack::is_full()
{	
	return size() == MAX_SIZE;
}

bool Stack::is_empty()
{
	return top == -1;
}

void Stack::show()
{
	for (int i = 0; i < size(); i++) {
		cout << stack[i] << " ";
	}
	cout << endl;
}

int Stack::size()
{
	return top + 1;
}
