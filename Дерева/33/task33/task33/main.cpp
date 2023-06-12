//#include "tree.h"

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Node {
public:
    char data;
    Node* left;
    Node* right;
    Node(char data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class Tree {
public:
    Node* root;
    Tree() {
        root = NULL;
    }
    void constructTree(string expression) {
        stack<Node*> st;
        Node* t, * t1, * t2;

        for (int i = 0; i < expression.length(); i++) {
            if (!isOperator(expression[i])) {
                t = new Node(expression[i]);
                st.push(t);
            }
            else {
                t = new Node(expression[i]);
                t1 = st.top();
                st.pop();

                if (!st.empty()) {
                    t2 = st.top();
                    st.pop();

                    t->right = t1;
                    t->left = t2;
                }
                else {
                    t->right = t1; // ќператор маЇ т≥льки один операнд, тому в≥н стаЇ правим дит€чим вузлом
                }

                st.push(t);
            }
        }

        root = st.top();
        st.pop();
    }
    bool isOperator(char c) {
        if (c == '+' || c == '-' || c == '*' || c == '/') {
            return true;
        }
        return false;
    }
    void prefix(Node* node) {
        if (node != NULL) {
            cout << node->data << " ";
            prefix(node->left);
            prefix(node->right);
        }
    }
    int evaluate(Node* node) {
        if (node == NULL) {
            return 0;
        }
        if (node->left == NULL && node->right == NULL) {
            return node->data - '0';
        }
        int left = evaluate(node->left);
        int right = evaluate(node->right);
        switch (node->data) {
        case '+':
            return left + right;
        case '-':
            return left - right;
        case '*':
            return left * right;
        case '/':
            return left / right;
        default:
            return 0;
        }
    }
};

int main() {
    string expression;
    cout << "Enter a mathematical expression: ";
    cin >> expression;
    Tree tree;
    tree.constructTree(expression);
    cout << "Prefix traversal of the tree: ";
    tree.prefix(tree.root);
    cout << endl;
    cout << "Evaluation of the expression: " << tree.evaluate(tree.root) << endl;
    return 0;
}
