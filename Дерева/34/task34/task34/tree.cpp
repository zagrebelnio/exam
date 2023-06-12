#include "tree.h"

Tree::Tree() : root(nullptr)
{
}

void Tree::add(const int& value)
{
	Node* newNode = new Node { value, nullptr, nullptr };
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

bool Tree::postOrder(Node* node, int& value)
{
	if (node == nullptr) {
		return false;
	}

	postOrder(node->left, value);
	postOrder(node->right, value);
	if (node->data == value) {
		return true;
	}
	else {
		return false;
	}
}

bool Tree::postOrder(int& value)
{
	return postOrder(root, value);
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
