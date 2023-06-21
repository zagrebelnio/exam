#include "hashtable.h"

bool HashTable::is_empty() const
{
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += table[i].size();
	}
	return sum == 0;
}

int HashTable::hash_function(int key)
{
	return key % size;
}

void HashTable::insert(int key, string value)
{
	int index = hash_function(key);
	auto& cell = table[index];
	auto bItr = begin(cell);
	for (; bItr != end(cell); bItr++) {
		if (bItr->first == key) {
			bItr->second = value;
			cout << "Key exists. Value was replaced." << endl;
			return;
		}
	}
	cell.emplace_back(key, value);
}

void HashTable::remove(int key)
{
	int index = hash_function(key);
	auto& cell = table[index];
	auto bItr = begin(cell);
	for (; bItr != end(cell); bItr++) {
		if (bItr->first == key) {
			cell.erase(bItr);
			cout << "Key exists. Value was removed." << endl;
			return;
		}
	}
	cout << "Key not found." << endl;
}

bool HashTable::search(int key, string& value)
{
	int index = hash_function(key);
	auto& cell = table[index];
	auto bItr = cell.begin();
	for (; bItr != cell.end(); bItr++) {
		if (bItr->first == key) {
			value = bItr->second;
			return true;
		}
	}
	return false;
}

void HashTable::clear()
{
	for (int i = 0; i < size; i++) {
		table[i].clear();
	}
}

void HashTable::print()
{
	for (int i = 0; i < size; i++) {
		if (table[i].size() == 0) continue;
		auto bItr = table[i].begin();
		for (; bItr != table[i].end(); bItr++) {
			cout << "Key: " << bItr->first << " Value: " << bItr->second << endl;
		}
	}
}
