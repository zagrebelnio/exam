#include "tree.h"

int generate_number(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

Tree::Tree() : root(nullptr)
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

void Tree::inOrder(Node* node, int& counter)
{
	if (node == nullptr) {
		return;
	}

	inOrder(node->left, counter);
	if (node->data < 0) { counter++; }
	cout << node->data << " ";
	inOrder(node->right, counter);
}

void Tree::inOrder(int& counter)
{
	inOrder(root, counter);
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
