#include "list.h"

/*11)	�������� ��������� ����� ������� ������ ��� ��������� �������� �����.
� ���� ���������� ����� ������ ��������, ����������, ����������� ������ 
� ��������� �� ��������� � �������. ������������ �� ���� ��������� ������
��������, �� ������ ���� �� 0 �� 10, �� ����������� � ������. �������� �����
������, � ���� ������ ������ ��������, �� ���� �� 4, �� ����������� �� �
����������� �������. ������ � ������ ������ ����������� �� �������� ������.
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