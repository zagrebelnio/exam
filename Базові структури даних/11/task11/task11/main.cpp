#include "list.h"

/*11)	Створити структуру даних зв’язний список для зберігання числових даних.
У класі реалізувати метод пошуку елементів, сортування, знаходження мінімуму 
і максимуму та виведення у консоль. Користувачем на вхід подаються оцінки
студентів, що можуть бути від 0 до 10, які записуються у список. Створити новий
список, у який додати оцінки студентів, які вище за 4, та відсортувати їх у
зростаючому порядку. Знайти у новому списку максимальну та мінімальну оцінку.
*/

int main() {
	srand(time(0));
	List list;
	for (int i = 0; i < 10; i++) {
		list.push_back(rand() % 11);
	}
	list.show();
	cout << "Size: " << list.get_size() << endl;
	cout << "Min: " << list.min() << endl;
	cout << "Max: " << list.max() << endl;
	int element;
	cout << "Enter the element to find in the list: ";
	cin >> element;
	if (list.find(element)) {
		cout << "The element " << element << " is in the list." << endl;
	}
	else {
		cout << "The element " << element << " is not in the list." << endl;
	}
	list.sort();
	list.show();
}