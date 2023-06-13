#include "tree.h"

int main() {

	string s;
	Tree tree;
	cout << "Input expression: ";
	getline(cin, s);
	tree.makeTree(s, 0, s.length() - 1);
	tree.print();
	cout << endl;
	cout << tree.calcTree(tree.getNode());

	return 0;
}