#include "tree.h"

Tree::Tree() : root(nullptr)
{
}

void Tree::add(const int& value)
{
	Node* newNode = new Node{ value, nullptr, nullptr };
	if (root == nullptr) {
		root = newNode;
		return;
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

void Tree::show(Node* node)
{
	if (node == nullptr) {
		return;
	}
	show(node->left);
	cout << node->data << " ";
	show(node->right);
}

void Tree::inOrder(Node* node, int& sum)
{
	if (node == nullptr) {
		return;
	}
	sum += node->data;
	inOrder(node->left, sum);
	inOrder(node->right, sum);
}

int Tree::left_sum()
{
	int sum = 0;
	inOrder(root->left, sum);
	return sum;
}

int Tree::right_sum()
{
	int sum = 0;
	inOrder(root->right, sum);
	return sum;
}

void Tree::show()
{
	show(root);
}
