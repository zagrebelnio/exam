#include "tree.h"

template<typename T>
void Tree<T>::remove_subtree(Node* node)
{
	if (node->left != nullptr) {
		remove_subtree(node->left);
	}
	if (node->right != nullptr) {
		remove_subtree(node->right);
	}
	delete node;
}

template<typename T>
typename Tree<T>::Node* Tree<T>::remove(Node* node, const T& value)
{
	if (node == nullptr) {
		return nullptr;
	}
	if (value < node->data) {
		node->left = remove(node->left, value);
	}
	else if (value > node->data) {
		node->right = remove(node->right, value);
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
			Node* temp = find_min(node->right);
			node->data = temp->data;
			node->right = remove(node->right, temp->data);
		}
	}
	return node;
}

template<typename T>
typename Tree<T>::Node* Tree<T>::find_min(Node* node)
{
	if (node->left == nullptr) {
		return node;
	}
	find_min(node->left);
}

template<typename T>
void Tree<T>::show(Node* node)
{
	if (node == nullptr) {
		return;
	}
	show(node->left);
	cout << node->data << " ";
	show(node->right);
}

template<typename T>
inline Tree<T>::Tree() : root(nullptr)
{
}

template<typename T>
Tree<T>::~Tree()
{
	clear();
}

template<typename T>
void Tree<T>::add(const T& value)
{
	Node* node = new Node{ value, nullptr, nullptr };
	if (root == nullptr) {
		root = node;
	}
	else {
		Node* current = root;
		while (current != nullptr) {
			if (value < current->data) {
				if (current->left == nullptr) {
					current->left = node;
					return;
				}
				current = current->left;
			}
			else {
				if (current->right == nullptr) {
					current->right = node;
					return;
				}
				current = current->right;
			}
		}
	}
}

template<typename T>
void Tree<T>::remove(const T& value)
{
	root = remove(root, value);
}

template<typename T>
void Tree<T>::clear()
{
	remove_subtree(root);
	root = nullptr;
}

template<typename T>
void Tree<T>::show()
{
	show(root);
}

template class Tree<int>;

int generate_number(int min, int max)
{
	return rand() % (max - min + 1) + min;
}
