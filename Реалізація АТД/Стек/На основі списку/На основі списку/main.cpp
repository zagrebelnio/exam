#include "stack.h"

int main() {

	Stack<int> stack;

	stack.push(12);
	stack.push(11);
	stack.show();

	Stack<int> new_stack(stack);

	new_stack.show();

	return 0;
}