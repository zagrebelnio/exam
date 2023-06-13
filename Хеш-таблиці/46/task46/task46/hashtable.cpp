#include "hashtable.h"

int HashTable::hash_function(const int& key) const
{
	return key % MAX_SIZE;
}
