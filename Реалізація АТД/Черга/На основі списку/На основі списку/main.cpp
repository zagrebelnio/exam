#include "queue.h"

int main() {

	int data_type;
	cout << "Choose data type of queue:" << endl;
	cout << "1. int" << endl;
	cout << "2. double" << endl;
	cout << "3. char" << endl;
	cout << "4. string" << endl;

	cin >> data_type;
	cin.ignore();

	switch (data_type) {
	case 1:
		process_queue<int>();
		break;
	case 2:
		process_queue<double>();
		break;
	case 3:
		process_queue<char>();
		break;
	case 4:
		process_queue<string>();
		break;
	}


	return 0;
}