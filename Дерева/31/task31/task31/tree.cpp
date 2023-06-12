#include "tree.h"

Tree::Tree() : root(nullptr)
{
}

void Tree::add(const char& value)
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

void Tree::preOrder(Node* node, string& result)
{
	if (node == nullptr) {
		return;
	}
	result += node->data;
	preOrder(node->left, result);
	preOrder(node->right, result);
}

void Tree::preOrder(string& result)
{
	preOrder(root, result);
}

void Tree::inOrder(Node* node, string& result)
{
	if (node == nullptr) {
		return;
	}
	inOrder(node->left, result);
	result += node->data;
	inOrder(node->right, result);
}

void Tree::inOrder(string& result)
{
	inOrder(root, result);
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