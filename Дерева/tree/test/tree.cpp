#include "tree.h"

Node* Tree::find_minimum(Node* node)
{
	while(true) {
		if (node->left == nullptr) {
			return node;
		}
		node = node->left;
	}
}

Tree::Tree()
{
}

void Tree::add(const int& value)
{
	Node* newNode = new Node{ value, nullptr, nullptr };
	if (root == nullptr) {
		root = newNode;
	}
	else {
		Node* current = root;
		while (true) {
			if (value < current->data) {
				if (current->left == nullptr) {
					current->left = newNode;
					return;
				}
				current = current->left;
			}
			else {
				if (current->right == nullptr) {
					current->right = newNode;
					return;
				}
				current = current->right;
			}
		}
	}
}

Node* Tree::pop(Node* node, const int& value)
{
	if (node == nullptr) {
		return nullptr;
	}
	if (value < node->data) {
		node->left = pop(node->left, value);
	}
	else if (value > node->data) {
		node->right = pop(node->right, value);
	}
	else {
		if (node->left == nullptr && node->right == nullptr) {
			delete node;
			node = nullptr;
		}
		else if (node->left == nullptr) {
			Node* temp = node->right;
			delete node;
			node = temp;
		}
		else if (node->right == nullptr) {
			Node* temp = node->left;
			delete node;
			node = temp;
		}
		else {
			Node* temp = find_minimum(node->right);
			node->data = temp->data;
			node->right = pop(node->right, temp->data);
		}
	}
	return node;
}

void Tree::pop(const int& value)
{
	root = pop(root, value);
}

void Tree::show(Node* node)
{
	if (node == nullptr) {
		return;
	}
	show(node->left);
	cout << node->data << " ";
	show(node->right);
}

void Tree::show()
{
	show(root);
}

int generate_number(const int& min, const int& max)
{
	return rand() % (max - min + 1) + min;
}
