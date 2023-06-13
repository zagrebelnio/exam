#pragma once
#include <iostream>
#include <string>

using namespace std;

class HashTable {
	static const int MAX_SIZE = 10;
	struct Node {
		int key;
		string value;
		bool deleted;
		Node() : key(0), value(""), deleted(false) { }
	};
	Node table[MAX_SIZE];
	int hash_function(const int& key) const;
public:
	void insert(int key, const string& value) {
		int index = hash_function(key);
		while (table[index].key != 0 && !table[index].deleted) {
			index = (index + 1) % MAX_SIZE;
		}
		table[index].key = key;
		table[index].value = value;
		table[index].deleted = false;
	}

	void search(int key) {
		int index = hash_function(key);
		while (table[index].key != 0) {
			if (table[index].key == key && !table[index].deleted) {
				cout << "Value with key " << key << ": " << table[index].value << endl;
				return;
			}
			index = (index + 1) % MAX_SIZE;
		}
		cout << "Value with key " << key << " not found." << endl;
	}
	void remove(int key) {
		int index = hash_function(key);

		while (table[index].key != 0) {
			if (table[index].key == key && !table[index].deleted) {
				table[index].deleted = true;
				std::cout << "Value with key " << key << " removed." << std::endl;
			}
			index = (index + 1) % MAX_SIZE;
		}
	}
};