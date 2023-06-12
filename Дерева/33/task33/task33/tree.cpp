/*#include "tree.h"

Tree::Tree() : root(nullptr)
{
}

void Tree::construct(string expression)
{
	Node* current = nullptr;
	for (int i = 0; i < expression.length(); i++) {
		if (isOperator(expression[i])) {
			if (root == nullptr) {
				root = new Node{ expression[i], nullptr, nullptr };
				current = root;
			}
			else {
				Node* temp = new Node{ expression[i], nullptr, nullptr };
				if (current->left == nullptr) {
					current->left = temp;
					current = current->left;
				}
				else if (current->right == nullptr) {
					current->right = temp;
					current = current->right;
				}
			}
		}
		else {
			if (current == nullptr) {
				current = new Node{ expression[i], nullptr, nullptr };
				root = current;
			}
			else {
				Node* temp = new Node{ expression[i], nullptr, nullptr };
				if (current->left == nullptr) {
					current->left = temp;
				}
				else if (current->right == nullptr) {
					current->right == temp;
				}
			}
		}
	}
}

bool Tree::isOperator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/') {
		return true;
	}
	return false;
}

void Tree::prefix(Node* node)
{
	if (node != nullptr) {
		cout << node->data << " ";
		prefix(node->left);
		prefix(node->right);
	}
}

void Tree::prefix()
{
	prefix(root);
}

int Tree::evaluate(Node* node)
{
	if (node == nullptr) {
		return 0;
	}
	if (node->left == nullptr && node->right == nullptr) {
		return node->data - '0';
	}
	int left = evaluate(node->left);
	int right = evaluate(node->right);
	if (node->data == '+') {
		return left + right;
	}
	else if (node->data == '-') {
		return left - right;
	}
	else if (node->data == '*') {
		return left * right;
	}
	else if (node->data == '/') {
		return left / right;
	}
	else {
		return 0;
	}
}

int Tree::evaluate()
{
	return evaluate(root);
}
*/