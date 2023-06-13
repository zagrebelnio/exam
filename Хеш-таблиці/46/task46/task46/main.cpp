#include "hashtable.h"

int main() {
    HashTable hashTable;
    int key;
    std::string value;

    while (true) {
        std::cout << "Enter key (0 to exit): ";
        std::cin >> key;
        if (key == 0) {
            break;
        }

        std::cout << "Enter value: ";
        std::cin.ignore();
        std::getline(std::cin, value);

        hashTable.insert(key, value);
    }

    std::cout << "Enter key to search (0 to end): ";
    std::cin >> key;
    if (key != 0) {
        hashTable.search(key);
    }

    std::cout << "Enter key to remove (0 to end): ";
    std::cin >> key;
    if (key != 0) {
        hashTable.remove(key);
    }


	return 0;
}