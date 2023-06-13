#include "tree.h"

int Tree::n = 0;

Node* Tree::makeTree(string str, size_t first, size_t last)
{
	if (first == last) {
		Node* p = new Node(str[first]);
		return p;
	}
	int priority, minPrt = 10, k;
	for (int i = first; i <= last; i++) {
		switch (str[i]) {
		case '+':
		case '-':
			priority = 1;
			break;
		case '*':
		case '/':
			priority = 2;
			break;
		default:
			priority = 10;
		}
		if (priority <= minPrt) {
			minPrt = priority;
			k = i;
		}
	}
	Node* p = new Node;
	p->data = str[k];
	if (n == 0) {
		root = p;
		n++;
	}
	p->left = makeTree(str, first, k - 1);
	p->right = makeTree(str, k + 1, last);
	return p;
}

int Tree::calcTree(Node* p)
{
	int num1, num2;
	if (!p->left) {
		return p->data - '0';
	}
	num1 = calcTree(p->left);
	num2 = calcTree(p->right);
	switch (p->data) {
	case '+':
		return num1 + num2;
	case '-':
		return num1 - num2;
	case '*':
		return num1 * num2;
	case '/':
		return num1 / num2;
	}
	return 0;
}

void Tree::print()
{
	print(root);
}

void Tree::print(Node* node)
{
	if (node == nullptr) {
		return;
	}
	print(node->left);
	cout << node->data << " ";
	print(node->right);
}
